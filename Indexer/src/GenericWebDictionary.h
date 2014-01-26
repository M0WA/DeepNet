/*
 * GenericWebDictionary.h
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Dictionary.h"

namespace indexing {

class GenericWebDictionary: public indexing::Dictionary {
public:
	GenericWebDictionary(database::DatabaseConnection* database, bool savePositions);
	virtual ~GenericWebDictionary();

public:
	virtual bool CommitMeta(void);
	virtual bool CommitContent(void);

private:
	bool savePositions;
};

}
