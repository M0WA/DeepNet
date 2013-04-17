/**
 * @file FileTools.h
 * @author Moritz Wagner
 * @date 30.11.2012
 */

#pragma once

#include <vector>
#include <string>

namespace tools {

/**
 * @brief wrapper class for filesystem functionality.
 * this class wraps all kind of file and filesystem
 * related functionalities.
 */
class FileTools {
private:
	FileTools();
public:
	virtual ~FileTools();

public:
	/**
	 * deletes file by filename.
	 * @param fileName filename.
	 * @return false on error, true on success.
	 */
	static bool DeleteFile(const std::string& fileName);

	/**
	 * read file contents into string.
	 * @param fileName filename.
	 * @param fileContents gets filled with file contents.
	 * @return false on error, true on success.
	 */
	static bool ReadFile(const std::string& fileName, std::string& fileContents);

	/**
	 * read file contents into list of lines
	 * @param fileName filename.
	 * @param lines gets filled with lines.
	 * @return false on error, true on success.
	 */
	static bool ReadFile(const std::string& fileName,std::vector<std::string>& lines);

	/**
	 * writes string to a file
	 * @param fileName filename.
	 * @param fileContents content to be written.
	 * @param append true if appending to file, false if file should be truncated before writing.
	 * @return false on error, true on success.
	 */
	static bool WriteFile(const std::string& fileName, const std::string& fileContents, const bool append);

	/**
	 * gets list of contents of a directory.
	 * @param files gets filled with files in directory.
	 * @param directory directory to list.
	 * @param onlyFiles true if only files should be listed, if false directories are also in files lists.
	 */
	static void ListDirectory(std::vector<std::string>& files, const std::string& directory, const bool onlyFiles = false);

	/**
	 *gets list of contents of a directory matching a regex.
	 * @param files gets filled with files in directory.
	 * @param directory directory to list.
	 * @param matchString pcre compatible regex a filename must match.
	 * @param onlyFiles true if only files should be listed, if false directories are also in files lists.
	 */
	static void ListDirectory(std::vector<std::string>& files, const std::string& directory, const std::string& matchString, const bool onlyFiles = false);
};

}

