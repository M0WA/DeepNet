/*
 * DatabaseNotConnectedException.h
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseNotConnectedException : DatabaseException {
public:
	DatabaseNotConnectedException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseNotConnectedException();
};

}

