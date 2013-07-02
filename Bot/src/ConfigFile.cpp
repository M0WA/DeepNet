/**
 * @file ConfigFile.cpp
 * @author Moritz Wagner
 * @date 13.02.2012
 */

#include "ConfigFile.h"

#include <algorithm>

#include "ConfigEntry.h"

#include <StringTools.h>
#include <FileTools.h>
#include <Logging.h>

namespace bot
{

ConfigFile::ConfigFile() {
}

ConfigFile::~ConfigFile() {
}

bool ConfigFile::ParseConfigFile(const std::string& fileName, std::vector<ConfigEntry>& registeredParams)
{
	std::vector<std::string> fileContent;
	if(!tools::FileTools::ReadFile(fileName, fileContent)){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not open config file: %s", fileName.c_str());
		return false; }

	if(fileContent.size()) {
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring empty config file: %s", fileName.c_str());
		return true;}

	tools::StringTools::RemoveComments(fileContent);
	bool success = ParseFile(fileContent,registeredParams);
	if(success)
		this->fileName = fileName;
	return success;
}

bool ConfigFile::ParseFile(std::vector<std::string>& fileContent, std::vector<ConfigEntry>& registeredParams) {

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

		std::vector<ConfigEntry>::iterator iFind = std::find(registeredParams.begin(),registeredParams.end(),key);
		if(iFind == registeredParams.end()) {
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown parameter from config file: %s",key.c_str()); }
		else {
			if(iFind->lockOverride) {
				log::Logging::Log(
						log::Logging::LOGLEVEL_WARN,
						"ignoring value '%s' with '%s' from line %d for key %s because it would override",
						iFind->GetValue().c_str(),value.c_str(),nLine,key.c_str());
			}
			else {
				iFind->SetValue(value);
			}
		}
	}

	return true;
}

}
