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

#include <StringTools.h>
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

const TableColumn* dockeyposTableBase::GetConstColumn_ID() const {

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

TableColumn* dockeyposTableBase::GetColumn_ID() {

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

void dockeyposTableBase::Set_ID(const long long& in) {

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

void dockeyposTableBase::Get_DOCKEY_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DOCKEY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DOCKEY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DOCKEY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DOCKEY_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* dockeyposTableBase::GetConstColumn_DOCKEY_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DOCKEY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DOCKEY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DOCKEY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DOCKEY_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* dockeyposTableBase::GetColumn_DOCKEY_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DOCKEY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DOCKEY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DOCKEY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DOCKEY_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void dockeyposTableBase::Set_DOCKEY_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DOCKEY_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DOCKEY_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DOCKEY_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DOCKEY_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void dockeyposTableBase::Get_paragraph(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "paragraph";
      break;
    case DB_IBM_DB2:
      fieldName = "paragraph";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("paragraph");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "paragraph";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* dockeyposTableBase::GetConstColumn_paragraph() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "paragraph";
      break;
    case DB_IBM_DB2:
      fieldName = "paragraph";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("paragraph");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "paragraph";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* dockeyposTableBase::GetColumn_paragraph() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "paragraph";
      break;
    case DB_IBM_DB2:
      fieldName = "paragraph";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("paragraph");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "paragraph";
      break;
    }

    return GetColumnByName(fieldName);
}

void dockeyposTableBase::Set_paragraph(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "paragraph";
      break;
    case DB_IBM_DB2:
      fieldName = "paragraph";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("paragraph");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "paragraph";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void dockeyposTableBase::Get_position(long long& out) const {

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

const TableColumn* dockeyposTableBase::GetConstColumn_position() const {

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

TableColumn* dockeyposTableBase::GetColumn_position() {

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

void dockeyposTableBase::Set_position(const long long& in) {

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
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "ID";
      createParam.tableName    = "dockeypos";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "dockeypos";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("dockeypos");
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
TableColumnDefinition* dockeyposTableBase::GetDefinition_DOCKEY_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "DOCKEY_ID";
      createParam.tableName    = "dockeypos";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "DOCKEY_ID";
      createParam.tableName    = "dockeypos";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("DOCKEY_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("dockeypos");
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
TableColumnDefinition* dockeyposTableBase::GetDefinition_paragraph() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "paragraph";
      createParam.tableName    = "dockeypos";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "paragraph";
      createParam.tableName    = "dockeypos";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("paragraph");
      createParam.tableName    = tools::StringTools::ToLowerNP("dockeypos");
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
TableColumnDefinition* dockeyposTableBase::GetDefinition_position() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "position";
      createParam.tableName    = "dockeypos";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "position";
      createParam.tableName    = "dockeypos";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("position");
      createParam.tableName    = tools::StringTools::ToLowerNP("dockeypos");
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

}
