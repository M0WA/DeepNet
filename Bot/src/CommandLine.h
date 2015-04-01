/**
 * @file CommandLine.h
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#pragma once

#include <string>
#include <vector>

namespace bot {

	class ConfigEntry;

/**
 * @brief class for command line argument processing.
 */
class CommandLine
{
public:
	CommandLine();
	virtual ~CommandLine();

public:
	/**
	 * parsing command line from raw parameters
	 * and also validating parameters by their name
	 * @param argc number of commandline arguments.
	 * @param argv array of commandline arguments.
	 * @param registeredParams list of acceptable parameter names, gets filled if matching are found.
	 * @return false on error, true on success.
	 */
	bool ParseCommandLine(int argc, char** argv, std::vector<ConfigEntry>& registeredParams);

	/**
	 * gets path and filename of this binary.
	 * @return path and name of this binary.
	 */
	const std::string& GetApplicationNamePath() const { return applicationNamePath; }

	/**
	 * gets filename of this binary.
	 * @return filename of this binary.
	 */
	const std::string& GetApplicationName() const { return applicationName; }

private:
	std::string applicationNamePath;
	std::string applicationName;
};

}
