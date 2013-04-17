/**
 * @file DatabaseConfig.cpp
 * @author Moritz Wagner
 * @date 29.04.2012
 */

#include "DatabaseConfig.h"

namespace database {

DatabaseConfig::DatabaseConfig(const DatabaseType& type)
: type(type)
{
}

DatabaseConfig::~DatabaseConfig() {
}

}
