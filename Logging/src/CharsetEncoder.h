/**
 * @file CharsetEncoder.h
 * @author Moritz Wagner
 * @date 20.03.2012
 */

#pragma once

#include <string>

namespace tools
{

/**
 * @brief charset specific functions
 * this class is mainly a wrapper for libicu and libiconv.
 * it can convert and detect numerous character set encodings.
 */
class CharsetEncoder {
public:
	/**
	 * @struct tools::CharsetEncoder::DetectMatch
	 * @brief contains information about detected charsets.
	 */
	struct DetectMatch
	{
		/**
		 * contruct using a hint for a charset
		 * @param encodingHint name of a charset/encoding that should be taken as a hint.
		 */
		DetectMatch(const std::string& encodingHint)
		: encodingName()
		, encodingConfidence(0)
		, encodingHint(encodingHint)
		, encodingHintCorrect(false){}

		/**
		 * detected encoding name.
		 */
		std::string encodingName;

		/**
		 * @brief confidence of result.
		 * minimum confidence of 10 is has special meaning for more information:
		 * see documentation of ucsdet_getConfidence(const UCharsetMatch *ucsm, UErrorCode *status)
	     * http://icu-project.org/apiref/icu4c/ucsdet_8h.html#aa1dd7ce8c727d855697aac1f35df71ed).
		 *
		 */
		long encodingConfidence;

		/**
		 * encoding/charset hint.
		 */
		std::string encodingHint;

		/**
		 * set to true if hint was correct.
		 */
		bool encodingHintCorrect;

		/**
		 * detected language.
		 */
		std::string language;
	};

public:
	CharsetEncoder();
	virtual ~CharsetEncoder();

	/**
	 * @brief converts buffer to host charset.
	 * @param pszBuffer input buffer.
	 * @param len size of input buffer.
	 * @param inEnc encoding/charset name.
	 * @param sOutput gets filled with converted string.
	 * @return false on error, true on success.
	 * this function also zero terminates the string.
	 */
	static bool Convert(const char* pszBuffer, const int len, const std::string& inEnc, std::string& sOutput);

	/**
	 * detects charset of buffer
	 * @param pszBuffer input buffer.
	 * @param len size of input buffer.
	 * @param match gets filled with information about buffer.
	 * @return false on error, true on success.
	 */
	static bool Detect( const char* pszBuffer, const int len, DetectMatch& match );

	/**
	 * checks if string is a valid encoding/charset name.
	 * @param encodingName charset/encoding name.
	 * @return false if invalid name, true if valid name.
	 */
	static bool IsValidEncodingName(std::string& encodingName);

	/**
	 * checks if two string are aliases of the same charset.
	 * @param name1 charset/encoding name.
	 * @param name2 charset/encoding name.
	 * @return false if they are not aliases, true if they are.
	 */
	static bool IsCharsetAlias(const char* name1, const char* name2);

	/**
	 * gets charset name of current host system.
	 * @return charset name of current host system.
	 */
	static std::string GetHostCharsetName();

	/**
	 * converts characters to their html-entity equivalents.
	 * @param pszIn input buffer.
	 * @param inSize size of input buffer.
	 * @param out gets filled with html encoded string.
	 * @return false on error, true on success.
	 */
	static bool EncodeHtmlEntities(const unsigned char* pszIn, const int inSize, std::string& out);
};

}
