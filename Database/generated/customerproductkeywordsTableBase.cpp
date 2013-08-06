#include "customerproductkeywordsTableBase.h"

#include "customerproductkeywordsTableDefinitionCreateParam.h"
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
#include "dictTableBase.h"


namespace database {

customerproductkeywordsTableBase::customerproductkeywordsTableBase()
: TableBase(customerproductkeywordsTableBase::CreateTableDefinition()) {
}

customerproductkeywordsTableBase::customerproductkeywordsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customerproductkeywordsTableBase");
}

customerproductkeywordsTableBase::~customerproductkeywordsTableBase() {
}

TableDefinition* customerproductkeywordsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customerproductkeywordsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customerproductkeywordsTableBase::Get_ID(long long& out) const {

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

const TableColumn* customerproductkeywordsTableBase::GetConstColumn_ID() const {

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

TableColumn* customerproductkeywordsTableBase::GetColumn_ID() {

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

void customerproductkeywordsTableBase::Set_ID(const long long& in) {

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

void customerproductkeywordsTableBase::Get_PRODUCT_ID(long long& out) const {

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

const TableColumn* customerproductkeywordsTableBase::GetConstColumn_PRODUCT_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* customerproductkeywordsTableBase::GetColumn_PRODUCT_ID() {

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

    return GetColumnByName(fieldName);
}

void customerproductkeywordsTableBase::Set_PRODUCT_ID(const long long& in) {

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

void customerproductkeywordsTableBase::Get_DICT_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customerproductkeywordsTableBase::GetConstColumn_DICT_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customerproductkeywordsTableBase::GetColumn_DICT_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customerproductkeywordsTableBase::Set_DICT_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customerproductkeywordsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductkeywordsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductkeywordsTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductkeywordsTableBase::GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_PRODUCT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductkeywordsTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerproductkeywordsTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerproductkeywordsTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerproductkeywordsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customerproductkeywordsTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerproductsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerproductsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customerproductkeywordsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductkeywordsTableBase::AddInnerJoinLeftSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_PRODUCT_ID("","","","",stmt);
}

void customerproductkeywordsTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerproductkeywordsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());
    TableDefinition*       joinTableDef       (customerproductsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerproductsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductkeywordsTableBase::AddInnerJoinRightSideOn_PRODUCT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_PRODUCT_ID("","","","",stmt);
}
void customerproductkeywordsTableBase::AddInnerJoinLeftSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (dictTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(dictTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customerproductkeywordsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerproductkeywordsTableBase::GetDefinition_DICT_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductkeywordsTableBase::AddInnerJoinLeftSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DICT_ID("","","","",stmt);
}

void customerproductkeywordsTableBase::AddInnerJoinRightSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerproductkeywordsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerproductkeywordsTableBase::GetDefinition_DICT_ID());
    TableDefinition*       joinTableDef       (dictTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (dictTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerproductkeywordsTableBase::AddInnerJoinRightSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DICT_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customerproductkeywordsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void customerproductkeywordsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void customerproductkeywordsTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void customerproductkeywordsTableBase::GetWhereColumnsFor_PRODUCT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void customerproductkeywordsTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_DICT_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void customerproductkeywordsTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerproductkeywordsTableBase::GetDefinition_DICT_ID());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customerproductkeywordsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductkeywords");
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
TableColumnDefinition* customerproductkeywordsTableBase::GetDefinition_PRODUCT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "PRODUCT_ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("PRODUCT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductkeywords");
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
TableColumnDefinition* customerproductkeywordsTableBase::GetDefinition_DICT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "DICT_ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "DICT_ID";
      createParam.tableName    = "customerproductkeywords";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("DICT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerproductkeywords");
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

}
