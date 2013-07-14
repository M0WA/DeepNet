#include "dockeyposTableBase.h"

#include "dockeyposTableDefinitionCreateParam.h"
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

#include <NotImplementedException.h>



#include "dockeyTableBase.h"


namespace database {

dockeyposTableBase::dockeyposTableBase()
: TableBase(dockeyposTableBase::CreateTableDefinition()) {
}

dockeyposTableBase::dockeyposTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dockeyposTableBase");
}

dockeyposTableBase::~dockeyposTableBase() {
}

TableDefinition* dockeyposTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dockeyposTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dockeyposTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void dockeyposTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void dockeyposTableBase::Get_DOCKEY_ID(long long& out) const {
    GetConstColumnByName("DOCKEY_ID")->Get(out);
}

void dockeyposTableBase::Set_DOCKEY_ID(const long long& in) {
    GetColumnByName("DOCKEY_ID")->Set(in);
}

void dockeyposTableBase::Get_paragraph(long long& out) const {
    GetConstColumnByName("paragraph")->Get(out);
}

void dockeyposTableBase::Set_paragraph(const long long& in) {
    GetColumnByName("paragraph")->Set(in);
}

void dockeyposTableBase::Get_position(long long& out) const {
    GetConstColumnByName("position")->Get(out);
}

void dockeyposTableBase::Set_position(const long long& in) {
    GetColumnByName("position")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dockeyposTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_DOCKEY_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_DOCKEY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_DOCKEY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_DOCKEY_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_paragraph(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_paragraph(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_paragraph(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_paragraph(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_position(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dockeyposTableBase::GetBy_position(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dockeyposTableBase::GetWhereColumnsFor_position(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dockeyposTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void dockeyposTableBase::AddInnerJoinLeftSideOn_DOCKEY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dockeyTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = dockeyposTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dockeyposTableBase::GetDefinition_DOCKEY_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyposTableBase::AddInnerJoinLeftSideOn_DOCKEY_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DOCKEY_ID("","","","",stmt);
}

void dockeyposTableBase::AddInnerJoinRightSideOn_DOCKEY_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dockeyposTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dockeyposTableBase::GetDefinition_DOCKEY_ID();
    TableDefinition*       joinTableDef        = dockeyTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dockeyTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void dockeyposTableBase::AddInnerJoinRightSideOn_DOCKEY_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DOCKEY_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void dockeyposTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_DOCKEY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_DOCKEY_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_DOCKEY_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_DOCKEY_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_paragraph(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_paragraph();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_paragraph(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_paragraph();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_position();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dockeyposTableBase::GetWhereColumnsFor_position(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dockeyposTableBase::GetDefinition_position();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dockeyposTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "dockeypos";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
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
TableColumnDefinition* dockeyposTableBase::GetDefinition_DOCKEY_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "DOCKEY_ID";
    createParam.tableName          = "dockeypos";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
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
TableColumnDefinition* dockeyposTableBase::GetDefinition_paragraph() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "paragraph";
    createParam.tableName          = "dockeypos";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dockeyposTableBase::GetDefinition_position() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "position";
    createParam.tableName          = "dockeypos";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
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
