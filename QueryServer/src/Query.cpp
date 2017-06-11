/**
 *
 * @file Query.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "Query.h"

#include <StringTools.h>
#include <Logging.h>

namespace queryserver {

Query::Query()
: nextGroupID(0){
}

Query::~Query() {
}

void Query::AppendKeyword(const long long& position,const std::string& keyword,const bool& caseSensitive,const bool& occuranceMandatory,const bool& exactMatch) {

	//assemble raw query string
	if(occuranceMandatory) {
		rawQueryString += "+"; }
	if(keyword.find(' ') != std::string::npos) {
		rawQueryString += "\"" + keyword + "\""; }
	else {
		rawQueryString += keyword; }

	//check if it is a grouped keyword (i.e "bla blub")
	std::vector<std::string> keys;
	tools::StringTools::SplitBy(keyword," ",keys);

	//append keywords
	if(keys.size() == 1) {
		queryKeywords.insert(queryKeywords.end(),QueryKeyword(position,-1,keyword,caseSensitive,occuranceMandatory,exactMatch));
	}
	else if(keys.size() > 1) {
		std::vector<std::string>::const_iterator i(keys.begin());
		for(;i!=keys.end();++i) {
			queryKeywords.insert(queryKeywords.end(),QueryKeyword(position,nextGroupID,*i,caseSensitive,occuranceMandatory,exactMatch));
		}
		nextGroupID++;
	}
	else {
		log::Logging::LogWarn("no keywords detected in query string: %s",keyword.c_str());
	}
}

void Query::DumpQuery(std::string& dump) const {

	std::ostringstream ss;

	//dump query properties
	std::string propDump;
	properties.Dump(propDump);
	ss << propDump;

	//dump query keywords
	std::vector<QueryKeyword>::const_iterator i(queryKeywords.begin());
	for(;i != queryKeywords.end(); ++i) {
		std::string keyDump;
		i->Dump(keyDump);
		ss << keyDump;
	}

	dump = ss.str();
}

void Query::GetQueryKeywords(std::vector<std::string>& keywords) const {

	std::vector<QueryKeyword>::const_iterator i(queryKeywords.begin());
	for(;i != queryKeywords.end(); ++i) {
		keywords.push_back(i->GetKeyword());
	}
}

}
