/**
 * @file HashTools.h
 * @author Moritz Wagner
 * @date 08.11.2012
 */

#pragma once

#include <string>

namespace tools {

/**
 * @brief wrapper class for hashing algorithms.
 * this class wraps all kind of hashing functionalities.
 */
class HashTools {
private:
	HashTools();
	virtual ~HashTools();

public:
	/**
	 * gets salted md5 string from buffer.
	 * @param pszInput input buffer.
	 * @param salt salt.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const char* pszInput, const char* salt);

	/**
	 * gets salted md5 string from buffer with a predefined salt.
	 * @param pszInput input buffer.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const char* pszInput);

	/**
	 * gets md5 string from buffer.
	 * @param input input buffer.
	 * @return md5 string.
	 */
	static std::string GetMD5(const std::string& input);

	/**
	 * gets sha512 string from buffer.
	 * @param input input buffer.
	 * @return sha512 string.
	 */
	static std::string GetSHA512(const std::string& input);

private:
	static const char salt[];
};

}

