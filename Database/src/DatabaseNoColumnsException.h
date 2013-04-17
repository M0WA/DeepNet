/*
 * DatabaseNoColumnsException.h
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseNoColumnsException: public DatabaseException {
public:
	DatabaseNoColumnsException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseNoColumnsException();
};

}

