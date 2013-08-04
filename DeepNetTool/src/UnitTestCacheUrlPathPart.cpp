/**
 *
 * @file UnitTestCacheUrlPathPart.cpp
 * @author Moritz Wagner
 * @date 04.08.2013
 *
 */

#include "UnitTestCacheUrlPathPart.h"

#include <string>
#include <vector>

#include <FileTools.h>
#include <CacheUrlPathPart.h>

namespace toolbot {

UnitTestCacheUrlPathPart::UnitTestCacheUrlPathPart(database::DatabaseConnection* connection,const std::string& urlPathPartValidateFile)
: connection(connection)
, urlPathPartValidateFile(urlPathPartValidateFile){
}

UnitTestCacheUrlPathPart::~UnitTestCacheUrlPathPart() {
}

bool UnitTestCacheUrlPathPart::Run() {
	std::vector<std::string> lines;
	tools::FileTools::ReadFile(urlPathPartValidateFile,lines);

	std::vector<std::string>::const_iterator i(lines.begin());
	for(;i != lines.end();++i) {

		long long urlPathPartID(caching::CacheUrlPathPart::GetIDByUrlPathPart(connection,*i));
		if(urlPathPartID == -1) {
			log::Logging::LogError("could not insert url path part %s",i->c_str());
			return false; }

		std::string urlPathPart(caching::CacheUrlPathPart::GetUrlPathPartByID(connection,urlPathPartID));
		if(i->compare(urlPathPart) != 0) {
			log::Logging::LogError("url path part changed: %s -> %s",i->c_str(),urlPathPart.c_str());
			return false; }
	}

	return true;
}

}
