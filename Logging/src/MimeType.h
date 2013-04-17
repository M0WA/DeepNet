/**
 * @file MimeType.h
 * @author Moritz Wagner
 * @date 15.05.2012
 */

#pragma once

#include <magic.h>
#include <string>

namespace tools {

/**
 * @brief mime type parsing class.
 */
class MimeType {

public:
	MimeType();
	virtual ~MimeType();

public:
	/**
	 * get mime type from mime string.
	 * @param pszBuffer buffer.
	 * @param len size of buffer.
	 * @return mime type.
	 */
	std::string GetMimeType(const void* pszBuffer, const size_t len);

	/**
	 * get encoding from mime string.
	 * @param pszBuffer buffer.
	 * @param len size of buffer.
	 * @return mime encoding.
	 */
	std::string GetMimeEncoding(const void* pszBuffer, const size_t len);

public:
	/**
	 * parses mime string into type and encoding.
	 * @param mimeString mime type string.
	 * @param mimeType mime type.
	 * @param mimeEncoding encoding.
	 * @return false on error, true on success.
	 */
	static bool ParseMimeString(const std::string& mimeString, std::string& mimeType, std::string& mimeEncoding);

	/**
	 * gets charset from mime string.
	 * @param contentType mime string.
	 * @param encoding gets filled with name of encoding.
	 * @return false on error, true on success.
	 */
	static bool GetCharsetFromMimeString(const std::string& contentType, std::string& encoding);

private:
	magic_t magicCookie;
};

}
