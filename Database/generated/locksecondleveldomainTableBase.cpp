#include "locksecondleveldomainTableBase.h"

#include "locksecondleveldomainTableDefinitionCreateParam.h"
#include "TableDefinition.h"
#include "TableColumnDefinition.h"
#include "TableColumn.h"
#include "WhereConditionTableColumnCreateParam.h"
#include "WhereConditionTableColumn.h"

#include "DatabaseConnection.h"
#include "DatabaseHelper.h"

#include "SelectStatement.h"
#include "UpdateStatement.h"

#include "InnerJoinEntry.h"

#include <StringTools.h>
#include <NotImplementedException.h>





namespace database {

locksecondleveldomainTableBase::locksecondleveldomainTableBase()
: TableBase(locksecondleveldomainTableBase::CreateTableDefinition()) {
}

locksecondleveldomainTableBase::locksecondleveldomainTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy locksecondleveldomainTableBase");
}

locksecondleveldomainTableBase::~locksecondleveldomainTableBase() {
}

TableDefinition* locksecondleveldomainTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(locksecondleveldomainTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void locksecondleveldomainTableBase::Get_SECONDLEVELDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void locksecondleveldomainTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void locksecondleveldomainTableBase::Get_CRAWLERSESSION_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void locksecondleveldomainTableBase::Set_CRAWLERSESSION_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void locksecondleveldomainTableBase::Get_schedule(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "schedule";
      break;
    case DB_IBM_DB2:
      fieldName = "schedule";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("schedule");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "schedule";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void locksecondleveldomainTableBase::Set_schedule(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "schedule";
      break;
    case DB_IBM_DB2:
      fieldName = "schedule";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("schedule");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "schedule";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void locksecondleveldomainTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void locksecondleveldomainTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void locksecondleveldomainTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void locksecondleveldomainTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void locksecondleveldomainTableBase::GetBy_schedule(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void locksecondleveldomainTableBase::GetBy_schedule(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(locksecondleveldomainTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//


//
// template: TableBase_WhereColumns.inc.cpp
//
void locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_schedule();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = locksecondleveldomainTableBase::GetDefinition_schedule();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* locksecondleveldomainTableBase::GetDefinition_SECONDLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "sync";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("locksecondleveldomain");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = true;
    createParam.isAutoGenerated     = true;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "sync";
      createParam.columnName   = "CRAWLERSESSION_ID";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CRAWLERSESSION_ID";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("locksecondleveldomain");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = true;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* locksecondleveldomainTableBase::GetDefinition_schedule() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "sync";
      createParam.columnName   = "schedule";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "schedule";
      createParam.tableName    = "locksecondleveldomain";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("schedule");
      createParam.tableName    = tools::StringTools::ToLowerNP("locksecondleveldomain");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
