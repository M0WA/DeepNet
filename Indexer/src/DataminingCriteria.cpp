/*
 * DataminingCriteria.cpp
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingCriteria.h"

#include <PCRERegex.h>
#include <NotImplementedException.h>

#include "Word.h"

namespace indexing {

DataminingCriteria::DataminingCriteria()
: database::dataminingcriteriaTableBase(){

	Get_keyword(keyword);
	Get_type(type);
}

DataminingCriteria::DataminingCriteria(const database::TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy DataminingCriteria");
}

DataminingCriteria::~DataminingCriteria(){
}

bool DataminingCriteria::Match(const std::set<Word>& words) const {

	std::set< Word >::const_iterator iterWords = words.begin();
	for(;iterWords != words.end();++iterWords) {
		if(type) {
			std::vector<std::string> groups;
			if(!tools::PCRERegex::Match(keyword,iterWords->GetString(),groups,true))
				return false;
			else
				return groups.size() > 0;
		} else {
			return keyword.compare(iterWords->GetString()) == 0;
		}
	}
	return false;
}

}
