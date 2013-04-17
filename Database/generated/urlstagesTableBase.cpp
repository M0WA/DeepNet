#include "urlstagesTableBase.h"

#include "urlstagesTableDefinitionCreateParam.h"
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
    GetConstColumnByName("ID")->Get(out);
}

void urlstagesTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void urlstagesTableBase::Get_URL_ID(long long& out) const {
    GetConstColumnByName("URL_ID")->Get(out);
}

void urlstagesTableBase::Set_URL_ID(const long long& in) {
    GetColumnByName("URL_ID")->Set(in);
}

void urlstagesTableBase::Get_response_code(long long& out) const {
    GetConstColumnByName("response_code")->Get(out);
}

void urlstagesTableBase::Set_response_code(const long long& in) {
    GetColumnByName("response_code")->Set(in);
}

void urlstagesTableBase::Get_content_md5(std::string& out) const {
    GetConstColumnByName("content_md5")->Get(out);
}

void urlstagesTableBase::Set_content_md5(const std::string& in) {
    GetColumnByName("content_md5")->Set(in);
}

void urlstagesTableBase::Get_last_change(struct tm& out) const {
    GetConstColumnByName("last_change")->Get(out);
}

void urlstagesTableBase::Set_last_change(const struct tm& in) {
    GetColumnByName("last_change")->Set(in);
}

void urlstagesTableBase::Get_redirect_count(long long& out) const {
    GetConstColumnByName("redirect_count")->Get(out);
}

void urlstagesTableBase::Set_redirect_count(const long long& in) {
    GetColumnByName("redirect_count")->Set(in);
}

void urlstagesTableBase::Get_download_speed(long long& out) const {
    GetConstColumnByName("download_speed")->Get(out);
}

void urlstagesTableBase::Set_download_speed(const long long& in) {
    GetColumnByName("download_speed")->Set(in);
}

void urlstagesTableBase::Get_upload_speed(long long& out) const {
    GetConstColumnByName("upload_speed")->Get(out);
}

void urlstagesTableBase::Set_upload_speed(const long long& in) {
    GetColumnByName("upload_speed")->Set(in);
}

void urlstagesTableBase::Get_content_length(long long& out) const {
    GetConstColumnByName("content_length")->Get(out);
}

void urlstagesTableBase::Set_content_length(const long long& in) {
    GetColumnByName("content_length")->Set(in);
}

void urlstagesTableBase::Get_content_type(std::string& out) const {
    GetConstColumnByName("content_type")->Get(out);
}

void urlstagesTableBase::Set_content_type(const std::string& in) {
    GetColumnByName("content_type")->Set(in);
}

void urlstagesTableBase::Get_primary_ip(long long& out) const {
    GetConstColumnByName("primary_ip")->Get(out);
}

void urlstagesTableBase::Set_primary_ip(const long long& in) {
    GetColumnByName("primary_ip")->Set(in);
}

void urlstagesTableBase::Get_primary_port(long long& out) const {
    GetConstColumnByName("primary_port")->Get(out);
}

void urlstagesTableBase::Set_primary_port(const long long& in) {
    GetColumnByName("primary_port")->Set(in);
}

void urlstagesTableBase::Get_int_links(long long& out) const {
    GetConstColumnByName("int_links")->Get(out);
}

void urlstagesTableBase::Set_int_links(const long long& in) {
    GetColumnByName("int_links")->Set(in);
}

void urlstagesTableBase::Get_ext_links(long long& out) const {
    GetConstColumnByName("ext_links")->Get(out);
}

void urlstagesTableBase::Set_ext_links(const long long& in) {
    GetColumnByName("ext_links")->Set(in);
}

void urlstagesTableBase::Get_download_time(long long& out) const {
    GetConstColumnByName("download_time")->Get(out);
}

void urlstagesTableBase::Set_download_time(const long long& in) {
    GetColumnByName("download_time")->Set(in);
}

void urlstagesTableBase::Get_html_errors(long long& out) const {
    GetConstColumnByName("html_errors")->Get(out);
}

void urlstagesTableBase::Set_html_errors(const long long& in) {
    GetColumnByName("html_errors")->Set(in);
}

void urlstagesTableBase::Get_found_date(struct tm& out) const {
    GetConstColumnByName("found_date")->Get(out);
}

void urlstagesTableBase::Set_found_date(const struct tm& in) {
    GetColumnByName("found_date")->Set(in);
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
    createParam.columnName         = "ID";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "URL_ID";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = true;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_response_code() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "response_code";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_md5() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "content_md5";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_CHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_last_change() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "last_change";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_redirect_count() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "redirect_count";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_download_speed() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "download_speed";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_upload_speed() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "upload_speed";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_length() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "content_length";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_content_type() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "content_type";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
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
TableColumnDefinition* urlstagesTableBase::GetDefinition_primary_ip() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "primary_ip";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_primary_port() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "primary_port";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_int_links() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "int_links";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_ext_links() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ext_links";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_download_time() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "download_time";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_html_errors() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "html_errors";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = true;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlstagesTableBase::GetDefinition_found_date() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "found_date";
    createParam.tableName          = "urlstages";
    createParam.databaseName       = "contents";
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
