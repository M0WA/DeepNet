/*
 * MySQLQueryErrorException.h
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class MySQLQueryErrorException: public database::DatabaseException {
public:
	MySQLQueryErrorException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& MySQLerror,
			const std::string& stmt);
	virtual ~MySQLQueryErrorException();
};

}

