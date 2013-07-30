#include "logmessagesTableBase.h"

#include "logmessagesTableDefinitionCreateParam.h"
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

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ID";
      break;
    case DB_IBM_DB2:
      fieldName = "ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ID";
      break;
    case DB_IBM_DB2:
      fieldName = "ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_loglevel(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "loglevel";
      break;
    case DB_IBM_DB2:
      fieldName = "loglevel";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("loglevel");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "loglevel";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_loglevel(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "loglevel";
      break;
    case DB_IBM_DB2:
      fieldName = "loglevel";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("loglevel");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "loglevel";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_message(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "message";
      break;
    case DB_IBM_DB2:
      fieldName = "message";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("message");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "message";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_message(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "message";
      break;
    case DB_IBM_DB2:
      fieldName = "message";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("message");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "message";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_actiontime(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "actiontime";
      break;
    case DB_IBM_DB2:
      fieldName = "actiontime";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("actiontime");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "actiontime";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_actiontime(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "actiontime";
      break;
    case DB_IBM_DB2:
      fieldName = "actiontime";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("actiontime");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "actiontime";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_pid(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "pid";
      break;
    case DB_IBM_DB2:
      fieldName = "pid";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("pid");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "pid";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_pid(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "pid";
      break;
    case DB_IBM_DB2:
      fieldName = "pid";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("pid");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "pid";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_tid(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "tid";
      break;
    case DB_IBM_DB2:
      fieldName = "tid";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("tid");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "tid";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_tid(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "tid";
      break;
    case DB_IBM_DB2:
      fieldName = "tid";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("tid");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "tid";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_appName(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "appName";
      break;
    case DB_IBM_DB2:
      fieldName = "appName";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("appName");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "appName";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_appName(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "appName";
      break;
    case DB_IBM_DB2:
      fieldName = "appName";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("appName");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "appName";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void logmessagesTableBase::Get_threadName(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "threadName";
      break;
    case DB_IBM_DB2:
      fieldName = "threadName";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("threadName");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "threadName";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void logmessagesTableBase::Set_threadName(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "threadName";
      break;
    case DB_IBM_DB2:
      fieldName = "threadName";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("threadName");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "threadName";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
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
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
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
TableColumnDefinition* logmessagesTableBase::GetDefinition_loglevel() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "loglevel";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "loglevel";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("loglevel");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
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
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_message() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "message";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "message";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("message");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_VARCHAR;
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
TableColumnDefinition* logmessagesTableBase::GetDefinition_actiontime() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "actiontime";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "actiontime";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("actiontime");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
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
TableColumnDefinition* logmessagesTableBase::GetDefinition_pid() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "pid";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "pid";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("pid");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
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
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_tid() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "tid";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "tid";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("tid");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
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
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_appName() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "appName";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "appName";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("appName");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* logmessagesTableBase::GetDefinition_threadName() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "threadName";
      createParam.tableName    = "logmessages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "threadName";
      createParam.tableName    = "logmessages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("threadName");
      createParam.tableName    = tools::StringTools::ToLowerNP("logmessages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
