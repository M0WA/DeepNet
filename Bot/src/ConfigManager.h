/**
 * @file ConfigManager.h
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#pragma once

#include "CommandLine.h"
#include "ConfigFile.h"

namespace bot
{

/**
 * @brief class for managing configuration file and commandline parameters.
 * processes and manages configuration accuired by configfile and commandline.
 */
class ConfigManager {

private:
	struct ConfigEntry
	{
		ConfigEntry()
		{
			name = "";
			desc = "";
			value = "";
			isFlag = false;
		}

		ConfigEntry( const std::string& name, const std::string& desc, const bool mandatory, const bool isFlag, const std::string* initialValue )
		{
			this->name = name;
			this->desc = desc;
			this->mandatory = mandatory;
			this->isFlag = isFlag;

			if(initialValue){
				this->value = *initialValue;}
			else {
				this->value = ""; }
		}

		std::string name;
		std::string desc;
		std::string value;
		bool mandatory;
		bool isFlag;
	};

public:
	ConfigManager();
	virtual ~ConfigManager();

	/**
	 * prints to usage to stdout.
	 */
	void PrintUsage(void) const;

	/**
	 * registers a parameter.
	 * @param paramName name of the parameter.
	 * @param description description of the parameter.
	 * @param isMandatory is a mandatory parameter.
	 * @param isFlag is parameter a flag.
	 * @param defaultValue default value of parameter or NULL if no default value.
	 */
	void RegisterParam(const std::string& paramName,
			const std::string& description,
			const bool isMandatory,
			const bool isFlag,
			const std::string* defaultValue);

	/**
	 * initializes command line.
	 * call this function before bot::ConfigManager::InitAndProcessConfigFile(const std::string&).
	 * @param argc number of commandline arguments.
	 * @param argv array of commandline arguments.
	 * @return false on error, true on success.
	 */
	bool Init(const int argc, char** argv);

	/**
	 * initializes config file and starts processing.
	 * bot::ConfigManager::Init() should be called before this function.
	 * commandline parameters from will be overidden by config file
	 * parameters if existing.
	 * @param configFileName
	 * @return false on error, true on success.
	 */
	bool InitAndProcessConfigFile(const std::string& configFileName);

	/**
	 * gets parameters by their name and converts
	 * it to the given type T.
	 * @param key name of the parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	template <class T>
	bool GetValue(const std::string& key, T& value) const {
		if(!configValues.count(key))
			return false;

		std::stringstream in;
		in << std::skipws;
		in << configValues.at(key);
		in >> value;
		return true;
	}

	/**
	 * gets parameters by their name as a string.
	 * @param key name of the parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	bool GetValue(const std::string& key, std::string& value) const {
		if(!configValues.count(key))
			return false;
		value = configValues.at(key);
		return true;
	}

	/**
	 * gets filename of this binary.
	 * @return filename of this binary.
	 */
	const std::string& GetApplicationName() const {	return cmdLine.GetApplicationName(); }

private:
	bool GetValueDirect(const std::string& key, std::string& value) const {
		if (cmdLine.GetValue(key,value)) {
			return true; }
		else if(configFile.GetValue(key, value)) {
			return true; }
		return false;
	}

	bool InitConfigFile();
	bool InitCommandLine(const int argc, char** argv);
	bool Process();

	std::map<std::string,std::string> configValues;
	std::vector<ConfigEntry> defaultConfig;
	std::vector<std::string> validParameterNames;
	CommandLine cmdLine;
	ConfigFile  configFile;
	std::string configFileName;
};

}
