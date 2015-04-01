/*
 * CommerceSearchParserThread.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchParserThread.h"

#include <HttpUrl.h>
#include <DatabaseUrl.h>
#include <HtmlParserFactory.h>
#include <IHtmlParser.h>

#include <NotImplementedException.h>

namespace parser {

CommerceSearchParserThread::CommerceSearchParserThread()
: GenericWebHtmlParserThread() {
}

CommerceSearchParserThread::~CommerceSearchParserThread() {
}

void CommerceSearchParserThread::InitParserThread() {

	CommerceSearchMatchCriteria::GetAll(DB().Connection(),criterias);

	criterias.ResetIter();
	for(size_t i = 0;!criterias.IsIterEnd();i++,criterias.Next()) {
		switch(criterias.GetIter()->GetCriteriaType()){
		case URL_CRITERIA_TYPE:
			urlTypePos.push_back(i);
			break;
		case META_CRITERIA_TYPE:
			metaTypePos.push_back(i);
			break;
		case CONTENT_CRITERIA_TYPE:
			contentTypePos.push_back(i);
			break;
		case TITLE_CRITERIA_TYPE:
			titleTypePos.push_back(i);
			break;
		default:
			THROW_EXCEPTION(errors::NotImplementedException,"invalid criteria type specified");
			break;
		}
	}
}

void CommerceSearchParserThread::OnAfterParsePage(const HtmlParserEntry& entry,tools::Pointer<htmlparser::IHtmlParserResult>& result,const std::vector<std::string> &content,const std::vector<htmlparser::DatabaseUrl>& hyperlinks,const std::vector<network::HttpUrl>& images)
{
	const std::vector<CommerceSearchMatchCriteria*>& criteriaVector = criterias.GetVector();

	//take care about url specific criteria
	MatchUrlCriteria(entry,hyperlinks,criteriaVector);

	//take care about meta info specific criteria
	MatchMetaCriteria(entry,result,criteriaVector);

	//take care about image specific criteria
	MatchImageCriteria(entry,images,criteriaVector);
}
/*
bool CommerceSearchParserThread::ParsePage(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document) {

	const std::vector<network::HttpUrl>  &hyperLinks = document.HyperLinks(),
			&imagesLinks = document.Images(),
			videosLinks; //TODO: video links
	const std::vector< std::pair<std::string,std::string> >& meta = document.Meta();
	const std::vector<std::string> &content = document.Content();

	std::vector<std::string> title, description;
	std::vector< std::pair<std::string,std::string> >::const_iterator iterTmp = meta.begin();
	for(;iterTmp != meta.end();++iterTmp) {
		if(iterTmp->first.compare("title") == 0) {
			title.push_back(iterTmp->second); }
		else if(iterTmp->first.compare("description") == 0) {
			description.push_back(iterTmp->second); }
	}
	const std::vector<CommerceSearchMatchCriteria*>& criteriaVector = criterias.GetVector();

	//take care about url specific criteria
	MatchUrlCriteria(entry,hyperLinks,criteriaVector);

	//take care about meta info specific criteria
	MatchMetaCriteria(entry,document,criteriaVector);

	//take care about image specific criteria
	MatchImageCriteria(entry,imagesLinks,criteriaVector);
	return true;
}
*/

void CommerceSearchParserThread::MatchUrlCriteria(const HtmlParserEntry& entry,const std::vector<htmlparser::DatabaseUrl>& hyperLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector) {

	std::vector<size_t>::const_iterator iterUrl = urlTypePos.begin();
	for(;iterUrl != urlTypePos.end();++iterUrl) {
		const CommerceSearchMatchCriteria* const urlCrit = criteriaVector.at(*iterUrl);

		//current document url
		urlCrit->Match(DB().Connection(),entry.url.GetFullUrl());

		std::vector<htmlparser::DatabaseUrl>::const_iterator iterParsedUrls = hyperLinks.begin();
		for(;iterParsedUrls != hyperLinks.end();++iterParsedUrls) {
			urlCrit->Match(DB().Connection(),iterParsedUrls->GetFullUrl());
		}
	}
}

void CommerceSearchParserThread::MatchMetaCriteria(const HtmlParserEntry& entry,tools::Pointer<htmlparser::IHtmlParserResult>& result,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector) {

	std::vector<std::string> titles,descriptions;

	//
	//TODO:
	//

	//pDoc->GetMeta(htmlparser::TITLE_META,titles);
	//pDoc->GetMeta(htmlparser::DESCRIPTION_META,descriptions);

	std::vector<size_t>::const_iterator iterMeta = metaTypePos.begin();
	for(;iterMeta != metaTypePos.end();++iterMeta) {

		const CommerceSearchMatchCriteria* const metaCrit = criteriaVector.at(*iterMeta);

		std::vector<std::string>::const_iterator iterMetaContent = titles.begin();
		for(;iterMetaContent != titles.end();++iterMetaContent) {
			metaCrit->Match(DB().Connection(),*iterMetaContent);
		}

		iterMetaContent = descriptions.begin();
		for(;iterMetaContent != descriptions.end();++iterMetaContent) {
			metaCrit->Match(DB().Connection(),*iterMetaContent);
		}
	}
}

void CommerceSearchParserThread::MatchImageCriteria(const HtmlParserEntry& entry,const std::vector<network::HttpUrl>& imagesLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector) {

	//TODO: match imagelinks for product...
}

}
