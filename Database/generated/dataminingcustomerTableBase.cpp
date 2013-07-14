#include "dataminingcustomerTableBase.h"

#include "dataminingcustomerTableDefinitionCreateParam.h"
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

dataminingcustomerTableBase::dataminingcustomerTableBase()
: TableBase(dataminingcustomerTableBase::CreateTableDefinition()) {
}

dataminingcustomerTableBase::dataminingcustomerTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dataminingcustomerTableBase");
}

dataminingcustomerTableBase::~dataminingcustomerTableBase() {
}

TableDefinition* dataminingcustomerTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dataminingcustomerTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dataminingcustomerTableBase::Get_ID(long long& out) const {

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

void dataminingcustomerTableBase::Set_ID(const long long& in) {

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

void dataminingcustomerTableBase::Get_login(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "login";
      break;
    case DB_IBM_DB2:
      fieldName = "login";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("login");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "login";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void dataminingcustomerTableBase::Set_login(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "login";
      break;
    case DB_IBM_DB2:
      fieldName = "login";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("login");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "login";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void dataminingcustomerTableBase::Get_password(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "password";
      break;
    case DB_IBM_DB2:
      fieldName = "password";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("password");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "password";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void dataminingcustomerTableBase::Set_password(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "password";
      break;
    case DB_IBM_DB2:
      fieldName = "password";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("password");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "password";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dataminingcustomerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcustomerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcustomerTableBase::GetBy_login(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_login(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcustomerTableBase::GetBy_login(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_login(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcustomerTableBase::GetBy_password(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_password(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcustomerTableBase::GetBy_password(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dataminingcustomerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcustomerTableBase::GetWhereColumnsFor_password(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcustomerTableBase::CreateTableDefinition());
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
void dataminingcustomerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcustomerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcustomerTableBase::GetWhereColumnsFor_login(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_login();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcustomerTableBase::GetWhereColumnsFor_login(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_login();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcustomerTableBase::GetWhereColumnsFor_password(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_password();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcustomerTableBase::GetWhereColumnsFor_password(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcustomerTableBase::GetDefinition_password();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dataminingcustomerTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "ID";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingcustomer");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
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
TableColumnDefinition* dataminingcustomerTableBase::GetDefinition_login() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "login";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "login";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("login");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingcustomer");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = true;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dataminingcustomerTableBase::GetDefinition_password() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "password";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "password";
      createParam.tableName    = "dataminingcustomer";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("password");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingcustomer");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
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

}
