/*
 * UnitTestPCRERegex.h
 *
 *  Created on: 19.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTest.h"

namespace toolbot {

struct PCRERegexUnitTestEntry {

	PCRERegexUnitTestEntry()
	: caseInsensitive(false)
	, multiline(false)
	, utf8Mode(false)
	{}

	std::string regex;
	std::string target;

	bool caseInsensitive;
	bool multiline;
	bool utf8Mode;

	std::vector<std::string> expectedGroups;
	size_t line;
};

class UnitTestPCRERegex : public UnitTest {
public:
	UnitTestPCRERegex(const std::string& unitTestFile);
	virtual ~UnitTestPCRERegex();

public:
	virtual bool Run();

private:
	void ParseTestFile(const std::string& unitTestFile);

private:
	static void ParseExpectedGroups(const std::string& groupsTerm, PCRERegexUnitTestEntry& entry);
	static void OnError(const std::string& formatMessage,const PCRERegexUnitTestEntry& entry, const std::vector<std::string>& groups);

private:
	std::vector<PCRERegexUnitTestEntry> testEntries;
};

}

