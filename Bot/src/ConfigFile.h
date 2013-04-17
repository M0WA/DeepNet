/**
 * @file ConfigFile.h
 * @author Moritz Wagner
 * @date 13.02.2012
 */

#pragma once

#include <string>
#include <map>
#include <vector>
#include <sstream>

namespace bot {

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
	 * @param validParameterNames list of acceptable parameter names.
	 * @return false on error, true on success.
	 */
	bool SetFileName(const std::string& fileName, const std::vector<std::string>& validParameterNames);

	/**
	 * gets config file parameters by their name and converts
	 * it to the given type T.
	 * @param key name of the config file parameter.
	 * @param out gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	template <class T>
	bool GetValue(const std::string& key, T& out) const {

		if(!mapKeyValues.count(key))
			return false;

		std::string realContent = mapKeyValues.at(key);
		std::ostringstream in;
		in << std::skipws;
		in << realContent;
		in >> out;
		return !in.bad();
	}

	/**
	 * gets config file parameters by their name as a string.
	 * @param key name of the config file parameter.
	 * @param out gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	bool GetValue(const std::string& key, std::string& out) const;

private:
	bool ParseFile(std::vector<std::string>& fileContent, const std::vector<std::string>& validParameterNames);

	std::string fileName;
	std::map<std::string,std::string> mapKeyValues;
};

}
