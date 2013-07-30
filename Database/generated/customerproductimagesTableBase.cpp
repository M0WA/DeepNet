#include "customerproductimagesTableBase.h"

#include "customerproductimagesTableDefinitionCreateParam.h"
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



#include "customerproductsTableBase.h"


namespace database {

customerproductimagesTableBase::customerproductimagesTableBase()
: TableBase(customerproductimagesTableBase::CreateTableDefinition()) {
}

customerproductimagesTableBase::customerproductimagesTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customerproductimagesTableBase");
}

customerproductimagesTableBase::~customerproductimagesTableBase() {
}

TableDefinition* customerproductimagesTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customerproductimagesTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customerproductimagesTableBase::Get_ID(long long& out) const {

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

void customerproductimagesTableBase::Set_ID(const long long& in) {

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

void customerproductimagesTableBase::Get_PRODUCT_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PRODUCT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PRODUCT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PRODUCT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PRODUCT_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerproductimagesTableBase::Set_PRODUCT_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PRODUCT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PRODUCT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PRODUCT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PRODUCT_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerproductimagesTableBase::Get_imageUrl(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "imageUrl";
      break;
    case DB_IBM_DB2:
      fieldName = "imageUrl";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("imageUrl");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "imageUrl";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerproductimagesTableBase::Set_imageUrl(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "imageUrl";
      break;
    case DB_IBM_DB2:
      fieldName = "imageUrl";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("imageUrl");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "imageUrl";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customerproductimagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductimagesTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductimagesTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductimagesTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductimagesTableBase::GetBy_imageUrl(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_imageUrl(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductimagesTableBase::GetBy_imageUrl(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerproductimagesTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductimagesTableBase::GetWhereColumnsFor_imageUrl(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductimagesTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customerproductimagesTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerproductsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerproductsTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customerproductimagesTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerproductimagesTableBase::GetDefinition_PRODUCT_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductimagesTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_PRODUCT_ID("","","","",stmt);
}

void customerproductimagesTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerproductimagesTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerproductimagesTableBase::GetDefinition_PRODUCT_ID();
    TableDefinition*       joinTableDef        = customerproductsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerproductsTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductimagesTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_PRODUCT_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customerproductimagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproductimagesTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerproductimagesTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_PRODUCT_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproductimagesTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_PRODUCT_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerproductimagesTableBase::GetWhereColumnsFor_imageUrl(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_imageUrl();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerproductimagesTableBase::GetWhereColumnsFor_imageUrl(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerproductimagesTableBase::GetDefinition_imageUrl();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customerproductimagesTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductimages");
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
TableColumnDefinition* customerproductimagesTableBase::GetDefinition_PRODUCT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("PRODUCT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductimages");
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
TableColumnDefinition* customerproductimagesTableBase::GetDefinition_imageUrl() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "imageUrl";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "imageUrl";
      createParam.tableName    = "customerproductimages";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("imageUrl");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductimages");
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

}
