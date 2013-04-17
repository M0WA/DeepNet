/*
 * HttpConnection.cpp
 *
 *  Created on: 14.01.2012
 *      Author: Moritz Wagner
 */

#include "HttpConnection.h"

#include <cstring>

#include <CharsetEncoder.h>
#include <MimeType.h>
#include <Logging.h>

#include "HttpUrl.h"

namespace network
{

HttpConnection::HttpConnection()
{
}

HttpConnection::~HttpConnection()
{
}

bool HttpConnection::FetchUrl(const HttpConnectionParam& in, HttpConnectionResult& out )
{
	memset(errorBuffer,0,CURL_ERROR_SIZE);
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &(HttpConnection::WriterCallback));
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out.htmlCode);
	curl_easy_setopt(curl, CURLOPT_URL, in.url.c_str());
	curl_easy_setopt(curl, CURLOPT_USERAGENT, in.userAgent.c_str() );
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, in.secondsTimeoutConnection);
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, in.secondsTimeoutConnect);
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE, (in.allowIPv6 ? CURL_IPRESOLVE_WHATEVER : CURL_IPRESOLVE_V4) );
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1);
	curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50);
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, &errorBuffer);
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

	//TODO: take care about ssl
	curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_NONE);
	//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);

	if(in.uploadLimitKB){
		curl_off_t bytesUploadLimit = in.uploadLimitKB * 1024;
		curl_easy_setopt(curl, CURLOPT_MAX_SEND_SPEED_LARGE, bytesUploadLimit);}
	if(in.downloadLimitKB){
		curl_off_t bytesDownloadLimit = in.downloadLimitKB * 1024;
		curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, bytesDownloadLimit);}

	CURLcode res = curl_easy_perform(curl);
	if(res != CURLE_OK) {
		curl_easy_cleanup(curl);
		out.htmlCode.Release();//not needed but nice;)
		if (log::Logging::IsLogLevelTrace()) log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "libcurl error while fetching url");
		return false; }

	char* redirUrl = 0;
	if( curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &out.httpResponseCode) != CURLE_OK ) out.httpResponseCode=-1;
	if( curl_easy_getinfo(curl, CURLINFO_FILETIME, &out.fileTimestamp)         != CURLE_OK ) out.fileTimestamp=0;
	if( curl_easy_getinfo(curl, CURLINFO_REDIRECT_COUNT, &out.redirectCount)   != CURLE_OK ) out.redirectCount=-1;
	if( out.redirectCount > 0 && curl_easy_getinfo(curl, CURLINFO_REDIRECT_URL, &redirUrl) == CURLE_OK ) out.redirectUrl = redirUrl ? redirUrl : "";
	if( curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &out.downloadSpeed )  != CURLE_OK ) out.downloadSpeed=0.0;
	if( curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &out.uploadSpeed )      != CURLE_OK ) out.uploadSpeed=0.0;
	if( curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &out.totalTime )          != CURLE_OK ) out.totalTime=0.0;
	out.primaryPort=80; //if( curl_easy_getinfo(curl, CURLINFO_PRIMARY_PORT, &out.primaryPort )      != CURLE_OK ) out.primaryPort=80;
	if( curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &out.contentLength ) != CURLE_OK ) out.contentLength=out.htmlCode.GetCount();

	char* primaryIP = 0;
	curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &primaryIP );
	if(primaryIP)
		out.primaryIP = primaryIP;

	char* contentType = 0;
	curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType );
	if(contentType) {
		out.contentType = contentType;}

	bool success = false;
	if(out.htmlCode.GetCount() > 0)	{
		//zero terminate buffer
		char zero = 0;
		out.htmlCode.Append(&zero,1);

		//check content type and convert charset if neccessary
		success = CheckContentType(out.htmlCode.GetBuffer(),out.htmlCode.GetBufferSize(),out);
	}

	//TODO: do we need the cookies?
	//CURLINFO_COOKIELIST(curl_slist_free_all)

	curl_easy_cleanup(curl);
	return success;
}

int HttpConnection::WriterCallback(char *data, size_t size, size_t nmemb, HtmlData* writerData)
{
	if(writerData == NULL)
		return 0;

	if(size<=0 || nmemb<=0 || data == 0)
		return size * nmemb;

	writerData->Append(data, size*nmemb);
	return size * nmemb;
}

bool HttpConnection::CheckContentType(const char* pszBuffer, const int bufLen, HttpConnectionResult& out)
{
	//minimum confidence of 10 is has special meaning
	//for more information:
	//see documentation of ucsdet_getConfidence(const UCharsetMatch *ucsm, UErrorCode *status)
	//http://icu-project.org/apiref/icu4c/ucsdet_8h.html#aa1dd7ce8c727d855697aac1f35df71ed)
	int minConfidence = 10;

	std::string mimeType,mimeEncoding;

	//parse content-type as mime string
	if(!out.contentType.empty() && tools::MimeType::ParseMimeString(out.contentType,mimeType,mimeEncoding))	{
		//document has valid mime type string
	}
	else {
		//guess mime type and encoding
		tools::MimeType mime;
		mimeType     = mime.GetMimeType(pszBuffer,bufLen);
		mimeEncoding = mime.GetMimeEncoding(pszBuffer,bufLen);
	}

	if(mimeType.empty()) {
		if (log::Logging::IsLogLevelTrace()) log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "could not detect a valid mime type");
		return false; }

	if(mimeType.compare("text/html") == 0) {
		//is a html-document
	}
	else if(mimeType.compare("text/plain") == 0){
		//is a plain-text document
	}
	//TODO: what to do with other mime types
	/*
	else if(mimeType.compare("text/xml") == 0) { }
	else if(mimeType.compare("application/pdf") == 0) {	}
	*/
	else {
		if (log::Logging::IsLogLevelTrace()) log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "invalid mime type");
		return false; }

	//checking encoding specified in mime type string
	if( mimeEncoding.empty() || !tools::CharsetEncoder::IsValidEncodingName(mimeEncoding) )	{
		//no or invalid encoding found in mime type string
		out.charsetHint = "";
	} else {
		out.charsetHint = mimeEncoding;
	}
	out.validHint = false;

	//detect charset encoding
	std::string charsetName;
	if(!out.htmlCode.DetectCharset( out.charsetHint,out.encodingConfidence,out.encodingName,out.validHint)) {
		return false;
	}

	//convert to host charset encoding if a valid encoding was found
	if( out.validHint || out.encodingConfidence >= minConfidence  ) {
		return out.htmlCode.ConvertToHostCharset(out.encodingName);
	}
	// wrong encoding specified or broken encoding in document
	else {
		if (log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "wrong encoding specified or broken encoding in document");

		return false;
	}
}

bool HttpConnection::Get(const network::HttpUrl& url, std::string& html) {
	return HttpConnection::Get(url.GetFullUrl(),html);
}

bool HttpConnection::Get(const std::string& url, std::string& html) {

	HttpConnectionParam in;
	in.url = url;
	in.allowIPv6 = false;
	in.secondsTimeoutConnect = 3;
	in.secondsTimeoutConnection = 8;
	in.downloadLimitKB = 300;
	in.uploadLimitKB = 100;
	in.userAgent = "siridia search engine v1.0";

	HttpConnection connection;
	HttpConnectionResult out;
	if(!connection.FetchUrl(in,out))
		return false;

	if(out.htmlCode.GetCount()) {
		html = out.htmlCode.GetBuffer();}
	return (out.htmlCode.GetBufferSize()>0);
}

}
