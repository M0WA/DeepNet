#include "locksecondleveldomainTableBase.h"

#include "locksecondleveldomainTableDefinitionCreateParam.h"
#include "TableDefinition.h"
#include "TableColumnDefinition.h"
#include "TableColumn.h"
#include "WhereConditionTableColumnCreateParam.h"
#include "WhereConditionTableColumn.h"

#include "DatabaseConnection.h"

#include "SelectStatement.h"
#include "UpdateStatement.h"

#include "InnerJoinEntry.h"

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
    GetConstColumnByName("SECONDLEVELDOMAIN_ID")->Get(out);
}

void locksecondleveldomainTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {
    GetColumnByName("SECONDLEVELDOMAIN_ID")->Set(in);
}

void locksecondleveldomainTableBase::Get_CRAWLERSESSION_ID(long long& out) const {
    GetConstColumnByName("CRAWLERSESSION_ID")->Get(out);
}

void locksecondleveldomainTableBase::Set_CRAWLERSESSION_ID(const long long& in) {
    GetColumnByName("CRAWLERSESSION_ID")->Set(in);
}

void locksecondleveldomainTableBase::Get_schedule(struct tm& out) const {
    GetConstColumnByName("schedule")->Get(out);
}

void locksecondleveldomainTableBase::Set_schedule(const struct tm& in) {
    GetColumnByName("schedule")->Set(in);
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
    createParam.columnName         = "SECONDLEVELDOMAIN_ID";
    createParam.tableName          = "locksecondleveldomain";
    createParam.databaseName       = "sync";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = true;
    createParam.isAutoGenerated    = true;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* locksecondleveldomainTableBase::GetDefinition_CRAWLERSESSION_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CRAWLERSESSION_ID";
    createParam.tableName          = "locksecondleveldomain";
    createParam.databaseName       = "sync";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = true;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* locksecondleveldomainTableBase::GetDefinition_schedule() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "schedule";
    createParam.tableName          = "locksecondleveldomain";
    createParam.databaseName       = "sync";
    createParam.columnType         = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
