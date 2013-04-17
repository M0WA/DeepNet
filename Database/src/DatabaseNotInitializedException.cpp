/*
 * DatabaseNotInitializedException.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseNotInitializedException.h"

namespace database {

DatabaseNotInitializedException::DatabaseNotInitializedException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseNotInitializedException", "not initialized"){

}

DatabaseNotInitializedException::~DatabaseNotInitializedException() {
}

}
