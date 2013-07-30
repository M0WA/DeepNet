#include "customerdomainsTableBase.h"

#include "customerdomainsTableDefinitionCreateParam.h"
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



#include "customersTableBase.h"


namespace database {

customerdomainsTableBase::customerdomainsTableBase()
: TableBase(customerdomainsTableBase::CreateTableDefinition()) {
}

customerdomainsTableBase::customerdomainsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customerdomainsTableBase");
}

customerdomainsTableBase::~customerdomainsTableBase() {
}

TableDefinition* customerdomainsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customerdomainsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customerdomainsTableBase::Get_ID(long long& out) const {

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

void customerdomainsTableBase::Set_ID(const long long& in) {

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

void customerdomainsTableBase::Get_CUSTOMER_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMER_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMER_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMER_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMER_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerdomainsTableBase::Set_CUSTOMER_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMER_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMER_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMER_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMER_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerdomainsTableBase::Get_domain(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "domain";
      break;
    case DB_IBM_DB2:
      fieldName = "domain";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("domain");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "domain";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerdomainsTableBase::Set_domain(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "domain";
      break;
    case DB_IBM_DB2:
      fieldName = "domain";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("domain");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "domain";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerdomainsTableBase::Get_revisitInterval(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "revisitInterval";
      break;
    case DB_IBM_DB2:
      fieldName = "revisitInterval";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("revisitInterval");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "revisitInterval";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerdomainsTableBase::Set_revisitInterval(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "revisitInterval";
      break;
    case DB_IBM_DB2:
      fieldName = "revisitInterval";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("revisitInterval");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "revisitInterval";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customerdomainsTableBase::Get_isDomainRegex(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isDomainRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isDomainRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isDomainRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isDomainRegex";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

void customerdomainsTableBase::Set_isDomainRegex(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isDomainRegex";
      break;
    case DB_IBM_DB2:
      fieldName = "isDomainRegex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isDomainRegex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isDomainRegex";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customerdomainsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_domain(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_domain(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_domain(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_domain(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_revisitInterval(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_revisitInterval(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_revisitInterval(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_revisitInterval(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_isDomainRegex(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_isDomainRegex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customerdomainsTableBase::GetBy_isDomainRegex(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customerdomainsTableBase::GetWhereColumnsFor_isDomainRegex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customerdomainsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customerdomainsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customersTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customersTableBase::GetDefinition_ID();
    TableDefinition*       joinTableDef        = customerdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customerdomainsTableBase::GetDefinition_CUSTOMER_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerdomainsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMER_ID("","","","",stmt);
}

void customerdomainsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = customerdomainsTableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = customerdomainsTableBase::GetDefinition_CUSTOMER_ID();
    TableDefinition*       joinTableDef        = customersTableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = customersTableBase::GetDefinition_ID();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customerdomainsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMER_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customerdomainsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_CUSTOMER_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_CUSTOMER_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_domain(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_domain();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_domain(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_domain();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_revisitInterval(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_revisitInterval();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_revisitInterval(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_revisitInterval();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_isDomainRegex(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_isDomainRegex();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void customerdomainsTableBase::GetWhereColumnsFor_isDomainRegex(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = customerdomainsTableBase::GetDefinition_isDomainRegex();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* customerdomainsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerdomains";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customerdomains";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomains");
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
TableColumnDefinition* customerdomainsTableBase::GetDefinition_CUSTOMER_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "customerdomains";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "customerdomains";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMER_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomains");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_INTEGER;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = true;
    createParam.isUniqueKey         = true;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customerdomainsTableBase::GetDefinition_domain() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "domain";
      createParam.tableName    = "customerdomains";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "domain";
      createParam.tableName    = "customerdomains";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("domain");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomains");
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
TableColumnDefinition* customerdomainsTableBase::GetDefinition_revisitInterval() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "revisitInterval";
      createParam.tableName    = "customerdomains";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "revisitInterval";
      createParam.tableName    = "customerdomains";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("revisitInterval");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomains");
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
TableColumnDefinition* customerdomainsTableBase::GetDefinition_isDomainRegex() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "isDomainRegex";
      createParam.tableName    = "customerdomains";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "isDomainRegex";
      createParam.tableName    = "customerdomains";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("isDomainRegex");
      createParam.tableName    = tools::StringTools::ToLowerNP("customerdomains");
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
