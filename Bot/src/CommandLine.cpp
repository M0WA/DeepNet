/**
 * @file CommandLine.cpp
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#include "CommandLine.h"

#include <cstdlib>
#include <cstring>
#include <algorithm>

#include "ConfigEntry.h"

#include <Logging.h>

namespace bot
{

CommandLine::CommandLine()
{
}

CommandLine::~CommandLine()
{
}

bool CommandLine::ParseCommandLine(int argc, char** argv, std::vector<ConfigEntry>& registeredParams)
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
			std::vector<ConfigEntry>::iterator iFind =
					std::find(registeredParams.begin(),registeredParams.end(),trimmedKey);
			if(iFind == registeredParams.end()){
				log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown commandline parameter: %s",trimmedKey.c_str()); }
			else {
				if(iFind->isFlag) {
					log::Logging::Log(log::Logging::LOGLEVEL_WARN,"commandline parameter registered as flag is used as a parameter: %s",trimmedKey.c_str());
					iFind->SetValue("1");}
				else {
					iFind->SetValue(value);}
				iFind->lockOverride = true;
			}
		}
		//flag
		else if ( sParam.find("-") == 0 ) {
			std::string trimmedKey = sParam.substr(1,sParam.length()-1);
			std::vector<ConfigEntry>::iterator iFind =
					std::find(registeredParams.begin(),registeredParams.end(),trimmedKey);
			if(iFind == registeredParams.end()){
				log::Logging::Log(log::Logging::LOGLEVEL_WARN,"ignoring unknown commandline parameter: %s",trimmedKey.c_str()); }
			else {
				if(!iFind->isFlag) {
					log::Logging::Log(log::Logging::LOGLEVEL_WARN,"commandline parameter registered as parameter is used as a flag, ignoring: %s",trimmedKey.c_str());
				}
				else {
					iFind->SetValue("1");}
				iFind->lockOverride = true;
			}
		}
	}

	return true;
}

}
