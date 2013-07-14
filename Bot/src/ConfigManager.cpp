/**
 * @file ConfigManager.cpp
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#include "ConfigManager.h"

#include <iostream>

#include <ContainerTools.h>
#include <Logging.h>

namespace bot
{

ConfigManager::ConfigManager() {
}

ConfigManager::~ConfigManager() {
}

bool ConfigManager::Init(const int argc, char** argv) {

	if( !ProcessCmdLine(argc, argv) ||
		!ProcessConfigFile() ||
		!ValidateConfig() )
	{
		std::string dump;
		DumpConfig(dump);
		log::Logging::LogError("config:\n" + dump);
		PrintUsage();
		return false;
	}

	return true;
}

void ConfigManager::PrintUsage(void) const {

	std::string compileTimeFlags("compile time flags (if any): ");
#ifdef ENABLE_PERFORMANCE_LOG
	compileTimeFlags += "ENABLE_PERFORMANCE_LOG ";
#endif

	std::cout << std::endl << std::endl;
	std::cout << "/=========================================================\\" << std::endl;
	std::cout << "| This software is part of the DeepNet search engine      |" << std::endl;
	std::cout << "| Copyright 2012-2013, Moritz Wagner                      |" << std::endl;
	std::cout << "| Author: Moritz Wagner (moritz.wagner@mo-sys.de)         |" << std::endl;
	std::cout << "\\=========================================================/" << std::endl;
	std::cout << compileTimeFlags << std::endl << std::endl;
	std::cout << std::endl << "usage: ./" << cmdLine.GetApplicationName() << " [parameters]" << std::endl;

	if(registeredParams.size()) {

		std::cout << "parameters:" << std::endl << "(mandatory parameters are marked with a \"*\")" << std::endl << std::endl;
		std::vector<ConfigEntry>::const_iterator iterParams = registeredParams.begin();
		for(;iterParams != registeredParams.end(); ++iterParams) {

			std::map<std::string, std::string>::const_iterator iFind =
					defaultValues.find(iterParams->name);

			// name: description
			std::ostringstream ssInitial;
			ssInitial << ( iFind == defaultValues.end() ? "" : (" (default: " + iFind->second) + ")" );
			std::ostringstream ssMandatory;
			ssMandatory << (iterParams->mandatory ? " (*)" : "");
			std::cout << "\t" << (iterParams->isFlag ? "-" : "--") << iterParams->name  << (iterParams->isFlag ? "" : " <value>") << ": " << iterParams->desc << ssInitial.str() << ssMandatory.str() << std::endl;
		}
	}
	std::cout << std::endl;
}

void ConfigManager::DumpConfig(std::string& dump) const {
	std::ostringstream ssOut;
	std::vector<ConfigEntry>::const_iterator i = registeredParams.begin();
	for(;i != registeredParams.end(); ++i) {
		if(i->valueSet) {
			ssOut <<
				( i->isFlag ? "flag " : "param" ) << ": " << i->name << " => " << i->GetValue() << std::endl;
		}
	}
	dump = ssOut.str();
}

void ConfigManager::RegisterParam(const std::string& paramName, const std::string& description, const bool isMandatory, const std::string* defaultValue) {
	if(defaultValue) {
		defaultValues[paramName] = *defaultValue;}
	registeredParams.push_back(ConfigEntry(paramName, description, isMandatory, false, defaultValue));
}

void ConfigManager::RegisterFlag(const std::string& paramName,const std::string& description,const bool defaultValue) {
	std::string tmpDefault(( defaultValue ) ? "1" : "0");
	defaultValues[paramName] = tmpDefault;
	registeredParams.push_back(ConfigEntry(paramName, description, true, true, &tmpDefault ));
}

bool ConfigManager::ProcessCmdLine(const int argc, char** argv) {
	bool success = cmdLine.ParseCommandLine(argc,argv,registeredParams);
	if(!GetValue("configfile",configFileName))
		configFileName.clear();
	return success;
}

bool ConfigManager::ProcessConfigFile(){
	if(configFileName.empty())
		return true;
	if(!configFile.ParseConfigFile(configFileName,registeredParams)) {
		return false;}
	return true;
}

bool ConfigManager::ValidateConfig() const {
	bool success = true;
	std::vector<ConfigEntry>::const_iterator i = registeredParams.begin();
	for(;i != registeredParams.end();++i) {
		if(i->mandatory && !i->valueSet) {
			std::string prefixName(i->isFlag ? "-" : "--");
			log::Logging::LogError(
				"missing mandatory config parameter, please check config: %s%s",
				prefixName.c_str(),i->name.c_str() );
			success = false;
		}
	}

	return success;
}

bool ConfigManager::GetValue(const std::string& key, std::string& value) const {
	std::vector<ConfigEntry>::const_iterator iFind =
			std::find(registeredParams.begin(),registeredParams.end(),key);

	if(iFind == registeredParams.end()) {
		return false; }
	if(!iFind->valueSet) {
		return false; }

	value = iFind->GetValue();
	return true;
}

const std::string& ConfigManager::GetApplicationName() const {
	return cmdLine.GetApplicationName();
}

}
