/*
 * MySQLQueryResultStoreException.h
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include "DatabaseException.h"

namespace database {

class MySQLQueryResultStoreException: public DatabaseException {
public:
	MySQLQueryResultStoreException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~MySQLQueryResultStoreException();
};

}

