/**
 * @file ConfigFile.h
 * @author Moritz Wagner
 * @date 13.02.2012
 */

#pragma once

#include <string>
#include <vector>

namespace bot {

	class ConfigEntry;

/**
 * @brief class for config file processing.
 * processes config files in the form of key=value.
 * also accepts commentaries in config files using #'s.
 */
class ConfigFile {

public:
	ConfigFile();
	virtual ~ConfigFile();

	/**
	 * sets the filename of the config file and tries to process it.
	 * @param fileName filename of the config file
	 * @param validParameterNames list of parameters, will get filled if paramaters are found.
	 * @return false on error, true on success.
	 */
	bool ParseConfigFile(const std::string& fileName, std::vector<ConfigEntry>& registeredParams);

private:
	bool ParseFile(std::vector<std::string>& fileContent, std::vector<ConfigEntry>& registeredParams);

private:
	std::string fileName;
};

}
