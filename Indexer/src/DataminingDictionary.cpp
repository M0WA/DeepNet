/*
 * DataminingDictionary.cpp
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingDictionary.h"

#include "DataminingNotifier.h"
#include "DataminingCriteria.h"

namespace indexing {

DataminingDictionary::DataminingDictionary(database::DatabaseConnection* database)
: Dictionary(database) {
	InitFromDatabase();
}

DataminingDictionary::~DataminingDictionary() {

	CleanUp(mapDataMiningContent);
	CleanUp(mapDataMiningMeta);
}

void DataminingDictionary::CleanUp(std::map< DataminingCriteria*, std::list<DataminingNotifier*> >& map) {

	std::map< DataminingCriteria*, std::list<DataminingNotifier*> >::iterator iterAlerts = map.begin();
	for(;iterAlerts != map.end(); ++iterAlerts) {
		delete iterAlerts->first;

		std::list<DataminingNotifier*>::iterator iterNotify = iterAlerts->second.begin();
		for(;iterNotify != iterAlerts->second.end();++iterNotify) {
			delete (*iterNotify); }
	}
}

void DataminingDictionary::InitFromDatabase() {

}

bool DataminingDictionary::CommitMeta(void) {
	wordMeta.clear();
	return true;
	//return Commit(mapDataMiningMeta);
}

bool DataminingDictionary::CommitContent(void) {
	return Commit(mapDataMiningContent);
}

bool DataminingDictionary::Commit(const std::map< DataminingCriteria*, std::list<DataminingNotifier*> >& mapDictionary) {
	if( testMode || !wordContent.size() )
		return true;

	std::list<DataminingNotifier*>::const_iterator iterNotifier;
	std::map< DataminingCriteria*, std::list<DataminingNotifier*> >::const_iterator iterAlerts = mapDictionary.begin();
	for(;iterAlerts != mapDictionary.end(); ++iterAlerts) {

		if( iterAlerts->first->Match(wordContent) ) {
			iterNotifier = iterAlerts->second.begin();
			for(;iterNotifier != iterAlerts->second.end(); ++iterNotifier) {
				(*iterNotifier)->AddAlert(iterAlerts->first);}
		}

		iterNotifier = iterAlerts->second.begin();
		for(;iterNotifier != iterAlerts->second.end(); ++iterNotifier) {
			(*iterNotifier)->OnNotify();}
	}

	wordContent.clear();
	return true;
}

}
