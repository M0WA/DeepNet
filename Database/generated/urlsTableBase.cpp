#include "urlsTableBase.h"

#include "urlsTableDefinitionCreateParam.h"
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
#include "urlpathpartsTableBase.h"
#include "urlsearchpartsTableBase.h"


namespace database {

urlsTableBase::urlsTableBase()
: TableBase(urlsTableBase::CreateTableDefinition()) {
}

urlsTableBase::urlsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy urlsTableBase");
}

urlsTableBase::~urlsTableBase() {
}

TableDefinition* urlsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(urlsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void urlsTableBase::Get_ID(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_ID() const {

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

TableColumn* urlsTableBase::GetColumn_ID() {

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

void urlsTableBase::Set_ID(const long long& in) {

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

void urlsTableBase::Get_SCHEME_ID(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_SCHEME_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_SCHEME_ID() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_SCHEME_ID(const long long& in) {

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

void urlsTableBase::Get_TOPLEVELDOMAIN_ID(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_TOPLEVELDOMAIN_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_TOPLEVELDOMAIN_ID() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_TOPLEVELDOMAIN_ID(const long long& in) {

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

void urlsTableBase::Get_SUBDOMAIN_ID(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_SUBDOMAIN_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_SUBDOMAIN_ID() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_SUBDOMAIN_ID(const long long& in) {

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

void urlsTableBase::Get_SECONDLEVELDOMAIN_ID(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_SECONDLEVELDOMAIN_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_SECONDLEVELDOMAIN_ID() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {

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

void urlsTableBase::Get_port(long long& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_port() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_port() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_port(const long long& in) {

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

void urlsTableBase::Get_URLPATHPART_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlsTableBase::GetConstColumn_URLPATHPART_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_URLPATHPART_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_URLPATHPART_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlsTableBase::Get_URLSEARCHPART_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSEARCHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSEARCHPART_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlsTableBase::GetConstColumn_URLSEARCHPART_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSEARCHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSEARCHPART_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_URLSEARCHPART_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSEARCHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSEARCHPART_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_URLSEARCHPART_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSEARCHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSEARCHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSEARCHPART_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlsTableBase::Get_found_date(struct tm& out) const {

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

const TableColumn* urlsTableBase::GetConstColumn_found_date() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* urlsTableBase::GetColumn_found_date() {

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

    return GetColumnByName(fieldName);
}

void urlsTableBase::Set_found_date(const struct tm& in) {

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
void urlsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SCHEME_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SCHEME_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SCHEME_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SCHEME_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_port(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_port(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_URLPATHPART_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_URLPATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_URLPATHPART_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_URLPATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_URLSEARCHPART_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_URLSEARCHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_URLSEARCHPART_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_URLSEARCHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlsTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlsTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void urlsTableBase::AddInnerJoinLeftSideOn_SCHEME_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = schemesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = schemesTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_SCHEME_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_SCHEME_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SCHEME_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_SCHEME_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_SCHEME_ID();
    TableDefinition*       joinTableDef        = schemesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = schemesTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_SCHEME_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SCHEME_ID("","","","",stmt);
}
void urlsTableBase::AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = topleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = topleveldomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    TableDefinition*       joinTableDef        = topleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = topleveldomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID("","","","",stmt);
}
void urlsTableBase::AddInnerJoinLeftSideOn_SUBDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = subdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = subdomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_SUBDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_SUBDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SUBDOMAIN_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_SUBDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_SUBDOMAIN_ID();
    TableDefinition*       joinTableDef        = subdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = subdomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_SUBDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SUBDOMAIN_ID("","","","",stmt);
}
void urlsTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = secondleveldomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableDefinition*       joinTableDef        = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = secondleveldomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}
void urlsTableBase::AddInnerJoinLeftSideOn_URLPATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlpathpartsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlpathpartsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_URLPATHPART_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_URLPATHPART_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLPATHPART_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_URLPATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_URLPATHPART_ID();
    TableDefinition*       joinTableDef        = urlpathpartsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlpathpartsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_URLPATHPART_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLPATHPART_ID("","","","",stmt);
}
void urlsTableBase::AddInnerJoinLeftSideOn_URLSEARCHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsearchpartsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsearchpartsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_URLSEARCHPART_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinLeftSideOn_URLSEARCHPART_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLSEARCHPART_ID("","","","",stmt);
}

void urlsTableBase::AddInnerJoinRightSideOn_URLSEARCHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_URLSEARCHPART_ID();
    TableDefinition*       joinTableDef        = urlsearchpartsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsearchpartsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlsTableBase::AddInnerJoinRightSideOn_URLSEARCHPART_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLSEARCHPART_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void urlsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SCHEME_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SCHEME_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SCHEME_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SCHEME_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SUBDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SUBDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_port();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_port();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_URLPATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_URLPATHPART_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_URLPATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_URLPATHPART_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_URLSEARCHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_URLSEARCHPART_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_URLSEARCHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_URLSEARCHPART_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_found_date();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlsTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlsTableBase::GetDefinition_found_date();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* urlsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_SCHEME_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SCHEME_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SCHEME_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SCHEME_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_TOPLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "TOPLEVELDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "TOPLEVELDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("TOPLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_SUBDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SUBDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SUBDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SUBDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_port() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "port";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "port";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("port");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlsTableBase::GetDefinition_URLPATHPART_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "URLPATHPART_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLPATHPART_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLPATHPART_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_URLSEARCHPART_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "URLSEARCHPART_ID";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLSEARCHPART_ID";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLSEARCHPART_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
TableColumnDefinition* urlsTableBase::GetDefinition_found_date() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "found_date";
      createParam.tableName    = "urls";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "found_date";
      createParam.tableName    = "urls";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("found_date");
      createParam.tableName    = tools::StringTools::ToLowerNP("urls");
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
