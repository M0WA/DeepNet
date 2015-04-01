#include "customerdomainblacklistTableBase.h"

#include "customerdomainblacklistTableDefinitionCreateParam.h"
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



#include "customerdomainsTableBase.h"


namespace database {

customerdomainblacklistTableBase::customerdomainblacklistTableBase()
: TableBase(customerdomainblacklistTableBase::CreateTableDefinition()) {
}

customerdomainblacklistTableBase::customerdomainblacklistTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customerdomainblacklistTableBase");
}

customerdomainblacklistTableBase::~customerdomainblacklistTableBase() {
}

TableDefinition* customerdomainblacklistTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customerdomainblacklistTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customerdomainblacklistTableBase::Get_ID(long long& out) const {

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

const TableColumn* customerdomainblacklistTableBase::GetConstColumn_ID() const {

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

TableColumn* customerdomainblacklistTableBase::GetColumn_ID() {

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

void customerdomainblacklistTableBase::Set_ID(const long long& in) {

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

void customerdomainblacklistTableBase::Get_CUSTOMERDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customerdomainblacklistTableBase::GetConstColumn_CUSTOMERDOMAIN_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customerdomainblacklistTableBase::GetColumn_CUSTOMERDOMAIN_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customerdomainblacklistTableBase::Set_CUSTOMERDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerdomainblacklistTableBase::Get_path(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path";
      break;
    case DB_IBM_DB2:
      fieldName = "path";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customerdomainblacklistTableBase::GetConstColumn_path() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path";
      break;
    case DB_IBM_DB2:
      fieldName = "path";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customerdomainblacklistTableBase::GetColumn_path() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path";
      break;
    case DB_IBM_DB2:
      fieldName = "path";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path";
      break;
    }

    return GetColumnByName(fieldName);
}

void customerdomainblacklistTableBase::Set_path(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "path";
      break;
    case DB_IBM_DB2:
      fieldName = "path";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("path");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "path";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerdomainblacklistTableBase::Get_isPathRegex(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPathRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isPathRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPathRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPathRegex";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customerdomainblacklistTableBase::GetConstColumn_isPathRegex() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPathRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isPathRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPathRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPathRegex";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customerdomainblacklistTableBase::GetColumn_isPathRegex() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPathRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isPathRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPathRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPathRegex";
      break;
    }

    return GetColumnByName(fieldName);
}

void customerdomainblacklistTableBase::Set_isPathRegex(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPathRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isPathRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPathRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPathRegex";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customerdomainblacklistTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_path(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_path(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_path(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_path(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_isPathRegex(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_isPathRegex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customerdomainblacklistTableBase::GetBy_isPathRegex(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainblacklistTableBase::GetWhereColumnsFor_isPathRegex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customerdomainblacklistTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customerdomainblacklistTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerdomainsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customerdomainblacklistTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerdomainblacklistTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}

void customerdomainblacklistTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerdomainblacklistTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
    TableDefinition*       joinTableDef       (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerdomainsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerdomainblacklistTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customerdomainblacklistTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_ID());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_ID());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_path(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_path());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_path(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_path());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_isPathRegex(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_isPathRegex());
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

void customerdomainblacklistTableBase::GetWhereColumnsFor_isPathRegex(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customerdomainblacklistTableBase::GetDefinition_isPathRegex());
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
TableColumnDefinition* customerdomainblacklistTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomainblacklist");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customerdomainblacklistTableBase::GetDefinition_CUSTOMERDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomainblacklist");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customerdomainblacklistTableBase::GetDefinition_path() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "path";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "path";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("path");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomainblacklist");
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
    createParam.dataSize            = (2048);
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customerdomainblacklistTableBase::GetDefinition_isPathRegex() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "isPathRegex";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "isPathRegex";
      createParam.tableName    = "customerdomainblacklist";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("isPathRegex");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomainblacklist");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
