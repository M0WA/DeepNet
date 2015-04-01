/*
 * MySQLOperationTimeoutException.h
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class MySQLOperationTimeoutException: public database::DatabaseException {
public:
	MySQLOperationTimeoutException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~MySQLOperationTimeoutException();
};

}

