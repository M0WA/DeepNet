/*
 * BackLinkEntry.h
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <list>

#include <DatabaseUrl.h>
#include "Relevance.h"

namespace queryserver {

class BackLinkEntry : public Relevance
{
public:
	BackLinkEntry(const double& relevance, const double& weight, const long long urlStageID, const std::vector<htmlparser::DatabaseUrl>& backlinks)
	: Relevance(relevance, weight)
	, urlStageID(urlStageID)
	, backlinks(backlinks) {}

	BackLinkEntry()
	: Relevance(0.0,0.0)
	, urlStageID(-1) {}

public:
	const long long         UrlStageID() const { return urlStageID; }
	const std::vector<htmlparser::DatabaseUrl>& BackLinks()  const { return backlinks;  }

private:
	long long urlStageID;
	std::vector<htmlparser::DatabaseUrl> backlinks;
};

}
