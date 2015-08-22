#include "queryresultsTableBase.h"

#include "queryresultsTableDefinitionCreateParam.h"
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



#include "searchqueryTableBase.h"
#include "urlstagesTableBase.h"
#include "urlsTableBase.h"


namespace database {

queryresultsTableBase::queryresultsTableBase()
: TableBase(queryresultsTableBase::CreateTableDefinition()) {
}

queryresultsTableBase::queryresultsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy queryresultsTableBase");
}

queryresultsTableBase::~queryresultsTableBase() {
}

TableDefinition* queryresultsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(queryresultsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void queryresultsTableBase::Get_ID(long long& out) const {

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

const TableColumn* queryresultsTableBase::GetConstColumn_ID() const {

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

TableColumn* queryresultsTableBase::GetColumn_ID() {

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

void queryresultsTableBase::Set_ID(const long long& in) {

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

void queryresultsTableBase::Get_SEARCHQUERY_ID(long long& out) const {

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

const TableColumn* queryresultsTableBase::GetConstColumn_SEARCHQUERY_ID() const {

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

TableColumn* queryresultsTableBase::GetColumn_SEARCHQUERY_ID() {

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

void queryresultsTableBase::Set_SEARCHQUERY_ID(const long long& in) {

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

void queryresultsTableBase::Get_URLSTAGE_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* queryresultsTableBase::GetConstColumn_URLSTAGE_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* queryresultsTableBase::GetColumn_URLSTAGE_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void queryresultsTableBase::Set_URLSTAGE_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void queryresultsTableBase::Get_URL_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* queryresultsTableBase::GetConstColumn_URL_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* queryresultsTableBase::GetColumn_URL_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void queryresultsTableBase::Set_URL_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void queryresultsTableBase::Get_position(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "position";
      break;
    case DB_IBM_DB2:
      fieldName = "position";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("position");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "position";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* queryresultsTableBase::GetConstColumn_position() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "position";
      break;
    case DB_IBM_DB2:
      fieldName = "position";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("position");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "position";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* queryresultsTableBase::GetColumn_position() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "position";
      break;
    case DB_IBM_DB2:
      fieldName = "position";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("position");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "position";
      break;
    }

    return GetColumnByName(fieldName);
}

void queryresultsTableBase::Set_position(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "position";
      break;
    case DB_IBM_DB2:
      fieldName = "position";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("position");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "position";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void queryresultsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_position(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void queryresultsTableBase::GetBy_position(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    queryresultsTableBase::GetWhereColumnsFor_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(queryresultsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void queryresultsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (searchqueryTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(searchqueryTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinLeftSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SEARCHQUERY_ID("","","","",stmt);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());
    TableDefinition*       joinTableDef       (searchqueryTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (searchqueryTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_SEARCHQUERY_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SEARCHQUERY_ID("","","","",stmt);
}
void queryresultsTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlstagesTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlstagesTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (queryresultsTableBase::GetDefinition_URLSTAGE_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLSTAGE_ID("","","","",stmt);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(queryresultsTableBase::GetDefinition_URLSTAGE_ID());
    TableDefinition*       joinTableDef       (urlstagesTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlstagesTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLSTAGE_ID("","","","",stmt);
}
void queryresultsTableBase::AddInnerJoinLeftSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (queryresultsTableBase::GetDefinition_URL_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinLeftSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URL_ID("","","","",stmt);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (queryresultsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(queryresultsTableBase::GetDefinition_URL_ID());
    TableDefinition*       joinTableDef       (urlsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void queryresultsTableBase::AddInnerJoinRightSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URL_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void queryresultsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_SEARCHQUERY_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_URLSTAGE_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_URLSTAGE_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_URL_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_URL_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_position());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void queryresultsTableBase::GetWhereColumnsFor_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(queryresultsTableBase::GetDefinition_position());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* queryresultsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("queryresults");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* queryresultsTableBase::GetDefinition_SEARCHQUERY_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "SEARCHQUERY_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SEARCHQUERY_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SEARCHQUERY_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("queryresults");
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
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* queryresultsTableBase::GetDefinition_URLSTAGE_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("queryresults");
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
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* queryresultsTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "queryresults";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URL_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("queryresults");
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
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* queryresultsTableBase::GetDefinition_position() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "position";
      createParam.tableName    = "queryresults";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "position";
      createParam.tableName    = "queryresults";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("position");
      createParam.tableName    = tools::StringTools::ToLowerNP("queryresults");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
