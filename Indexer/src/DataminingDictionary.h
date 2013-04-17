/*
 * DataminingDictionary.h
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <map>
#include <list>

#include "Dictionary.h"

namespace database {
	class DatabaseConnection;
}

namespace indexing {

class DataminingCriteria;
class DataminingNotifier;
class DataminingDictionary : public Dictionary {
public:
	DataminingDictionary(database::DatabaseConnection* database);
	virtual ~DataminingDictionary();

public:
	virtual bool CommitMeta(void);
	virtual bool CommitContent(void);

private:
	bool Commit(const std::map< DataminingCriteria*, std::list<DataminingNotifier*> >& mapDictionary);
	void InitFromDatabase();
	void CleanUp(std::map< DataminingCriteria*, std::list<DataminingNotifier*> >& map);

private:
	std::map< DataminingCriteria*, std::list<DataminingNotifier*> > mapDataMiningContent;
	std::map< DataminingCriteria*, std::list<DataminingNotifier*> > mapDataMiningMeta;
};

}
