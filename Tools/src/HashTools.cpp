/**
 * @file HashTools.cpp
 * @author Moritz Wagner
 * @date 08.11.2012
 */

#include "HashTools.h"

#include <openssl/md5.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

#include <cstring>
#include <crypt.h>

#include <sstream>
#include <iomanip>

namespace tools {

const char HashTools::defaultSalt[] = "$1$6buND7vK";

HashTools::HashTools() {
}

HashTools::~HashTools() {
}

std::string HashTools::GetSaltedMD5(const char* input, const size_t& size, const char* pszSalt) {
	struct crypt_data data;
	data.initialized = 0;

	//crypt_r returns md5 in <salt(11)>$<md5sum>
	size_t saltSize(strlen(pszSalt) + 1);
	return std::string(crypt_r(input, pszSalt, &data)).substr(saltSize,size-saltSize);
}

std::string HashTools::GetSaltedMD5(const char* pszInput, const size_t& size) {
	return GetSaltedMD5(pszInput, size, defaultSalt);
}

std::string HashTools::GetSaltedMD5(const std::string& input) {
	return GetSaltedMD5(input.c_str(), input.size(), defaultSalt);
}

std::string HashTools::GetSaltedMD5(const std::string& input, const char* pszSalt) {
	return GetSaltedMD5(input.c_str(),input.size(), pszSalt);
}

std::string HashTools::GetMD5(const char* input, const size_t& size)
{
	unsigned char out[MD5_DIGEST_LENGTH];
	memset(out,0,MD5_DIGEST_LENGTH);
	MD5(reinterpret_cast<const unsigned char*>(input),size,out);

	std::ostringstream ssHex;
	ssHex << std::hex << std::setfill('0');
	for(int i=0; i <MD5_DIGEST_LENGTH; i++) {
		ssHex << std::setw(2) << std::hex << static_cast<int>(out[i]);	}

	return ssHex.str();
}

std::string HashTools::GetMD5(const std::string& input) {
	return GetMD5(input.c_str(), input.size());
}

std::string HashTools::GetSHA512(const char* input, const size_t& size)
{
	unsigned char out[EVP_MAX_MD_SIZE];
	memset(out,0,EVP_MAX_MD_SIZE);
	SHA512(reinterpret_cast<const unsigned char*>(input),size,out);

	std::ostringstream ssHex;
	ssHex << std::hex << std::setfill('0');
	for(int i=0; i <EVP_MAX_MD_SIZE; i++) {
		ssHex << std::setw(2) << std::hex << static_cast<int>(out[i]);	}

	return ssHex.str();
}

std::string HashTools::GetSHA512(const std::string& input) {
	return GetSHA512(input.c_str(), input.size());
}

}
