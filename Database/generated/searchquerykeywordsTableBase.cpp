#include "searchquerykeywordsTableBase.h"

#include "searchquerykeywordsTableDefinitionCreateParam.h"
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



#include "keywordqueryTableBase.h"
#include "searchqueryTableBase.h"


namespace database {

searchquerykeywordsTableBase::searchquerykeywordsTableBase()
: TableBase(searchquerykeywordsTableBase::CreateTableDefinition()) {
}

searchquerykeywordsTableBase::searchquerykeywordsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy searchquerykeywordsTableBase");
}

searchquerykeywordsTableBase::~searchquerykeywordsTableBase() {
}

TableDefinition* searchquerykeywordsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(searchquerykeywordsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void searchquerykeywordsTableBase::Get_ID(long long& out) const {

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

const TableColumn* searchquerykeywordsTableBase::GetConstColumn_ID() const {

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

TableColumn* searchquerykeywordsTableBase::GetColumn_ID() {

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

void searchquerykeywordsTableBase::Set_ID(const long long& in) {

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

void searchquerykeywordsTableBase::Get_KEYWORDQUERY_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("KEYWORDQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "KEYWORDQUERY_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchquerykeywordsTableBase::GetConstColumn_KEYWORDQUERY_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("KEYWORDQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "KEYWORDQUERY_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchquerykeywordsTableBase::GetColumn_KEYWORDQUERY_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("KEYWORDQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "KEYWORDQUERY_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchquerykeywordsTableBase::Set_KEYWORDQUERY_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "KEYWORDQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("KEYWORDQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "KEYWORDQUERY_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void searchquerykeywordsTableBase::Get_SEARCHQUERY_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERY_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchquerykeywordsTableBase::GetConstColumn_SEARCHQUERY_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERY_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchquerykeywordsTableBase::GetColumn_SEARCHQUERY_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERY_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchquerykeywordsTableBase::Set_SEARCHQUERY_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERY_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void searchquerykeywordsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void searchquerykeywordsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void searchquerykeywordsTableBase::GetBy_KEYWORDQUERY_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_KEYWORDQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void searchquerykeywordsTableBase::GetBy_KEYWORDQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_KEYWORDQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void searchquerykeywordsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void searchquerykeywordsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchquerykeywordsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(searchquerykeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void searchquerykeywordsTableBase::AddInnerJoinLeftSideOn_KEYWORDQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = keywordqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = keywordqueryTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = searchquerykeywordsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchquerykeywordsTableBase::AddInnerJoinLeftSideOn_KEYWORDQUERY_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_KEYWORDQUERY_ID("","","","",stmt);
}

void searchquerykeywordsTableBase::AddInnerJoinRightSideOn_KEYWORDQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = searchquerykeywordsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID();
    TableDefinition*       joinTableDef        = keywordqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = keywordqueryTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchquerykeywordsTableBase::AddInnerJoinRightSideOn_KEYWORDQUERY_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_KEYWORDQUERY_ID("","","","",stmt);
}
void searchquerykeywordsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = searchqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = searchqueryTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = searchquerykeywordsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchquerykeywordsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SEARCHQUERY_ID("","","","",stmt);
}

void searchquerykeywordsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = searchquerykeywordsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID();
    TableDefinition*       joinTableDef        = searchqueryTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = searchqueryTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchquerykeywordsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SEARCHQUERY_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void searchquerykeywordsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void searchquerykeywordsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void searchquerykeywordsTableBase::GetWhereColumnsFor_KEYWORDQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void searchquerykeywordsTableBase::GetWhereColumnsFor_KEYWORDQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void searchquerykeywordsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void searchquerykeywordsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* searchquerykeywordsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquerykeywords");
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
TableColumnDefinition* searchquerykeywordsTableBase::GetDefinition_KEYWORDQUERY_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "KEYWORDQUERY_ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "KEYWORDQUERY_ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("KEYWORDQUERY_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquerykeywords");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = true;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* searchquerykeywordsTableBase::GetDefinition_SEARCHQUERY_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "SEARCHQUERY_ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SEARCHQUERY_ID";
      createParam.tableName    = "searchquerykeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquerykeywords");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = true;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
