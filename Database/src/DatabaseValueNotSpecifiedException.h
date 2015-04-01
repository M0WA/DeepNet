/*
 * DatabaseValueNotSpecifiedException.h
 *
 *  Created on: 12.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseValueNotSpecifiedException: public database::DatabaseException {
public:
	DatabaseValueNotSpecifiedException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseValueNotSpecifiedException();
};

}

