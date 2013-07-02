/**
 *
 * @file ConfigEntry.h
 * @author Moritz Wagner
 * @date 02.07.2013
 *
 */

#pragma once

#include <string>

namespace bot {

/**
 * @brief implements a registered configuration parameter
 * @see bot::ConfigManager
 */
class ConfigEntry
{
private:
	ConfigEntry();

public:
	/**
	 * constructs a new entry of a registered configuration parameter
	 * @see bot::ConfigManager
	 * @param name name of the parameter
	 * @param desc description of the parameter
	 * @param mandatory true if parameter is mandatory
	 * @param isFlag true if parameter is a flag
	 * @param defaultValue default value of parameter or null if no default
	 */
	ConfigEntry(
		const std::string& name,
		const std::string& desc,
		const bool mandatory,
		const bool isFlag,
		const std::string* defaultValue );

	virtual ~ConfigEntry();

public:
	/**
	 * compares entry to a parameter name
	 * @param rhs name to compare to
	 * @return true if equals else false
	 */
	bool operator==(const std::string& rhs) const;

	/**
	 * sets value of the config parameter
	 * @param value value of the config parameter
	 */
	void SetValue(const std::string& value);

	/**
	 * sets value of the config parameter
	 * @param value value of the config parameter
	 */
	void SetValue(const char* value);

	/**
	 * gets value of the config parameter
	 * @return value value of the config parameter
	 */
	const std::string& GetValue() const;

	/**
	 * name of the parameter
	 */
	std::string name;

	/**
	 * description of the parameter
	 */
	std::string desc;

private:
	std::string value;

public:
	/**
	 * true if parameter is mandatory
	 */
	bool mandatory;

	/**
	 * true if parameter is a flag
	 */
	bool isFlag;

	/**
	 * true of parameter may not be overriden
	 */
	bool lockOverride;

	/**
	 * true if value is set
	 */
	bool valueSet;
};

}


