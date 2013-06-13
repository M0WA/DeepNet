/*
 * DataminingContentIndexer.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingContentIndexer.h"

namespace indexing {

DataminingContentIndexer::DataminingContentIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type)
: ContentIndexer(database,type)
, dictionary(database) {
}

DataminingContentIndexer::~DataminingContentIndexer() {
}

}
