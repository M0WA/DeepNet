#include "customersynccrawlerTableBase.h"

#include "customersynccrawlerTableDefinitionCreateParam.h"
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

customersynccrawlerTableBase::customersynccrawlerTableBase()
: TableBase(customersynccrawlerTableBase::CreateTableDefinition()) {
}

customersynccrawlerTableBase::customersynccrawlerTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customersynccrawlerTableBase");
}

customersynccrawlerTableBase::~customersynccrawlerTableBase() {
}

TableDefinition* customersynccrawlerTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customersynccrawlerTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customersynccrawlerTableBase::Get_ID(long long& out) const {

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

const TableColumn* customersynccrawlerTableBase::GetConstColumn_ID() const {

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

TableColumn* customersynccrawlerTableBase::GetColumn_ID() {

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

void customersynccrawlerTableBase::Set_ID(const long long& in) {

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

void customersynccrawlerTableBase::Get_CUSTOMERDOMAIN_ID(long long& out) const {

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

const TableColumn* customersynccrawlerTableBase::GetConstColumn_CUSTOMERDOMAIN_ID() const {

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

TableColumn* customersynccrawlerTableBase::GetColumn_CUSTOMERDOMAIN_ID() {

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

void customersynccrawlerTableBase::Set_CUSTOMERDOMAIN_ID(const long long& in) {

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

void customersynccrawlerTableBase::Get_CRAWLERSESSION_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customersynccrawlerTableBase::GetConstColumn_CRAWLERSESSION_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customersynccrawlerTableBase::GetColumn_CRAWLERSESSION_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customersynccrawlerTableBase::Set_CRAWLERSESSION_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CRAWLERSESSION_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CRAWLERSESSION_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customersynccrawlerTableBase::Get_scheduled(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "scheduled";
      break;
    case DB_IBM_DB2:
      fieldName = "scheduled";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("scheduled");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "scheduled";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customersynccrawlerTableBase::GetConstColumn_scheduled() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "scheduled";
      break;
    case DB_IBM_DB2:
      fieldName = "scheduled";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("scheduled");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "scheduled";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customersynccrawlerTableBase::GetColumn_scheduled() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "scheduled";
      break;
    case DB_IBM_DB2:
      fieldName = "scheduled";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("scheduled");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "scheduled";
      break;
    }

    return GetColumnByName(fieldName);
}

void customersynccrawlerTableBase::Set_scheduled(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "scheduled";
      break;
    case DB_IBM_DB2:
      fieldName = "scheduled";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("scheduled");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "scheduled";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customersynccrawlerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customersynccrawlerTableBase::GetBy_scheduled(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customersynccrawlerTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customersynccrawlerTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerdomainsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customersynccrawlerTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersynccrawlerTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}

void customersynccrawlerTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customersynccrawlerTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
    TableDefinition*       joinTableDef       (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerdomainsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersynccrawlerTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customersynccrawlerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_scheduled());
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

void customersynccrawlerTableBase::GetWhereColumnsFor_scheduled(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersynccrawlerTableBase::GetDefinition_scheduled());
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
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersynccrawler");
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
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_CUSTOMERDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersynccrawler");
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
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_CRAWLERSESSION_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CRAWLERSESSION_ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CRAWLERSESSION_ID";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CRAWLERSESSION_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersynccrawler");
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
    createParam.isIndex             = true;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customersynccrawlerTableBase::GetDefinition_scheduled() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "scheduled";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "scheduled";
      createParam.tableName    = "customersynccrawler";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("scheduled");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersynccrawler");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_TIMESTAMP;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = true;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
