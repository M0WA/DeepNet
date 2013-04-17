/**
 * @file StringTools.h
 * @author Moritz Wagner
 * @date 23.03.2012
 */

#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace tools
{

/**
 * @brief string manipulation class
 */
class StringTools {
private:
	StringTools();
	virtual ~StringTools();

public:
	/**
	 * replaces occurances of patterns in string
	 * @param oldstr string to be replaced.
	 * @param newstr string to be replaced by.
	 * @param target target string.
	 */
	static void ReplaceString(const std::string& oldstr, const std::string& newstr, std::string& target);

	/**
	 * removes empty lines from a list of lines.
	 * @param fileContent list of lines.
	 */
	static void RemoveEmptyLines(std::vector<std::string>& fileContent);

	/**
	 * trims string in place.
	 * @param s string to trim.
	 */
	static void Trim (std::string &s);

	/**
	 * trims string on left side.
	 * @param s string to trim.
	 */
	static void LeftTrim(std::string &s);

	/**
	 * trims string on right side.
	 * @param s string to trim.
	 */
	static void RightTrim(std::string &s);

	/**
	 * lowers string in place.
	 * @param s string to lower.
	 * @return lowercase string.
	 */
	static std::string& ToLowerIP(std::string& s);

	/**
	 * lowers string.
	 * @param s string to lower.
	 * @return lowercase string.
	 */
	static std::string ToLowerNP(const std::string& s);

	/**
	 * removes comments from a list of lines (lines beginning with #)
	 * @param fileContent list of lines.
	 */
	static void RemoveComments(std::vector<std::string>& fileContent);

	/**
	 * splits a string by a separator.
	 * @param text string to split.
	 * @param separators string to split by.
	 * @param words list of splitted patterns.
	 */
	static void SplitBy(const std::string & text, const std::string & separators, std::vector<std::string> & words);

	/**
	 * creates a formated string.
	 * @param outString gets filled with formated string.
	 * @param fmt format string.
	 */
	static void FormatString(std::string& outString, const char* fmt, ...);

	/**
	 * checks if a string is numeric.
	 * @param in string to check.
	 * @return false if not numeric, true if numeric.
	 */
	static bool IsNumeric(const std::string& in);

public:
	/**
	 * executes command saving it's output.
	 * @param cmd command to execute.
	 * @param output output of command.
	 * @param maxOutputSize maximum size of output string.
	 * @return return value of command.
	 */
	static int ExecuteCommand( const std::string& cmd, std::string& output, const int maxOutputSize = 1024);

public:
	/**
	 * converts generic vector to a string.
	 * @param vecIn vector to convert.
	 * @param out output string.
	 * @param separator NULL for no separator, otherwise separator to use.
	 */
	template <class T>
	static void VectorToString(const std::vector<T>& vecIn, std::string& out, const char* separator = 0) {
		if(vecIn.size() == 0)
			return;
		std::ostringstream ssIn;
		typename std::vector<T>::const_iterator iterType = vecIn.begin();
		for(size_t i = 0; iterType != vecIn.end(); i++,++iterType) {
			if(separator != 0 && i )
				ssIn << separator;
			ssIn << *iterType;}
		out = ssIn.str();
	}

	/**
	 * converts generic vector to a string.
	 * @param vecIn vector to convert.
	 * @param prefix string to put before every item.
	 * @param postfix string to put after every item.
	 * @param out output string.
	 */
	template <class T>
	static void VectorToString(const std::vector<T>& vecIn, const std::string& prefix, const std::string& postfix, std::string& out) {
		if(vecIn.size() == 0)
			return;
		std::ostringstream ssIn;
		typename std::vector<T>::const_iterator iterType = vecIn.begin();
		for(; iterType != vecIn.end(); ++iterType) {
			ssIn << prefix << *iterType << postfix;	}
		out = ssIn.str();
	}

	/**
	 * converts string to generic type.
	 * @param in string to convert.
	 * @param out output.
	 * @return false on error, true on success.
	 */
	template <class T>
	static bool TransformString(const std::string& in, T& out)	{
		std::stringstream ssConvert;
		ssConvert << std::skipws;
		ssConvert << in;
		ssConvert >> out;
		return !ssConvert.fail();
	}

	/**
	 * converts generic type to a string.
	 * @param in string to convert.
	 * @return converted string.
	 */
	template <class T>
	static std::string TransformString(const T& in) {
		std::ostringstream ssConvert;
		ssConvert << in;
		if(ssConvert.fail()) {
			return "";	}
		else
			return ssConvert.str();
	}

	/**
	 * transform a string containing hex values to a numeric value.
	 * @param in string to convert.
	 * @param out converted value.
	 * @return false on error, true on success.
	 */
	static bool TransformHexString(const std::string& in, unsigned int& out) {
		std::stringstream ssConvert;
		ssConvert << std::hex << std::skipws << in;
		ssConvert >> out;
		return !ssConvert.fail();
	}

	/**
	 * transform a string containing hex values to a generic value.
	 * @param in string to convert.
	 * @param out converted value.
	 * @return false on error, true on success.
	 */
	template <class T>
	static bool TransformHexString(const std::string& in, T& out) {
		unsigned int x = 0;
		std::stringstream ssConvert;
		ssConvert << std::hex << std::skipws << in;
		ssConvert >> x;
		out = reinterpret_cast<T&>(x);
		return !ssConvert.fail();
	}

	/**
	 * transform a numeric value to a hex string.
	 * @param in value to convert.
	 * @return converted string.
	 */
	static std::string TransformHexString(const unsigned int& in) {
		std::ostringstream ssConvert;
		ssConvert << std::hex << in;
		if(ssConvert.fail()) {
			return "";	}
		else
			return ssConvert.str();

	}

	/**
	 * transform a generic value to a hex string.
	 * @param in value to convert.
	 * @return converted string.
	 */
	template <class T>
	static std::string TransformHexString(const T& in) {
		unsigned int x = reinterpret_cast<unsigned int>(in);
		std::ostringstream ssConvert;
		ssConvert << std::hex << in;
		if(ssConvert.fail()) {
			return "";	}
		else
			return ssConvert.str();
	}

	/**
	 * checks if comp is one of the strings in choice.
	 * use this function only with care.
	 * @param comp string to compare
	 * @param choice string to compare to (NEEDS TO BE ZERO TERMINATED)
	 * @return
	 */
	static bool IsOneOf(const std::string& comp, const char** choice) {

		for(size_t i = 0; choice[i] != 0; i++) {
			if(comp.compare(choice[i]) == 0)
				return true;
		}
		return false;
	}

public:
	//similiarity functions

	/*
	//
	//http://creativyst.com/Doc/Articles/SoundEx1/SoundEx1.htm
	//
	static int SoundEx(char *SoundEx, char *WordString, int LengthOption, int CensusOption);
	*/

	//
	// see http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B
	//
	template<class T>
	static unsigned int LevenshteinDistance(const T &s1, const T & s2) {
		const size_t len1 = s1.size(), len2 = s2.size();
		std::vector<unsigned int> col(len2+1), prevCol(len2+1);
		for (unsigned int i = 0; i < prevCol.size(); i++)
			prevCol[i] = i;
		for (unsigned int i = 0; i < len1; i++) {
			col[0] = i+1;
			for (unsigned int j = 0; j < len2; j++)
				col[j+1] = std::min( std::min( 1 + col[j], 1 + prevCol[1 + j]), prevCol[j] + (s1[i]==s2[j] ? 0 : 1) );
			col.swap(prevCol);
		}
		return prevCol[len2];
	}

	//
	// see http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B
	//
	template <class T>
	static unsigned int EditDistance(const T& s1, const T& s2) {
		const size_t len1 = s1.size(), len2 = s2.size();
		std::vector<std::vector<unsigned int> > d(len1 + 1, std::vector<unsigned int>(len2 + 1));
		d[0][0] = 0;
		for(unsigned int i = 1; i <= len1; ++i)
			d[i][0] = i;

		for(unsigned int i = 1; i <= len2; ++i)
			d[0][i] = i;

		for(unsigned int i = 1; i <= len1; ++i) {
			for(unsigned int j = 1; j <= len2; ++j) {
				  d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1), d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) );}
		}
		return d[len1][len2];
	}
};

}
