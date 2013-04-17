/**
 * @file ConfigFile.cpp
 * @author Moritz Wagner
 * @date 13.02.2012
 */

#include "ConfigFile.h"

#include <algorithm>

#include <StringTools.h>
#include <FileTools.h>
#include <Logging.h>

namespace bot
{

ConfigFile::ConfigFile() {
}

ConfigFile::~ConfigFile() {
}

bool ConfigFile::SetFileName(const std::string& fileName, const std::vector<std::string>& validParameterNames)
{
	std::vector<std::string> fileContent;
	if(!tools::FileTools::ReadFile(fileName, fileContent))
		return false;
	tools::StringTools::RemoveComments(fileContent);
	bool success = ParseFile(fileContent,validParameterNames);
	if(success)
		this->fileName = fileName;
	return success;
}

bool ConfigFile::ParseFile(std::vector<std::string>& fileContent, const std::vector<std::string>& validParameterNames) {

	std::vector<std::string>::iterator iterLines = fileContent.begin();
	for(int nLine = 1; iterLines != fileContent.end(); iterLines++,nLine++)
	{
		size_t equalSign = std::string::npos;
		if( (equalSign = iterLines->find('=')) == std::string::npos ){
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error in line %d, '=' is missing: %s", nLine, iterLines->c_str());
			continue;}

		std::string key, value;
		key = iterLines->substr(0,equalSign);
		//trim(key);
		if(key.empty()){
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error in line %d, key is empty or invalid: %s", nLine, iterLines->c_str());
			continue;}

		size_t posValue = equalSign+1;
		value = iterLines->substr(posValue,iterLines->length() - posValue);
		if(value.empty()){
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error in line %d, empty value specified for key: %s", nLine, key.c_str());}

		if(mapKeyValues.count(key)){
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"overriding value '%s' with '%s' from line %d for key %s",mapKeyValues[key].c_str(),value.c_str(),nLine,key.c_str());}

		if(std::find(validParameterNames.begin(),validParameterNames.end(),key) == validParameterNames.end()){
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown commandline parameter: %s",key.c_str()); }
		else {
			mapKeyValues.insert(std::pair<std::string,std::string>(key,value)); }
	}

	return (bool)mapKeyValues.size();
}

bool ConfigFile::GetValue(const std::string& key, std::string& out) const
{
	if(mapKeyValues.count(key)){
		out = mapKeyValues.at(key);
		return true;}
	return false;
}

}
