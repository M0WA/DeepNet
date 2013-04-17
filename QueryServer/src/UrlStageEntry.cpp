/*
 * UrlStageEntry.cpp
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#include "UrlStageEntry.h"

namespace queryserver {

Relevance UrlStageEntry::GetTotalRelevance() const
{
	Relevance rele(0.0,1.0);
	const std::vector<KeywordEntry>& keywords = Keywords();
	std::vector<KeywordEntry>::const_iterator iterMatchedKeywords = keywords.begin();
	for(;iterMatchedKeywords != keywords.end();++iterMatchedKeywords) {
		rele = rele + (const Relevance&)*iterMatchedKeywords; }
	return rele;
}

}
