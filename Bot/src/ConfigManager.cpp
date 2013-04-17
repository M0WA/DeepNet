/**
 * @file ConfigManager.cpp
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#include "ConfigManager.h"

#include <iostream>
#include <ContainerTools.h>

namespace bot
{

ConfigManager::ConfigManager() {
}

ConfigManager::~ConfigManager() {
}

void ConfigManager::PrintUsage(void) const {

	std::cout << std::endl << std::endl;
	std::cout << "/=========================================================\\" << std::endl;
	std::cout << "| This software is part of the SIRIDIA search engine      |" << std::endl;
	std::cout << "| Copyright 2012, SIRIDIA GmbH                            |" << std::endl;
	std::cout << "| Author: Moritz Wagner (moritz.wagner@siridia.de)        |" << std::endl;
	std::cout << "\\=========================================================/" << std::endl;
	std::cout << std::endl << "usage: ./" << cmdLine.GetApplicationName() << " [parameters]" << std::endl;

	if(defaultConfig.size()) {

		std::cout << "parameters:" << std::endl << "(mandatory parameters are marked with a \"*\")" << std::endl << std::endl;
		std::vector<ConfigEntry>::const_iterator iterParams = defaultConfig.begin();
		for(;iterParams != defaultConfig.end(); ++iterParams) {

			// name: description
			std::ostringstream ssInitial;
			ssInitial << ( !iterParams->value.empty() ? "" : (" default: " + iterParams->value) );
			std::ostringstream ssMandatory;
			ssMandatory << (iterParams->mandatory ? " (*)" : "");
			std::cout << "\t" << (iterParams->isFlag ? "-" : "--") << iterParams->name  << (iterParams->isFlag ? "" : " <value>") << ": " << iterParams->desc << ssInitial.str() << ssMandatory.str() << std::endl;
		}
	}
	std::cout << std::endl;
}

bool ConfigManager::Init(const int argc, char** argv) {

	if(!InitCommandLine(argc,argv))
		return false;

	if(cmdLine.GetValue("configfile",configFileName) && !configFileName.empty() )
		InitConfigFile();

	return Process();
}

bool ConfigManager::InitConfigFile() {

	return configFile.SetFileName(configFileName,validParameterNames);
}

bool ConfigManager::InitAndProcessConfigFile(const std::string& configFileName) {

	this->configFileName = configFileName;
	if(!configFile.SetFileName(configFileName,validParameterNames))
		return false;
	return Process();
}

bool ConfigManager::InitCommandLine(const int argc, char** argv) {

	return cmdLine.ParseCommandLine(argc,argv,validParameterNames);
}

void ConfigManager::RegisterParam(const std::string& paramName, const std::string& description, const bool isMandatory, const bool isFlag, const std::string* defaultValue ) {

	defaultConfig.push_back(ConfigEntry(paramName, description, isMandatory, isFlag, defaultValue));
	validParameterNames.push_back(paramName);
}

bool ConfigManager::Process() {

	std::vector<ConfigEntry>::iterator iterDefault = defaultConfig.begin();
	for(; iterDefault != defaultConfig.end(); ++iterDefault) {

		std::string sValue;
		bool bAvailable = GetValueDirect(iterDefault->name,sValue);
		if(	!bAvailable ) {

			//check if missing mandatory parameters has a default value
			if( iterDefault->mandatory && iterDefault->value.empty() ){

				std::string confFileContent;
				tools::ContainerTools::DumpMap(configValues,confFileContent);
				std::cout << std::endl << "missing mandatory parameter/config entry: " << iterDefault->name;
				std::cout << std::endl << "config file contents:" << std::endl << confFileContent << std::endl;
				PrintUsage();
				return false;
			}

			//fill missing parameters with default
			if(!iterDefault->value.empty()) {
				configValues[iterDefault->name] = iterDefault->value; }
		}
		else {
			configValues[iterDefault->name] = sValue;
		}
	}
	return true;
}

}
