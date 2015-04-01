/*
 * SuggestServerResponse.cpp
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#include <string>
#include <vector>
#include <sstream>

#include "SuggestServerResponse.h"
#include <SpellChecking.h>
#include <FastCGIServerThread.h>

namespace suggestserver {

SuggestServerResponse::SuggestServerResponse(database::DatabaseHelper& dbHelper,SuggestServerRequest* request)
: fastcgiserver::FastCGIResponse(request)
, suggestRequest(request)
, dbHelper(dbHelper)
{
}

SuggestServerResponse::~SuggestServerResponse()
{
}

bool SuggestServerResponse::Process(FCGX_Request& request)
{
	const std::list<std::string>& queryParts = suggestRequest->QueryParts();
	if(queryParts.size() == 0)
		return false;

	std::stringstream ssContent;

	ssContent << "<response><result id=\"1\">";
	std::list<std::string>::const_iterator iterQueryParts = queryParts.begin();
	for(int i = 1;iterQueryParts != queryParts.end(); i++,++iterQueryParts) {
		bool spellCorrect = true;
		std::vector<std::string> vecProposals;
		suggestRequest->ServerThread()->SpellChecker().GenerateProposals(*iterQueryParts,spellCorrect,vecProposals);
		ssContent <<
			"<keyword id=\""<< i << "\">"
			"<word>" << *iterQueryParts << "</word>"
			"<spell>" << spellCorrect << "</spell>";
		if(vecProposals.size() != 0) {
			std::vector<std::string>::const_iterator iterProposals = vecProposals.begin();
			ssContent << "<proposals>";
			for(;iterProposals != vecProposals.end();++iterProposals) {
				ssContent << "<proposal>" << *iterProposals << "</proposal>";
			}
			ssContent << "</proposals>";
		}
		ssContent << "</keyword>";
	}
	ssContent << "</result></response>";

	content = ssContent.str();

	return fastcgiserver::FastCGIResponse::Process(request);
}

}
