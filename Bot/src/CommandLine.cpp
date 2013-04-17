/**
 * @file CommandLine.cpp
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#include "CommandLine.h"

#include <cstdlib>
#include <cstring>
#include <algorithm>

#include <Logging.h>

namespace bot
{

CommandLine::CommandLine()
{
}

CommandLine::~CommandLine()
{
}

bool CommandLine::GetValue(const std::string& name, std::string& value) const
{
	if(!cmdLineParams.count(name))
		return false;
	value = cmdLineParams.at(name);
	return true;
}

bool CommandLine::ParseCommandLine(int argc, char** argv, const std::vector<std::string>& validParameterNames)
{
	applicationNamePath = argv[0];
	char *pszAppName = strdup(applicationNamePath.c_str());
	applicationName = basename(pszAppName);
	free(pszAppName);

	//first argument is application binary => skip
	for(int i = 1; i < argc; i++) {
		std::string sParam = argv[i];
		//parameter
		if( sParam.find("--") == 0 ) {
			std::string value = (i < argc-1) ? argv[++i] : "";
			std::string trimmedKey = sParam.substr(2,sParam.length()-2);
			if(std::find(validParameterNames.begin(),validParameterNames.end(),trimmedKey) == validParameterNames.end()){
				log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown commandline parameter: %s",trimmedKey.c_str()); }
			else { cmdLineParams[trimmedKey] = value;}
		}
		//flag
		else if ( sParam.find("-") == 0 ) {
			std::string trimmedKey = sParam.substr(1,sParam.length()-1);
			if(std::find(validParameterNames.begin(),validParameterNames.end(),trimmedKey) == validParameterNames.end()){
				log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown commandline parameter: %s",trimmedKey.c_str()); }
			else { cmdLineParams[trimmedKey]  = "1";}
		}
	}

	return true;
}

}
