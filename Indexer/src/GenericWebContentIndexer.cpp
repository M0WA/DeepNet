/*
 * GenericWebContentIndexer.cpp
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebContentIndexer.h"

namespace indexing {

GenericWebContentIndexer::GenericWebContentIndexer(database::DatabaseConnection* database, const IndexerBase::IndexerType type, bool savePositions)
: ContentIndexer(database,type)
, dictionary(database,savePositions){
}

GenericWebContentIndexer::~GenericWebContentIndexer() {
}

}
