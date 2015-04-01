/*
 * DB2DatabaseConfig.h
 *
 *  Created on: 30.04.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseConfig.h"

namespace database {

class DB2DatabaseConfig : public DatabaseConfig {
public:
	DB2DatabaseConfig();
	virtual ~DB2DatabaseConfig();
};

}
