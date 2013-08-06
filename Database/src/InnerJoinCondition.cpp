/**
 * @file InnerJoinCondition.cpp
 * @author Moritz Wagner
 * @date 20.06.2012
 */

#include "InnerJoinCondition.h"

#include <sstream>

#include <TableDefinition.h>
#include <TableColumnDefinition.h>

namespace database {

InnerJoinCondition::InnerJoinCondition()
{
}

InnerJoinCondition::~InnerJoinCondition()
{
	std::vector<InnerJoinEntry>::iterator iterEntry = entries.begin();
	for(;iterEntry != entries.end();++iterEntry) {
		delete iterEntry->joinTableDef;
		delete iterEntry->joinColumnDef;
		delete iterEntry->referencedTableDef;
		delete iterEntry->referencedColumnDef;}
}

void InnerJoinCondition::AddInnerJoin(
		database::TableDefinition* joinTableDef,
		database::TableColumnDefinition* joinColumnDef,
		database::TableDefinition* referencedTableDef,
		database::TableColumnDefinition* referencedColumnDef ) {

	AddInnerJoin(joinTableDef, joinColumnDef, referencedTableDef, referencedColumnDef, "", "", "", "");
}

void InnerJoinCondition::AddInnerJoin(
	database::TableDefinition* joinTableDef,
	database::TableColumnDefinition* joinColumnDef,
	database::TableDefinition* referencedTableDef,
	database::TableColumnDefinition* referencedColumnDef,
	const std::string& joinTableAlias,
	const std::string& joinColumnAlias,
	const std::string& referencedTableAlias,
	const std::string& referencedColumnsAlias ){

	InnerJoinEntry entry(joinTableDef, joinColumnDef, referencedTableDef, referencedColumnDef);
	entry.joinTableAlias         = joinTableAlias;
	entry.joinColumnAlias        = joinColumnAlias;
	entry.referencedTableAlias   = referencedTableAlias;
	entry.referencedColumnsAlias = referencedColumnsAlias;

	entries.push_back(entry);

}

std::string InnerJoinCondition::ToString(DatabaseConnection* db) const
{
	std::stringstream ssEntries;
	std::vector<InnerJoinEntry>::const_iterator iterEntry(entries.begin());
	for(;iterEntry != entries.end();++iterEntry){
		ssEntries << " " << iterEntry->ToString() << " ";}
	return ssEntries.str();
}

}
