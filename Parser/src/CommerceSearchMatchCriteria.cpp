/*
 * CommerceSearchMatchCriteria.cpp
 *
 *  Created on: 08.09.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchMatchCriteria.h"

#include <StringTools.h>
#include <PCRERegex.h>
#include <HttpUrlParser.h>
#include <NotImplementedException.h>

#include "CommerceSearchProduct.h"

namespace parser {

CommerceSearchMatchCriteria::CommerceSearchMatchCriteria()
: database::customermatchcriteriaTableBase()
, customerMatchCriteriaID(-1)
, matchCriteriaID(-1)
, matchType(UNKNOWN_CRITERIA_TYPE){
}

CommerceSearchMatchCriteria::CommerceSearchMatchCriteria(const database::TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy CommerceSearchMatchCriteria");
}

CommerceSearchMatchCriteria::~CommerceSearchMatchCriteria() {
}

void CommerceSearchMatchCriteria::Init(database::DatabaseConnection* db) {

	database::SelectResultContainer<database::matchcriteriaTableBase> criteria;
	database::SelectResultContainer<database::customermatchcriteriagrouptypeTableBase> groups;

	Get_ID(customerMatchCriteriaID);

	Get_MATCHCRITERIA_ID(matchCriteriaID);
	database::matchcriteriaTableBase::GetBy_ID(db,matchCriteriaID,criteria);
	if(criteria.Size() != 1) {
		THROW_EXCEPTION(errors::NotImplementedException,"invalid customer match criteria specified");}
	else
		criteria.ResetIter();
	criteria.GetIter()->Get_regex(regex);

	long long tmpMatchType = -1;
	Get_type(tmpMatchType);
	switch(tmpMatchType) {
	case URL_CRITERIA_TYPE:
		matchType = URL_CRITERIA_TYPE;
		break;
	case META_CRITERIA_TYPE:
		matchType = META_CRITERIA_TYPE;
		break;
	case CONTENT_CRITERIA_TYPE:
		matchType = CONTENT_CRITERIA_TYPE;
		break;
	case UNKNOWN_CRITERIA_TYPE:
	default:
		THROW_EXCEPTION(errors::NotImplementedException,"invalid customer match type specified");
		break;
	}

	database::customermatchcriteriagrouptypeTableBase::GetBy_CUSTOMERMATCHCRITERIA_ID(db,customerMatchCriteriaID,groups);
	groups.ResetIter();
	for(;!groups.IsIterEnd();groups.Next()) {
		long long tmpPos = -1,tmpType = -1, tmpIsPrimaryKey = -1;
		groups.GetIter()->Get_groupPosition(tmpPos);
		groups.GetIter()->Get_type(tmpType);
		groups.GetIter()->Get_isPrimaryKey(tmpIsPrimaryKey);

		CommerceSearchMatchGroup groupType;
		groupType.groupType    = (CommerceSearchMatchGroupType)tmpType;
		groupType.isPrimaryKey = tmpIsPrimaryKey > 0;
		groupType.position     = (size_t)tmpPos;

		posGroup[groupType.position] = groupType;
	}
}

void CommerceSearchMatchCriteria::GetAll(database::DatabaseConnection* db,database::SelectResultContainer<CommerceSearchMatchCriteria>& criterias) {

	database::SelectStatement selectAll(CommerceSearchMatchCriteria::CreateTableDefinition());
	selectAll.SelectAllColumns();
	db->Select(selectAll,criterias);

	criterias.ResetIter();
	for(;!criterias.IsIterEnd();criterias.Next()) {
		criterias.GetIter()->Init(db);	}
}

bool CommerceSearchMatchCriteria::Match(database::DatabaseConnection* db, const std::string& target) const {

	std::vector<std::string> groups;
	bool success = tools::PCRERegex::Match(regex,target,groups,false);

	if( !success || groups.size() == 0 || posGroup.size() != groups.size() )
		return false;

	CommerceSearchProduct product;
	std::map<size_t,CommerceSearchMatchGroup>::const_iterator iterGroups;
	for(iterGroups = posGroup.begin(); iterGroups != posGroup.end(); ++iterGroups) {

		const std::string& substring = groups.at(iterGroups->first);
		switch(iterGroups->second.groupType)
		{
		case PRODUCT_URL:
			product.productURL = substring;
			break;
		case PRODUCT_ID:
			product.productID = substring;
			break;
		case PRODUCT_NAME:
			product.productName = substring;
			break;
		case PRODUCT_DESCRIPTION:
			product.productDescription = substring;
			break;
		case PRODUCT_IMAGE:
			product.productImage = substring;
			break;
		default:
			break;
		}
	}
	product.Store(db);
	return success;
}

}
