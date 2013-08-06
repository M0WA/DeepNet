#include "customersessionsTableBase.h"

#include "customersessionsTableDefinitionCreateParam.h"
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

customersessionsTableBase::customersessionsTableBase()
: TableBase(customersessionsTableBase::CreateTableDefinition()) {
}

customersessionsTableBase::customersessionsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customersessionsTableBase");
}

customersessionsTableBase::~customersessionsTableBase() {
}

TableDefinition* customersessionsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customersessionsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customersessionsTableBase::Get_ID(long long& out) const {

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

const TableColumn* customersessionsTableBase::GetConstColumn_ID() const {

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

TableColumn* customersessionsTableBase::GetColumn_ID() {

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

void customersessionsTableBase::Set_ID(const long long& in) {

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

void customersessionsTableBase::Get_CUSTOMER_ID(long long& out) const {

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

const TableColumn* customersessionsTableBase::GetConstColumn_CUSTOMER_ID() const {

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

    return GetConstColumnByName(fieldName);
}

TableColumn* customersessionsTableBase::GetColumn_CUSTOMER_ID() {

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

    return GetColumnByName(fieldName);
}

void customersessionsTableBase::Set_CUSTOMER_ID(const long long& in) {

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

void customersessionsTableBase::Get_session(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "session";
      break;
    case DB_IBM_DB2:
      fieldName = "session";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("session");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "session";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customersessionsTableBase::GetConstColumn_session() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "session";
      break;
    case DB_IBM_DB2:
      fieldName = "session";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("session");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "session";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customersessionsTableBase::GetColumn_session() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "session";
      break;
    case DB_IBM_DB2:
      fieldName = "session";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("session");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "session";
      break;
    }

    return GetColumnByName(fieldName);
}

void customersessionsTableBase::Set_session(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "session";
      break;
    case DB_IBM_DB2:
      fieldName = "session";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("session");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "session";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customersessionsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersessionsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersessionsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersessionsTableBase::GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersessionsTableBase::GetBy_session(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_session(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customersessionsTableBase::GetBy_session(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customersessionsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customersessionsTableBase::GetWhereColumnsFor_session(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customersessionsTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customersessionsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customersTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customersTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customersessionsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customersessionsTableBase::GetDefinition_CUSTOMER_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersessionsTableBase::AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMER_ID("","","","",stmt);
}

void customersessionsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customersessionsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customersessionsTableBase::GetDefinition_CUSTOMER_ID());
    TableDefinition*       joinTableDef       (customersTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customersTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customersessionsTableBase::AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMER_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customersessionsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_ID());
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

void customersessionsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_ID());
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

void customersessionsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_CUSTOMER_ID());
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

void customersessionsTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_CUSTOMER_ID());
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

void customersessionsTableBase::GetWhereColumnsFor_session(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_session());
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

void customersessionsTableBase::GetWhereColumnsFor_session(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customersessionsTableBase::GetDefinition_session());
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
TableColumnDefinition* customersessionsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customersessions";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customersessions";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersessions");
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
TableColumnDefinition* customersessionsTableBase::GetDefinition_CUSTOMER_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "customersessions";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "customersessions";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMER_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersessions");
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
TableColumnDefinition* customersessionsTableBase::GetDefinition_session() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "session";
      createParam.tableName    = "customersessions";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "session";
      createParam.tableName    = "customersessions";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("session");
      createParam.tableName    = tools::StringTools::ToLowerNP("customersessions");
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
