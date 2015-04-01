/*
 * DatabaseValueNotSpecifiedException.cpp
 *
 *  Created on: 12.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseValueNotSpecifiedException.h"

namespace database {

DatabaseValueNotSpecifiedException::DatabaseValueNotSpecifiedException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseValueNotSpecifiedException", "no value specified where required") {
}

DatabaseValueNotSpecifiedException::~DatabaseValueNotSpecifiedException() {
}

}
