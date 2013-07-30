#include "imagesTableBase.h"

#include "imagesTableDefinitionCreateParam.h"
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



#include "schemesTableBase.h"
#include "topleveldomainsTableBase.h"
#include "subdomainsTableBase.h"
#include "secondleveldomainsTableBase.h"


namespace database {

imagesTableBase::imagesTableBase()
: TableBase(imagesTableBase::CreateTableDefinition()) {
}

imagesTableBase::imagesTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy imagesTableBase");
}

imagesTableBase::~imagesTableBase() {
}

TableDefinition* imagesTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(imagesTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void imagesTableBase::Get_ID(long long& out) const {

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

void imagesTableBase::Set_ID(const long long& in) {

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

void imagesTableBase::Get_SCHEME_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SCHEME_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SCHEME_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SCHEME_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SCHEME_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_SCHEME_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SCHEME_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SCHEME_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SCHEME_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SCHEME_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_TOPLEVELDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("TOPLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_TOPLEVELDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("TOPLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "TOPLEVELDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_SUBDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SUBDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SUBDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SUBDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SUBDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_SUBDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SUBDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SUBDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SUBDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SUBDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_SECONDLEVELDOMAIN_ID(long long& out) const {

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

void imagesTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {

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

void imagesTableBase::Get_port(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "port";
      break;
    case DB_IBM_DB2:
      fieldName = "port";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("port");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "port";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_port(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "port";
      break;
    case DB_IBM_DB2:
      fieldName = "port";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("port");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "port";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_path_part(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path_part";
      break;
    case DB_IBM_DB2:
      fieldName = "path_part";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path_part");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path_part";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_path_part(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path_part";
      break;
    case DB_IBM_DB2:
      fieldName = "path_part";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path_part");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path_part";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_search_part(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "search_part";
      break;
    case DB_IBM_DB2:
      fieldName = "search_part";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("search_part");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "search_part";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_search_part(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "search_part";
      break;
    case DB_IBM_DB2:
      fieldName = "search_part";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("search_part");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "search_part";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_url_md5(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "url_md5";
      break;
    case DB_IBM_DB2:
      fieldName = "url_md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("url_md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "url_md5";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_url_md5(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "url_md5";
      break;
    case DB_IBM_DB2:
      fieldName = "url_md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("url_md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "url_md5";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void imagesTableBase::Get_found_date(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "found_date";
      break;
    case DB_IBM_DB2:
      fieldName = "found_date";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("found_date");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "found_date";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void imagesTableBase::Set_found_date(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "found_date";
      break;
    case DB_IBM_DB2:
      fieldName = "found_date";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("found_date");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "found_date";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void imagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SCHEME_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SCHEME_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SCHEME_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SCHEME_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_port(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_port(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_path_part(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_path_part(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_path_part(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_path_part(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_search_part(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_search_part(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_search_part(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_search_part(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_url_md5(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_url_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_url_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_url_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void imagesTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<imagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    imagesTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(imagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void imagesTableBase::AddInnerJoinLeftSideOn_SCHEME_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = schemesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = schemesTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = imagesTableBase::GetDefinition_SCHEME_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinLeftSideOn_SCHEME_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SCHEME_ID("","","","",stmt);
}

void imagesTableBase::AddInnerJoinRightSideOn_SCHEME_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = imagesTableBase::GetDefinition_SCHEME_ID();
    TableDefinition*       joinTableDef        = schemesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = schemesTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinRightSideOn_SCHEME_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SCHEME_ID("","","","",stmt);
}
void imagesTableBase::AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = topleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = topleveldomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID("","","","",stmt);
}

void imagesTableBase::AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    TableDefinition*       joinTableDef        = topleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = topleveldomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID("","","","",stmt);
}
void imagesTableBase::AddInnerJoinLeftSideOn_SUBDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = subdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = subdomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = imagesTableBase::GetDefinition_SUBDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinLeftSideOn_SUBDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SUBDOMAIN_ID("","","","",stmt);
}

void imagesTableBase::AddInnerJoinRightSideOn_SUBDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = imagesTableBase::GetDefinition_SUBDOMAIN_ID();
    TableDefinition*       joinTableDef        = subdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = subdomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinRightSideOn_SUBDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SUBDOMAIN_ID("","","","",stmt);
}
void imagesTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = secondleveldomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}

void imagesTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = imagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableDefinition*       joinTableDef        = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = secondleveldomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void imagesTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void imagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SCHEME_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SCHEME_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SCHEME_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SCHEME_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SUBDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SUBDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_port();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_port();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_path_part(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_path_part();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_path_part(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_path_part();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_search_part(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_search_part();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_search_part(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_search_part();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_url_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_url_md5();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_url_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_url_md5();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_found_date();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void imagesTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = imagesTableBase::GetDefinition_found_date();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* imagesTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "ID";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
TableColumnDefinition* imagesTableBase::GetDefinition_SCHEME_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SCHEME_ID";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SCHEME_ID";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SCHEME_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "TOPLEVELDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "TOPLEVELDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("TOPLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* imagesTableBase::GetDefinition_SUBDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SUBDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SUBDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SUBDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* imagesTableBase::GetDefinition_port() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "port";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "port";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("port");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
TableColumnDefinition* imagesTableBase::GetDefinition_path_part() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "path_part";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "path_part";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("path_part");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
TableColumnDefinition* imagesTableBase::GetDefinition_search_part() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "search_part";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "search_part";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("search_part");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
TableColumnDefinition* imagesTableBase::GetDefinition_url_md5() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "url_md5";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "url_md5";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("url_md5");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
TableColumnDefinition* imagesTableBase::GetDefinition_found_date() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "found_date";
      createParam.tableName    = "images";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "found_date";
      createParam.tableName    = "images";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("found_date");
      createParam.tableName    = tools::StringTools::ToLowerNP("images");
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
