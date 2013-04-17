#include "customermatchcriteriagrouptypeTableBase.h"

#include "customermatchcriteriagrouptypeTableDefinitionCreateParam.h"
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



#include "customermatchcriteriaTableBase.h"


namespace database {

customermatchcriteriagrouptypeTableBase::customermatchcriteriagrouptypeTableBase()
: TableBase(customermatchcriteriagrouptypeTableBase::CreateTableDefinition()) {
}

customermatchcriteriagrouptypeTableBase::customermatchcriteriagrouptypeTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customermatchcriteriagrouptypeTableBase");
}

customermatchcriteriagrouptypeTableBase::~customermatchcriteriagrouptypeTableBase() {
}

TableDefinition* customermatchcriteriagrouptypeTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customermatchcriteriagrouptypeTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void customermatchcriteriagrouptypeTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_CUSTOMERMATCHCRITERIA_ID(long long& out) const {
    GetConstColumnByName("CUSTOMERMATCHCRITERIA_ID")->Get(out);
}

void customermatchcriteriagrouptypeTableBase::Set_CUSTOMERMATCHCRITERIA_ID(const long long& in) {
    GetColumnByName("CUSTOMERMATCHCRITERIA_ID")->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_type(long long& out) const {
    GetConstColumnByName("type")->Get(out);
}

void customermatchcriteriagrouptypeTableBase::Set_type(const long long& in) {
    GetColumnByName("type")->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_groupPosition(long long& out) const {
    GetConstColumnByName("groupPosition")->Get(out);
}

void customermatchcriteriagrouptypeTableBase::Set_groupPosition(const long long& in) {
    GetColumnByName("groupPosition")->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_isPrimaryKey(long long& out) const {
    GetConstColumnByName("isPrimaryKey")->Get(out);
}

void customermatchcriteriagrouptypeTableBase::Set_isPrimaryKey(const long long& in) {
    GetColumnByName("isPrimaryKey")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_groupPosition(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_groupPosition(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_isPrimaryKey(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriagrouptypeTableBase::GetBy_isPrimaryKey(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customermatchcriteriaTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customermatchcriteriaTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customermatchcriteriagrouptypeTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID("","","","",stmt);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customermatchcriteriagrouptypeTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID();
    TableDefinition*       joinTableDef        = customermatchcriteriaTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customermatchcriteriaTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_type();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_type();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "customermatchcriteriagrouptype";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CUSTOMERMATCHCRITERIA_ID";
    createParam.tableName          = "customermatchcriteriagrouptype";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "type";
    createParam.tableName          = "customermatchcriteriagrouptype";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "groupPosition";
    createParam.tableName          = "customermatchcriteriagrouptype";
    createParam.databaseName       = "commercesearch";
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "isPrimaryKey";
    createParam.tableName          = "customermatchcriteriagrouptype";
    createParam.databaseName       = "commercesearch";
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
