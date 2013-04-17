#include "logmessagesTableBase.h"

#include "logmessagesTableDefinitionCreateParam.h"
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

logmessagesTableBase::logmessagesTableBase()
: TableBase(logmessagesTableBase::CreateTableDefinition()) {
}

logmessagesTableBase::logmessagesTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy logmessagesTableBase");
}

logmessagesTableBase::~logmessagesTableBase() {
}

TableDefinition* logmessagesTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(logmessagesTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void logmessagesTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void logmessagesTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void logmessagesTableBase::Get_loglevel(long long& out) const {
    GetConstColumnByName("loglevel")->Get(out);
}

void logmessagesTableBase::Set_loglevel(const long long& in) {
    GetColumnByName("loglevel")->Set(in);
}

void logmessagesTableBase::Get_message(std::string& out) const {
    GetConstColumnByName("message")->Get(out);
}

void logmessagesTableBase::Set_message(const std::string& in) {
    GetColumnByName("message")->Set(in);
}

void logmessagesTableBase::Get_actiontime(struct tm& out) const {
    GetConstColumnByName("actiontime")->Get(out);
}

void logmessagesTableBase::Set_actiontime(const struct tm& in) {
    GetColumnByName("actiontime")->Set(in);
}

void logmessagesTableBase::Get_pid(long long& out) const {
    GetConstColumnByName("pid")->Get(out);
}

void logmessagesTableBase::Set_pid(const long long& in) {
    GetColumnByName("pid")->Set(in);
}

void logmessagesTableBase::Get_tid(long long& out) const {
    GetConstColumnByName("tid")->Get(out);
}

void logmessagesTableBase::Set_tid(const long long& in) {
    GetColumnByName("tid")->Set(in);
}

void logmessagesTableBase::Get_appName(std::string& out) const {
    GetConstColumnByName("appName")->Get(out);
}

void logmessagesTableBase::Set_appName(const std::string& in) {
    GetColumnByName("appName")->Set(in);
}

void logmessagesTableBase::Get_threadName(std::string& out) const {
    GetConstColumnByName("threadName")->Get(out);
}

void logmessagesTableBase::Set_threadName(const std::string& in) {
    GetColumnByName("threadName")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void logmessagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_loglevel(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_loglevel(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_loglevel(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_loglevel(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_message(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_message(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_message(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_message(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_actiontime(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_actiontime(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_actiontime(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_actiontime(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_pid(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_pid(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_pid(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_pid(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_tid(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_tid(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_tid(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_tid(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_appName(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_appName(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_appName(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_appName(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_threadName(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_threadName(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void logmessagesTableBase::GetBy_threadName(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    logmessagesTableBase::GetWhereColumnsFor_threadName(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(logmessagesTableBase::CreateTableDefinition());
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
void logmessagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_loglevel(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_loglevel();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_loglevel(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_loglevel();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_message(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_message();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_message(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_message();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_actiontime(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_actiontime();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_actiontime(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_actiontime();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_pid(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_pid();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_pid(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_pid();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_tid(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_tid();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_tid(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_tid();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_appName(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_appName();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_appName(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_appName();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_threadName(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_threadName();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void logmessagesTableBase::GetWhereColumnsFor_threadName(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = logmessagesTableBase::GetDefinition_threadName();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* logmessagesTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
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
TableColumnDefinition* logmessagesTableBase::GetDefinition_loglevel() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "loglevel";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_message() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "message";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_actiontime() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "actiontime";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
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
TableColumnDefinition* logmessagesTableBase::GetDefinition_pid() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "pid";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_tid() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "tid";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_appName() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "appName";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_threadName() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "threadName";
    createParam.tableName          = "logmessages";
    createParam.databaseName       = "logging";
    createParam.columnType         = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
