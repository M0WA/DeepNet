/*
 * DatabaseNotInitializedException.h
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseNotInitializedException: public database::DatabaseException {
public:
	DatabaseNotInitializedException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseNotInitializedException();
};

}

