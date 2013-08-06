#include "urlsearchpartsTableBase.h"

#include "urlsearchpartsTableDefinitionCreateParam.h"
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

urlsearchpartsTableBase::urlsearchpartsTableBase()
: TableBase(urlsearchpartsTableBase::CreateTableDefinition()) {
}

urlsearchpartsTableBase::urlsearchpartsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy urlsearchpartsTableBase");
}

urlsearchpartsTableBase::~urlsearchpartsTableBase() {
}

TableDefinition* urlsearchpartsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(urlsearchpartsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void urlsearchpartsTableBase::Get_ID(long long& out) const {

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

const TableColumn* urlsearchpartsTableBase::GetConstColumn_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsearchpartsTableBase::GetColumn_ID() {

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

    return GetColumnByName(fieldName);
}

void urlsearchpartsTableBase::Set_ID(const long long& in) {

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

void urlsearchpartsTableBase::Get_searchpart(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "searchpart";
      break;
    case DB_IBM_DB2:
      fieldName = "searchpart";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("searchpart");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "searchpart";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlsearchpartsTableBase::GetConstColumn_searchpart() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "searchpart";
      break;
    case DB_IBM_DB2:
      fieldName = "searchpart";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("searchpart");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "searchpart";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsearchpartsTableBase::GetColumn_searchpart() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "searchpart";
      break;
    case DB_IBM_DB2:
      fieldName = "searchpart";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("searchpart");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "searchpart";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlsearchpartsTableBase::Set_searchpart(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "searchpart";
      break;
    case DB_IBM_DB2:
      fieldName = "searchpart";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("searchpart");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "searchpart";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlsearchpartsTableBase::Get_md5(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "md5";
      break;
    case DB_IBM_DB2:
      fieldName = "md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "md5";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlsearchpartsTableBase::GetConstColumn_md5() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "md5";
      break;
    case DB_IBM_DB2:
      fieldName = "md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "md5";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsearchpartsTableBase::GetColumn_md5() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "md5";
      break;
    case DB_IBM_DB2:
      fieldName = "md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "md5";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlsearchpartsTableBase::Set_md5(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "md5";
      break;
    case DB_IBM_DB2:
      fieldName = "md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "md5";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void urlsearchpartsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsearchpartsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsearchpartsTableBase::GetBy_searchpart(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_searchpart(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsearchpartsTableBase::GetBy_searchpart(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_searchpart(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsearchpartsTableBase::GetBy_md5(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsearchpartsTableBase::GetBy_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsearchpartsTableBase::GetWhereColumnsFor_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsearchpartsTableBase::CreateTableDefinition());
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
void urlsearchpartsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsearchpartsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsearchpartsTableBase::GetWhereColumnsFor_searchpart(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_searchpart();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsearchpartsTableBase::GetWhereColumnsFor_searchpart(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_searchpart();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsearchpartsTableBase::GetWhereColumnsFor_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_md5();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsearchpartsTableBase::GetWhereColumnsFor_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsearchpartsTableBase::GetDefinition_md5();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* urlsearchpartsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlsearchparts");
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
TableColumnDefinition* urlsearchpartsTableBase::GetDefinition_searchpart() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "searchpart";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "searchpart";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("searchpart");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlsearchparts");
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
TableColumnDefinition* urlsearchpartsTableBase::GetDefinition_md5() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "md5";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "md5";
      createParam.tableName    = "urlsearchparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("md5");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlsearchparts");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_CHAR;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = true;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
