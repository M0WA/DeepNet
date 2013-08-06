/**
 * @file InnerJoinEntry.cpp
 * @author Moritz Wagner
 * @date 16.08.2012
 */

#include "InnerJoinEntry.h"

#include <sstream>

#include <TableColumnDefinition.h>
#include <TableDefinition.h>

namespace database {

InnerJoinEntry::InnerJoinEntry(
	database::TableDefinition* joinTableDef,
	database::TableColumnDefinition* joinColumnDef,
	database::TableDefinition* referencedTableDef,
	database::TableColumnDefinition* referencedColumnDef)
: joinTableDef(joinTableDef)
, joinColumnDef(joinColumnDef)
, referencedTableDef(referencedTableDef)
, referencedColumnDef(referencedColumnDef) {
}

InnerJoinEntry::~InnerJoinEntry() {
}

std::string InnerJoinEntry::ToString(void) const
{
	std::string nonAliasedJoinTableName(joinTableDef->DatabaseName().empty() ? "" : joinTableDef->DatabaseName() + ".");
	nonAliasedJoinTableName.append(joinTableDef->TableName());
	std::string aliasedJoinTableName(joinTableAlias.empty() ? nonAliasedJoinTableName : joinTableAlias);

	std::string aliasedReferencedTableName((referencedTableDef->DatabaseName().empty() ? "" : referencedTableDef->DatabaseName()) + "." + referencedTableDef->TableName());
	if(!referencedTableAlias.empty())
		aliasedReferencedTableName = referencedTableAlias;

	std::stringstream ssEntry;
	ssEntry <<
		" INNER JOIN " <<  nonAliasedJoinTableName << " " << joinTableAlias <<
		" ON " <<
		" " << aliasedJoinTableName <<
		"." << (joinColumnAlias.empty() ? joinColumnDef->GetColumnName() : joinColumnAlias) <<
		"=" << aliasedReferencedTableName <<
		"." << (referencedColumnsAlias.empty() ? referencedColumnDef->GetColumnName() : referencedColumnsAlias);
	return ssEntry.str();
}

}
