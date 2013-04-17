/*
 * UrlStageEntry.h
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "KeywordEntry.h"
#include "BackLinkEntry.h"

namespace queryserver {

class UrlStageProperties
{
public:
	UrlStageProperties(
		const long long& urlStageID,
		const long long& urlID,
		const long long& secondLevelDomainID,
		const struct tm& lastVisited,
		const struct tm& lastChanged,
		const long long& contentSize)
	: urlStageID(urlStageID)
	, urlID(urlID)
	, secondLevelDomainID(secondLevelDomainID)
	, lastVisited(lastVisited)
	, lastChanged(lastChanged)
	, contentSize(contentSize) {}

public:
	const long long&  UrlStageID()          const { return urlStageID;          }
	const long long&  UrlID()               const { return urlID;               }
	const long long&  SecondLevelDomainID() const { return secondLevelDomainID; }
	const struct tm&  LastVisited()         const { return lastVisited;         }
	const struct tm&  LastChanged()         const { return lastChanged;         }
	const long long&  ContentSize()         const { return contentSize;         }

private:
	long long urlStageID;
	long long urlID;
	long long secondLevelDomainID;
	struct tm lastVisited;
	struct tm lastChanged;
	long long contentSize;
};

class UrlStageEntry
{
public:
	UrlStageEntry( const UrlStageProperties& stageProperties, const std::vector<KeywordEntry>& keywords, const BackLinkEntry& backlinkEntry )
	: stageProperties(stageProperties)
	, keywords(keywords)
	, backlinkEntry(backlinkEntry) {}

public:
	const std::vector<KeywordEntry>& Keywords() const { return keywords; }
	const BackLinkEntry& BackLinks() const { return backlinkEntry; }
	const UrlStageProperties& UrlStageProperty() const { return stageProperties; }

public:
	Relevance GetTotalRelevance() const;

private:
	UrlStageProperties stageProperties;
	std::vector<KeywordEntry> keywords;
	BackLinkEntry backlinkEntry;
};

}
