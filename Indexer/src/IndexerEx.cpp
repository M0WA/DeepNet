/**
 *
 * @file IndexerEx.cpp
 * @author Moritz Wagner
 * @date Jun 13, 2013
 *
 */

#include "IndexerEx.h"

#include <PCRERegex.h>
#include <CharsetEncoder.h>
#include <StringTools.h>

namespace indexing {

IndexerEx::IndexerEx(database::DatabaseConnection* database)
: db(database)
, dictionary(database){
}

IndexerEx::~IndexerEx() {
}

void IndexerEx::Parse(const std::string& input, const long long paragraph)
{
	bool isUTF8 = (tools::StringTools::ToLowerNP(tools::CharsetEncoder::GetHostCharsetName()).find_first_of("utf-8") != std::string::npos);

	std::vector<std::string> groups;
	tools::PCRERegex regex("(\\w+)",true,false,isUTF8);
	if(!regex.Match(input,groups))
		return;

	std::vector<std::string>::const_iterator i = groups.begin();
	for(; i != groups.end();++i) {
		dictionary.Add(*i);	}
}

}
