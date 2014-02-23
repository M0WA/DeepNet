/**
 *
 * @file QueryLimitations.cpp
 * @author Moritz Wagner
 * @date 23.02.2014
 *
 */

#include "QueryLimitations.h"

namespace queryserver {

QueryLimitations::QueryLimitations() {
}

QueryLimitations::~QueryLimitations() {
}

QueryLimitations::QueryLimitationsFlag QueryLimitations::GetEnabledFlags(void) const {

	QueryLimitations::QueryLimitationsFlag flag(LIMITATION_UNKNOWN);

	std::map<QueryLimitationsFlag,std::string>::const_iterator i(limits.begin());
	for(;i!= limits.end();++i) {
		reinterpret_cast<unsigned long&>(flag) |= i->first;}
	return flag;
}

bool QueryLimitations::IsLimitationEnabled(const QueryLimitations::QueryLimitationsFlag& type) const{
	return (limits.find(type) != limits.end());
}

}
