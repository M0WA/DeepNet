/**
 * @file ConfigManager.h
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "CommandLine.h"
#include "ConfigFile.h"
#include "ConfigEntry.h"

namespace bot
{

/**
 * @brief class for managing configuration file and commandline parameters.
 * processes and manages configuration accuired by configfile and commandline.
 */
class ConfigManager {

public:
	ConfigManager();
	virtual ~ConfigManager();

	/**
	 * parses command line and if given also the config file.
	 * command line args overrule config file parameters.
	 * call this function only after ALL parameters have been
	 * registered with bot::ConfigManager::RegisterFlag or
	 * bot::ConfigManager::RegisterParam
	 * @param argc number of commandline arguments.
	 * @param argv array of commandline arguments.
	 * @return false on error, true on success.
	 */
	bool Init(const int argc, char** argv);

	/**
	 * registers a new flag.
	 * this function can only be called before bot::ConfigManager::Init is called.
	 * @param flagName name of the flag.
	 * @param description description of the flag.
	 * @param defaultValue default value of flag
	 */
	void RegisterFlag(const std::string& flagName,
			const std::string& description,
			const bool defaultValue);

	/**
	 * registers a new parameter.
	 * this function can only be called before bot::ConfigManager::Init is called.
	 * @param paramName name of the parameter.
	 * @param description description of the parameter.
	 * @param isMandatory is a mandatory parameter.
	 * @param defaultValue default value of parameter or NULL if no default value.
	 */
	void RegisterParam(const std::string& paramName,
			const std::string& description,
			const bool isMandatory,
			const std::string* defaultValue);

	/**
	 * gets filename of this binary.
	 * @return filename of this binary.
	 */
	const std::string& GetApplicationName() const;

	/**
	 * prints to usage to stdout.
	 */
	void PrintUsage(void) const;

	/**
	 * gets parameters by their name as a string.
	 * @param key name of the parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	bool GetValue(const std::string& key, std::string& value) const;

	/**
	 * gets parameters by their name and converts
	 * it to the given type T.
	 * @param key name of the parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	template <class T>
	bool GetValue(const std::string& key, T& value) const {
		std::string tmp;
		if(!GetValue(key,tmp))
			return false;
		std::stringstream in;
		in << std::skipws;
		in << tmp;
		in >> value;
		return true;
	}

	/**
	 * dumps config to a string
	 * @param dump string to dump to
	 */
	void DumpConfig(std::string& dump) const;

private:
	bool ProcessCmdLine(const int argc, char** argv);
	bool ProcessConfigFile();
	bool ValidateConfig() const;

private:
	CommandLine cmdLine;
	ConfigFile  configFile;
	std::string configFileName;
	std::vector<ConfigEntry> registeredParams;
	std::map<std::string,std::string> defaultValues;
};

}
