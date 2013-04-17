/*
 * CommerceSearchParserThread.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <DatabaseLayer.h>
#include <DatabaseUrl.h>

#include "HtmlParserThread.h"
#include "CommerceSearchProduct.h"
#include "CommerceSearchMatchCriteria.h"

namespace htmlparser {
	class Document;
}

namespace parser {

class CommerceSearchParserThread : public HtmlParserThread {
public:
	CommerceSearchParserThread();
	virtual ~CommerceSearchParserThread();

private:
	virtual bool ParsePage(const HtmlParserEntry& entry,htmlparser::Document* parsedDoc);
	virtual void InitParserThread();

private:
	void MatchUrlCriteria(const HtmlParserEntry& entry,const std::vector<htmlparser::DatabaseUrl>& hyperLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);
	void MatchMetaCriteria(const HtmlParserEntry& entry,htmlparser::Document* pDoc,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);
	void MatchImageCriteria(const HtmlParserEntry& entry,const std::vector<htmlparser::DatabaseUrl>& imagesLinks,const std::vector<CommerceSearchMatchCriteria*>& criteriaVector);

private:
	std::vector<CommerceSearchProduct> products;
	database::SelectResultContainer<CommerceSearchMatchCriteria> criterias;

	std::vector<size_t> urlTypePos;
	std::vector<size_t> contentTypePos;
	std::vector<size_t> metaTypePos;
	std::vector<size_t> titleTypePos;
};

}
