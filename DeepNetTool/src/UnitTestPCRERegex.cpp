/*
 * UnitTestPCRERegex.cpp
 *
 *  Created on: 19.09.2012
 *      Author: Moritz Wagner
 */

#include "UnitTestPCRERegex.h"

#include <PCRERegex.h>
#include <Logging.h>
#include <PerformanceCounter.h>

#include <StringTools.h>
#include <FileTools.h>
#include <ContainerTools.h>

namespace toolbot {

UnitTestPCRERegex::UnitTestPCRERegex(const std::string& unitTestFile) {
	ParseTestFile(unitTestFile);
}

UnitTestPCRERegex::~UnitTestPCRERegex() {
}

void UnitTestPCRERegex::ParseTestFile(const std::string& unitTestFile) {

	std::vector<std::string> lines;
	if(!tools::FileTools::ReadFile(unitTestFile,lines)) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error while reading pcre test input file (%s)",unitTestFile.c_str());
		return; }

	std::string parseLineTerm = "^\\s*\"(.*?)\"\\s*;\\s*\"(0|1)\"\\s*;\\s*\"(0|1)\"\\s*;\\s*\"(0|1)\"\\s*;\\s*\"(.*?)\"\\s*;(.*)$";
	tools::PCRERegex parseLineRegex(parseLineTerm);

	std::vector<std::string>::const_iterator iterLines = lines.begin();
	for(int i = 1;iterLines != lines.end();i++,++iterLines){

		std::vector<std::string> parsedLineGroups;
		if(	!parseLineRegex.Match(*iterLines,parsedLineGroups)){
			continue;}
		if( parsedLineGroups.size() < 6 ) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error while parsing pcre regex test input in line %d:\n'%s' ", i, iterLines->c_str());
			continue;}

		PCRERegexUnitTestEntry entry;
		entry.regex           = parsedLineGroups.at(1);
		entry.caseInsensitive = atoi(parsedLineGroups.at(2).c_str()) == 1;
		entry.multiline       = atoi(parsedLineGroups.at(3).c_str()) == 1;
		entry.utf8Mode        = atoi(parsedLineGroups.at(4).c_str()) == 1;
		entry.target          = parsedLineGroups.at(5);
		entry.line            = i;

		if( parsedLineGroups.size() == 7 ) {
			ParseExpectedGroups(parsedLineGroups.at(6),entry); }

		if(entry.expectedGroups.size()>0) {
			entry.expectedGroups.insert(entry.expectedGroups.begin(),entry.target); }

		testEntries.push_back(entry);
	}
}

void UnitTestPCRERegex::ParseExpectedGroups(const std::string& groupsTerm, PCRERegexUnitTestEntry& entry){

	tools::StringTools::SplitBy(groupsTerm,";",entry.expectedGroups);
	if(entry.expectedGroups.size() == 0){
		return; }

	std::string parseGroupTerm = "\\s*\"(.*?)\"\\s*";
	tools::PCRERegex parseGroupRegex(parseGroupTerm);

	std::vector<std::string>::iterator iterGroups = entry.expectedGroups.begin();
	for(int i = 0;iterGroups != entry.expectedGroups.end();i++,++iterGroups){

		std::vector<std::string> parsedGroup;
		if(!parseGroupRegex.Match(*iterGroups,parsedGroup) || parsedGroup.size() != 2){
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error while parsing %d. group in line %d:\n'%s'", i, entry.line, iterGroups->c_str());
			entry.expectedGroups.clear();
			return;}
		*iterGroups = parsedGroup.at(1);
	}
}

bool UnitTestPCRERegex::Test(){

	std::vector<PCRERegexUnitTestEntry>::const_iterator iterEntries = testEntries.begin();

	PERFORMANCE_LOG_START;
	for(int i = 0;iterEntries != testEntries.end();i++,++iterEntries){

		tools::PCRERegex regex(iterEntries->regex,iterEntries->caseInsensitive,iterEntries->multiline,iterEntries->utf8Mode);
		std::vector<std::string> groups;

		bool match = false;
		if(!(match = regex.Match(iterEntries->target,groups)) && iterEntries->expectedGroups.size() > 0){
			OnError("error while evaluating expression from line %d, aborting...",*iterEntries,groups);
			return false;}
		else if(!match && iterEntries->expectedGroups.size() == 0){
			return true;}

		if(groups.size() != iterEntries->expectedGroups.size()){
			OnError("number of groups not matching in expression from line %d, aborting...",*iterEntries,groups);
			return false;}

		if(!tools::ContainerTools::CompareVector(groups,iterEntries->expectedGroups)) {
			OnError("content of groups not matching in expression from line %d, aborting...",*iterEntries,groups);
			return false;}
	}
	std::stringstream ssPerf;
	ssPerf << "evaluated " << testEntries.size() << " pcre entries";
	PERFORMANCE_LOG_STOP(ssPerf.str());

	return true;
}

void UnitTestPCRERegex::OnError(const std::string& formatMessage,const PCRERegexUnitTestEntry& entry, const std::vector<std::string>& groups){

	std::string detectedGroupsDump,expectedGroupsDump;
	tools::ContainerTools::DumpVector(groups,detectedGroupsDump);
	tools::ContainerTools::DumpVector(entry.expectedGroups,expectedGroupsDump);
	log::Logging::Log(log::Logging::LOGLEVEL_ERROR,formatMessage.c_str(), entry.line);
	log::Logging::Log(log::Logging::LOGLEVEL_INFO,"\n\t===> '%s' -> '%s' <===\ndetected groups:\n%s\nexpected groups:\n%s\n", entry.regex.c_str(), entry.target.c_str(), detectedGroupsDump.c_str(), expectedGroupsDump.c_str());
}

}
