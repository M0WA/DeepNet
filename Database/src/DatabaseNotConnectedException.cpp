/*
 * DatabaseNotConnectedException.cpp
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseNotConnectedException.h"

namespace database {

DatabaseNotConnectedException::DatabaseNotConnectedException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseNotConnectedException","database not connected") {
}

DatabaseNotConnectedException::~DatabaseNotConnectedException() {
}

}
