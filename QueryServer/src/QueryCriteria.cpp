/**
 *
 * @file QueryCriteria.cpp
 * @author Moritz Wagner
 * @date 23.02.2014
 *
 */

#include "QueryCriteria.h"

#include <InvalidOperationException.h>

namespace queryserver {

QueryCriteria::QueryCriteria() {
}

QueryCriteria::~QueryCriteria() {
}

const Relevance& QueryCriteria::GetRelevanceByCriteria(const QueryCriteria::QueryCriteriaFlag& type) const {

	if(!IsCriteriaEnabled(type)) {
		THROW_EXCEPTION(errors::InvalidOperationException,"queryserver::QueryCriteria::GetRelevanceByCriteria(type == not enabled)"); }

	switch(type)
	{
	case CRITERIA_META:
	case CRITERIA_DOMAIN:
	case CRITERIA_CONTENT:
	case CRITERIA_PATH:
	case CRITERIA_LINKS:
		return relevance.find(type)->second;

	default:
		THROW_EXCEPTION(errors::InvalidOperationException,"queryserver::QueryCriteria::GetRelevanceByCriteria(type == invalid)");
	}
}

QueryCriteria::QueryCriteriaFlag QueryCriteria::GetEnabledFlags(void) const {

	unsigned long flag(CRITERIA_UNKNOWN);

	std::map<QueryCriteriaFlag,Relevance>::const_iterator i(relevance.begin());
	for(;i!= relevance.end();++i) {
		flag |= reinterpret_cast<const unsigned long&>(i->first);}
	return reinterpret_cast<QueryCriteria::QueryCriteriaFlag&>(flag);
}

bool QueryCriteria::IsCriteriaEnabled(const QueryCriteria::QueryCriteriaFlag& type) const {
	return (relevance.find(type) != relevance.end());
}

}
