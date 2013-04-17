/*
 * CommerceSearchParserThread.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <DatabaseLayer.h>

#include "GenericWebHtmlParserThread.h"
#include "CommerceSearchProduct.h"
#include "CommerceSearchMatchCriteria.h"


namespace network {
	class HttpUrl;
}

namespace htmlparser {
	class Document;
	class DatabaseUrl;
}

namespace parser {

class CommerceSearchParserThread : public GenericWebHtmlParserThread {
public:
	CommerceSearchParserThread();
	virtual ~CommerceSearchParserThread();

private:
	//virtual bool ParsePage(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document);
	virtual void InitParserThread();
	virtual void OnAfterParsePage(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document,const std::vector<std::string> &content,const std::vector<htmlparser::DatabaseUrl>& hyperlinks,const std::vector<network::HttpUrl>& images);

private:
	void MatchUrlCriteria(const HtmlParserEntry& entry,const std::vector<htmlparser::DatabaseUrl>& hyperLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);
	void MatchMetaCriteria(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);
	void MatchImageCriteria(const HtmlParserEntry& entry,const std::vector<network::HttpUrl>& imagesLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);

private:
	std::vector<CommerceSearchProduct> products;
	database::SelectResultContainer<CommerceSearchMatchCriteria> criterias;

	std::vector<size_t> urlTypePos;
	std::vector<size_t> contentTypePos;
	std::vector<size_t> metaTypePos;
	std::vector<size_t> titleTypePos;
};

}
