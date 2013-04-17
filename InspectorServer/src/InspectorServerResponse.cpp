/*
 * InspectorServerResponse.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServerResponse.h"

#include <sstream>

#include <Logging.h>
#include <HtmlTester.h>
#include <HttpUrlParser.h>
#include <GenericWebContentIndexer.h>
#include <HttpConnection.h>
#include <DatabaseLayer.h>
#include <FastCGIRequest.h>
#include <FastCGIServerThread.h>
#include <StringTools.h>
#include <ContainerTools.h>
#include <CacheDatabaseUrl.h>
#include <HtmlElementType.h>

#include <Exception.h>

#include "InspectorServerRequest.h"

namespace inspectorserver {

InspectorServerResponse::InspectorServerResponse(database::DatabaseHelper& dbHelper,InspectorServerRequest* request)
: fastcgiserver::FastCGIResponse(request)
, inspectorRequest(request)
, dbHelper(dbHelper)
{
}

InspectorServerResponse::~InspectorServerResponse()
{
}

bool InspectorServerResponse::Process(FCGX_Request& request)
{
	const std::list<std::string>& htmlcodes = inspectorRequest->HtmlCodes();
	if(htmlcodes.size() > 0)
	{
		std::stringstream responseXML;
		std::list<std::string>::const_iterator iterCode = htmlcodes.begin();
		for(;iterCode != htmlcodes.end();++iterCode){

			bool bIsUrl = false;
			network::HttpUrl urlIn;
			std::string fullURL = "";
			std::string htmlCode = *iterCode;


			try {
				network::HttpUrlParser::DecodeUrl(htmlCode);
			}
			catch(errors::Exception& e) {
				log::Logging::Log(log::Logging::LOGLEVEL_WARN,"error while url-decoding:\n" + htmlCode);
				continue;
			}

			//check if its a url
			size_t posHttp = htmlCode.find_first_of("http://",0);
			if( posHttp == 0) {

				try {
					network::HttpUrlParser::ParseURL(htmlCode,urlIn);
				}
				catch(errors::Exception& e) {
					log::Logging::Log(log::Logging::LOGLEVEL_WARN,"error while url-parsing:\n" + htmlCode);
					continue; }

				fullURL = urlIn.GetFullUrl();
				bIsUrl = true;

				network::HttpConnection::HttpConnectionParam inParam;
				inParam.url       = fullURL;
				inParam.userAgent = "siridia.de crawler v1.0";
				inParam.secondsTimeoutConnect    = 3;
				inParam.secondsTimeoutConnection = 3;
				inParam.allowIPv6       = false;
				inParam.uploadLimitKB   = 300;
				inParam.downloadLimitKB = 300;

				network::HttpConnection::HttpConnectionResult outParam;
				network::HttpConnection server;
				if( !server.FetchUrl(inParam,outParam) ) {
					htmlCode = "";
				}

				if(outParam.httpResponseCode != -1) {
					htmlCode = outParam.htmlCode.GetBuffer();
				}
			}

			htmlparser::HtmlTesterResult result;
			if(!htmlparser::HtmlTester::ParseHtml(DB().Connection(),fullURL,htmlCode,result))	{
				//TODO: error while parsing(may be a non fatal error)
			}

			std::vector<long long> backLinkUrlIDs;
			if(bIsUrl) {
				responseXML << result.ToXML(DB().Connection());

				//TODO: search for backlinks
				/*
				if(urlIn.GetUrlID() > 0) {

					std::map<long long,htmlparser::DatabaseUrl> mapIDUrls;
					htmlparser::DatabaseUrl::GetBackLinks(DB().Connection(), urlIn.GetUrlID(), mapIDUrls);

					std::vector<long long> backlinkIDs;
					tools::ContainerTools::Map1ToVector(mapIDUrls,backlinkIDs);
					responseXML << "<backlinks>";

					std::map<long long,htmlparser::DatabaseUrl> mapBacklinks;
					caching::CacheDatabaseUrl::GetByUrlID(DB().Connection(),backlinkIDs,mapBacklinks);
					std::map<long long,htmlparser::DatabaseUrl>::iterator iterMapBackLinks = mapBacklinks.begin();
					for(int i=1; iterMapBackLinks != mapBacklinks.end(); i++,++iterMapBackLinks){
						responseXML <<
						"<url id=\"" << i << "\">"
						"<fullurl>" <<
							iterMapBackLinks->second.GetFullUrl() <<
						"</fullurl>"
						"</url>" << std::endl;
					}
					responseXML << "</backlinks>";
				}
				*/
			}
			else
				responseXML << result.ToXML(DB().Connection());

			indexing::ContentIndexer* indexerContent = new indexing::GenericWebContentIndexer(NULL, indexing::IndexerBase::BODY_CONTENT);
			indexerContent->GetDictionary().SetTestMode(true);
			std::vector< htmlparser::HtmlTextElement >::iterator iterContent = result.contentElements.begin();
			for(long long iParagraph = 0;iterContent != result.contentElements.end();++iParagraph,++iterContent) {
				indexerContent->Parse(iterContent->textContent,iParagraph); }

			indexing::ContentIndexer* indexerMeta = new indexing::GenericWebContentIndexer(NULL, indexing::IndexerBase::BODY_CONTENT);
			indexerMeta->GetDictionary().SetTestMode(true);
			std::vector< htmlparser::HtmlMetaElement >::iterator iterMeta = result.metaElements.begin();
			for(;iterMeta != result.metaElements.end();++iterMeta) {
				indexerMeta->Parse(iterMeta->textContent,-1); }

			std::string dictionaryContent,dictionaryMeta;
			indexerContent->GetDictionary().DumpXML(dictionaryContent,inspectorRequest->ServerThread()->SpellChecker());
			indexerMeta   ->GetDictionary().DumpXML(dictionaryMeta,inspectorRequest->ServerThread()->SpellChecker());
			responseXML << "<websiteDictionary>" << dictionaryContent << "</websiteDictionary>" << std::endl;
			responseXML << "<metaDictionary>"    << dictionaryMeta    << "</metaDictionary>"    << std::endl;

			delete indexerContent;
			delete indexerMeta;
		}

		content = "<response id=\"1\"><result id=\"1\">" + responseXML.str() + "</result></response>";
	}
	else
	{
		content = "";
	}

	return fastcgiserver::FastCGIResponse::Process(request);
}

}
