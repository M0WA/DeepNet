#include "urlstagesTableBase.h"

#include "urlstagesTableDefinitionCreateParam.h"
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



#include "urlsTableBase.h"


namespace database {

urlstagesTableBase::urlstagesTableBase()
: TableBase(urlstagesTableBase::CreateTableDefinition()) {
}

urlstagesTableBase::urlstagesTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy urlstagesTableBase");
}

urlstagesTableBase::~urlstagesTableBase() {
}

TableDefinition* urlstagesTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(urlstagesTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void urlstagesTableBase::Get_ID(long long& out) const {

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

void urlstagesTableBase::Set_ID(const long long& in) {

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

void urlstagesTableBase::Get_URL_ID(long long& out) const {

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

void urlstagesTableBase::Set_URL_ID(const long long& in) {

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

void urlstagesTableBase::Get_response_code(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "response_code";
      break;
    case DB_IBM_DB2:
      fieldName = "response_code";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("response_code");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "response_code";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_response_code(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "response_code";
      break;
    case DB_IBM_DB2:
      fieldName = "response_code";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("response_code");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "response_code";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_content_md5(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_md5";
      break;
    case DB_IBM_DB2:
      fieldName = "content_md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_md5";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_content_md5(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_md5";
      break;
    case DB_IBM_DB2:
      fieldName = "content_md5";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_md5");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_md5";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_last_change(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "last_change";
      break;
    case DB_IBM_DB2:
      fieldName = "last_change";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("last_change");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "last_change";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_last_change(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "last_change";
      break;
    case DB_IBM_DB2:
      fieldName = "last_change";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("last_change");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "last_change";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_redirect_count(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "redirect_count";
      break;
    case DB_IBM_DB2:
      fieldName = "redirect_count";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("redirect_count");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "redirect_count";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_redirect_count(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "redirect_count";
      break;
    case DB_IBM_DB2:
      fieldName = "redirect_count";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("redirect_count");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "redirect_count";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_download_speed(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "download_speed";
      break;
    case DB_IBM_DB2:
      fieldName = "download_speed";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("download_speed");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "download_speed";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_download_speed(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "download_speed";
      break;
    case DB_IBM_DB2:
      fieldName = "download_speed";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("download_speed");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "download_speed";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_upload_speed(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "upload_speed";
      break;
    case DB_IBM_DB2:
      fieldName = "upload_speed";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("upload_speed");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "upload_speed";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_upload_speed(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "upload_speed";
      break;
    case DB_IBM_DB2:
      fieldName = "upload_speed";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("upload_speed");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "upload_speed";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_content_length(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_length";
      break;
    case DB_IBM_DB2:
      fieldName = "content_length";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_length");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_length";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_content_length(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_length";
      break;
    case DB_IBM_DB2:
      fieldName = "content_length";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_length");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_length";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_content_type(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_type";
      break;
    case DB_IBM_DB2:
      fieldName = "content_type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_type";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_content_type(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "content_type";
      break;
    case DB_IBM_DB2:
      fieldName = "content_type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("content_type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "content_type";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_primary_ip(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "primary_ip";
      break;
    case DB_IBM_DB2:
      fieldName = "primary_ip";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("primary_ip");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "primary_ip";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_primary_ip(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "primary_ip";
      break;
    case DB_IBM_DB2:
      fieldName = "primary_ip";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("primary_ip");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "primary_ip";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_primary_port(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "primary_port";
      break;
    case DB_IBM_DB2:
      fieldName = "primary_port";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("primary_port");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "primary_port";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_primary_port(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "primary_port";
      break;
    case DB_IBM_DB2:
      fieldName = "primary_port";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("primary_port");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "primary_port";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_int_links(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "int_links";
      break;
    case DB_IBM_DB2:
      fieldName = "int_links";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("int_links");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "int_links";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_int_links(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "int_links";
      break;
    case DB_IBM_DB2:
      fieldName = "int_links";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("int_links");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "int_links";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_ext_links(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ext_links";
      break;
    case DB_IBM_DB2:
      fieldName = "ext_links";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ext_links");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ext_links";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_ext_links(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "ext_links";
      break;
    case DB_IBM_DB2:
      fieldName = "ext_links";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("ext_links");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "ext_links";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_download_time(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "download_time";
      break;
    case DB_IBM_DB2:
      fieldName = "download_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("download_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "download_time";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_download_time(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "download_time";
      break;
    case DB_IBM_DB2:
      fieldName = "download_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("download_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "download_time";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_html_errors(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "html_errors";
      break;
    case DB_IBM_DB2:
      fieldName = "html_errors";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("html_errors");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "html_errors";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void urlstagesTableBase::Set_html_errors(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "html_errors";
      break;
    case DB_IBM_DB2:
      fieldName = "html_errors";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("html_errors");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "html_errors";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlstagesTableBase::Get_found_date(struct tm& out) const {

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

void urlstagesTableBase::Set_found_date(const struct tm& in) {

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
void urlstagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_response_code(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_response_code(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_response_code(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_response_code(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_md5(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_md5(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_last_change(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_last_change(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_last_change(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_last_change(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_redirect_count(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_redirect_count(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_redirect_count(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_redirect_count(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_download_speed(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_download_speed(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_download_speed(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_download_speed(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_upload_speed(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_upload_speed(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_upload_speed(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_upload_speed(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_length(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_length(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_length(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_length(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_type(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_content_type(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_content_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_primary_ip(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_primary_ip(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_primary_ip(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_primary_ip(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_primary_port(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_primary_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_primary_port(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_primary_port(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_int_links(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_int_links(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_int_links(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_int_links(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_ext_links(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_ext_links(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_ext_links(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_ext_links(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_download_time(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_download_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_download_time(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_download_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_html_errors(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_html_errors(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_html_errors(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_html_errors(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void urlstagesTableBase::GetBy_found_date(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlstagesTableBase::GetWhereColumnsFor_found_date(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(urlstagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void urlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlstagesTableBase::GetDefinition_URL_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URL_ID("","","","",stmt);
}

void urlstagesTableBase::AddInnerJoinRightSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlstagesTableBase::GetDefinition_URL_ID();
    TableDefinition*       joinTableDef        = urlsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlstagesTableBase::AddInnerJoinRightSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URL_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void urlstagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_URL_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_URL_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_response_code(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_response_code();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_response_code(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_response_code();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_md5();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_md5(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_md5();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_last_change(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_last_change();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_last_change(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_last_change();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_redirect_count(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_redirect_count();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_redirect_count(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_redirect_count();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_download_speed(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_download_speed();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_download_speed(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_download_speed();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_upload_speed(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_upload_speed();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_upload_speed(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_upload_speed();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_length(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_length();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_length(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_length();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_type();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_content_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_content_type();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_primary_ip(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_primary_ip();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_primary_ip(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_primary_ip();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_primary_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_primary_port();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_primary_port(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_primary_port();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_int_links(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_int_links();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_int_links(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_int_links();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_ext_links(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_ext_links();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_ext_links(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_ext_links();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_download_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_download_time();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_download_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_download_time();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_html_errors(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_html_errors();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_html_errors(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_html_errors();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_found_date();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void urlstagesTableBase::GetWhereColumnsFor_found_date(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = urlstagesTableBase::GetDefinition_found_date();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* urlstagesTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URL_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_response_code() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "response_code";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "response_code";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("response_code");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_md5() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "content_md5";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "content_md5";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("content_md5");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_CHAR;
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_last_change() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "last_change";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "last_change";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("last_change");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_redirect_count() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "redirect_count";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "redirect_count";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("redirect_count");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_download_speed() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "download_speed";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "download_speed";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("download_speed");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_BIGINT;
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_upload_speed() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "upload_speed";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "upload_speed";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("upload_speed");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_BIGINT;
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_length() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "content_length";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "content_length";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("content_length");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_BIGINT;
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "content_type";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "content_type";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("content_type");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_primary_ip() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "primary_ip";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "primary_ip";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("primary_ip");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_BIGINT;
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_primary_port() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "primary_port";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "primary_port";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("primary_port");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_int_links() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "int_links";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "int_links";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("int_links");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_ext_links() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "ext_links";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ext_links";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ext_links");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_download_time() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "download_time";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "download_time";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("download_time");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_html_errors() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "html_errors";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "html_errors";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("html_errors");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_found_date() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "contents";
      createParam.columnName   = "found_date";
      createParam.tableName    = "urlstages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "found_date";
      createParam.tableName    = "urlstages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("found_date");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlstages");
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
