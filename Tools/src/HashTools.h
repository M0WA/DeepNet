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
	 * @param input input buffer.
	 * @param size size of buffer.
	 * @param pszSalt salt string.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const char* input, const size_t& size, const char* pszSalt);

	/**
	 * gets salted md5 string from string.
	 * @param input input string.
	 * @param pszSalt salt string.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const std::string& input, const char* pszSalt);

	/**
	 * gets salted md5 string from buffer with a predefined salt.
	 * @param input input buffer.
	 * @param size size of buffer.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const char* input, const size_t& size);

	/**
	 * gets salted md5 string from string with a predefined salt.
	 * @param input input string.
	 * @return salted md5 string.
	 */
	static std::string GetSaltedMD5(const std::string& input);

	/**
	 * gets md5 string from buffer.
	 * @param input input buffer.
	 * @param size size of buffer.
	 * @return md5 string.
	 */
	static std::string GetMD5(const char* input, const size_t& size);

	/**
	 * gets md5 string from string.
	 * @param input input string.
	 * @return md5 string.
	 */
	static std::string GetMD5(const std::string& input);

	/**
	 * gets sha512 string from buffer.
	 * @param input input buffer.
	 * @param size size of buffer.
	 * @return sha512 string.
	 */
	static std::string GetSHA512(const char* input, const size_t& size);

	/**
	 * gets sha512 string from string.
	 * @param input input string.
	 * @return sha512 string.
	 */
	static std::string GetSHA512(const std::string& input);

private:
	static const char defaultSalt[];
};

}

