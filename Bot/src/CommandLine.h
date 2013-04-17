/**
 * @file CommandLine.h
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#pragma once

#include <string>
#include <sstream>
#include <map>
#include <vector>

namespace bot
{
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
	 * @param validParameterNames list of acceptable parameter names.
	 * @return false on error, true on success.
	 */
	bool ParseCommandLine(int argc, char** argv, const std::vector<std::string>& validParameterNames);

	/**
	 * gets command line parameters by their name and converts
	 * it to the given type T.
	 * @param name name of the commandline parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	template <class T>
	inline bool GetValue(const std::string& name, T& value) const
	{
		if(!cmdLineParams.count(name))
			return false;

		std::ostringstream in;
		in << std::skipws;
		in << cmdLineParams.at(name);
		in >> value;
		return true;
	}

	/**
	 * gets command line parameters by their name as a string.
	 * @param name name of the commandline parameter.
	 * @param value gets filled with value of parameter.
	 * @return false if non-existent, true on success.
	 */
	bool GetValue(const std::string& name, std::string& value) const;

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
	std::map<std::string,std::string> cmdLineParams;
	std::string applicationNamePath;
	std::string applicationName;
};

}
