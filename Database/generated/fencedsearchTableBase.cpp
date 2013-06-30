#include "fencedsearchTableBase.h"

#include "fencedsearchTableDefinitionCreateParam.h"
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



#include "dataminingcustomerTableBase.h"
#include "secondleveldomainsTableBase.h"


namespace database {

fencedsearchTableBase::fencedsearchTableBase()
: TableBase(fencedsearchTableBase::CreateTableDefinition()) {
}

fencedsearchTableBase::fencedsearchTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy fencedsearchTableBase");
}

fencedsearchTableBase::~fencedsearchTableBase() {
}

TableDefinition* fencedsearchTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(fencedsearchTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void fencedsearchTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void fencedsearchTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void fencedsearchTableBase::Get_CUSTOMER_ID(long long& out) const {
    GetConstColumnByName("CUSTOMER_ID")->Get(out);
}

void fencedsearchTableBase::Set_CUSTOMER_ID(const long long& in) {
    GetColumnByName("CUSTOMER_ID")->Set(in);
}

void fencedsearchTableBase::Get_SECONDLEVELDOMAIN_ID(long long& out) const {
    GetConstColumnByName("SECONDLEVELDOMAIN_ID")->Get(out);
}

void fencedsearchTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {
    GetColumnByName("SECONDLEVELDOMAIN_ID")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void fencedsearchTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void fencedsearchTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void fencedsearchTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void fencedsearchTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void fencedsearchTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void fencedsearchTableBase::GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(fencedsearchTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void fencedsearchTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = dataminingcustomerTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = dataminingcustomerTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = fencedsearchTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = fencedsearchTableBase::GetDefinition_CUSTOMER_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void fencedsearchTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMER_ID("","","","",stmt);
}

void fencedsearchTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = fencedsearchTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = fencedsearchTableBase::GetDefinition_CUSTOMER_ID();
    TableDefinition*       joinTableDef        = dataminingcustomerTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = dataminingcustomerTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void fencedsearchTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMER_ID("","","","",stmt);
}
void fencedsearchTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = secondleveldomainsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = fencedsearchTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void fencedsearchTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}

void fencedsearchTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = fencedsearchTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableDefinition*       joinTableDef        = secondleveldomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = secondleveldomainsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void fencedsearchTableBase::AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void fencedsearchTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void fencedsearchTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_CUSTOMER_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_CUSTOMER_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* fencedsearchTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "fencedsearch";
    createParam.databaseName       = "datamining";
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
TableColumnDefinition* fencedsearchTableBase::GetDefinition_CUSTOMER_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "CUSTOMER_ID";
    createParam.tableName          = "fencedsearch";
    createParam.databaseName       = "datamining";
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
TableColumnDefinition* fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "SECONDLEVELDOMAIN_ID";
    createParam.tableName          = "fencedsearch";
    createParam.databaseName       = "datamining";
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

}
