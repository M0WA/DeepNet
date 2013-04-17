/*
 * MySQLQueryResultStoreException.cpp
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#include "MySQLQueryResultStoreException.h"

namespace database {

MySQLQueryResultStoreException::MySQLQueryResultStoreException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"MySQLQueryResultStoreException","could not store query result"){
}

MySQLQueryResultStoreException::~MySQLQueryResultStoreException() {
}

}
