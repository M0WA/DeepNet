/**
 *
 * @file IndexerEx.cpp
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#include "IndexerEx.h"

#include <PCRERegex.h>
#include <CharsetEncoder.h>
#include <StringTools.h>
#include <PerformanceCounter.h>
#include <Logging.h>

namespace indexing {

IndexerEx::IndexerEx(database::DatabaseConnection* database)
: db(database)
, dictionary(database){
}

IndexerEx::~IndexerEx() {
}

void IndexerEx::Parse(const std::string& input, const long long paragraph)
{
	if(input.size() < 2)
		return;

	bool isUTF8 = (tools::StringTools::ToLowerNP(tools::CharsetEncoder::GetHostCharsetName()).find_first_of("utf-8") != std::string::npos);

	PERFORMANCE_LOG_START;
	std::vector<std::string> groups;
	tools::PCRERegex regex("(\\w{2,})",true,false,isUTF8);
	if(!regex.Match(input,groups)) {
		if(log::Logging::IsLogLevelTrace()) {
			log::Logging::LogTrace("did not detect any words in content");	}
		return;
	}
	PERFORMANCE_LOG_STOP("splitting content group to words");

	PERFORMANCE_LOG_RESTART;
	std::vector<std::string>::const_iterator i = groups.begin();
	for(; i != groups.end();++i) {
		dictionary.Add(*i);	}
	PERFORMANCE_LOG_STOP("adding words to dictionary");

	/*
	PERFORMANCE_LOG_RESTART;
	dictionary.CommitContent();
	dictionary.CommitMeta();
	PERFORMANCE_LOG_STOP("commited dictionary");
	*/
}

}
