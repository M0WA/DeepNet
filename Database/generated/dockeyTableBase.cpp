#include "dockeyTableBase.h"

#include "dockeyTableDefinitionCreateParam.h"
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



#include "dictTableBase.h"
#include "urlstagesTableBase.h"


namespace database {

dockeyTableBase::dockeyTableBase()
: TableBase(dockeyTableBase::CreateTableDefinition()) {
}

dockeyTableBase::dockeyTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dockeyTableBase");
}

dockeyTableBase::~dockeyTableBase() {
}

TableDefinition* dockeyTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dockeyTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dockeyTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void dockeyTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void dockeyTableBase::Get_DICT_ID(long long& out) const {
    GetConstColumnByName("DICT_ID")->Get(out);
}

void dockeyTableBase::Set_DICT_ID(const long long& in) {
    GetColumnByName("DICT_ID")->Set(in);
}

void dockeyTableBase::Get_URLSTAGE_ID(long long& out) const {
    GetConstColumnByName("URLSTAGE_ID")->Get(out);
}

void dockeyTableBase::Set_URLSTAGE_ID(const long long& in) {
    GetColumnByName("URLSTAGE_ID")->Set(in);
}

void dockeyTableBase::Get_occurrence(long long& out) const {
    GetConstColumnByName("occurrence")->Get(out);
}

void dockeyTableBase::Set_occurrence(const long long& in) {
    GetColumnByName("occurrence")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dockeyTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void dockeyTableBase::AddInnerJoinLeftSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dictTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dictTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dockeyTableBase::GetDefinition_DICT_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyTableBase::AddInnerJoinLeftSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DICT_ID("","","","",stmt);
}

void dockeyTableBase::AddInnerJoinRightSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dockeyTableBase::GetDefinition_DICT_ID();
    TableDefinition*       joinTableDef        = dictTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dictTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyTableBase::AddInnerJoinRightSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DICT_ID("","","","",stmt);
}
void dockeyTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = urlstagesTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dockeyTableBase::GetDefinition_URLSTAGE_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLSTAGE_ID("","","","",stmt);
}

void dockeyTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dockeyTableBase::GetDefinition_URLSTAGE_ID();
    TableDefinition*       joinTableDef        = urlstagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = urlstagesTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLSTAGE_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void dockeyTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_DICT_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_DICT_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_URLSTAGE_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_URLSTAGE_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_occurrence();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyTableBase::GetDefinition_occurrence();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dockeyTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "dockey";
    createParam.databaseName       = "lexicon";
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
TableColumnDefinition* dockeyTableBase::GetDefinition_DICT_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "DICT_ID";
    createParam.tableName          = "dockey";
    createParam.databaseName       = "lexicon";
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
TableColumnDefinition* dockeyTableBase::GetDefinition_URLSTAGE_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "URLSTAGE_ID";
    createParam.tableName          = "dockey";
    createParam.databaseName       = "lexicon";
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
TableColumnDefinition* dockeyTableBase::GetDefinition_occurrence() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "occurrence";
    createParam.tableName          = "dockey";
    createParam.databaseName       = "lexicon";
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = true;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
