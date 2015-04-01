#include "unittest3TableBase.h"

#include "unittest3TableDefinitionCreateParam.h"
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



#include "unittest1TableBase.h"
#include "unittest2TableBase.h"


namespace database {

unittest3TableBase::unittest3TableBase()
: TableBase(unittest3TableBase::CreateTableDefinition()) {
}

unittest3TableBase::unittest3TableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy unittest3TableBase");
}

unittest3TableBase::~unittest3TableBase() {
}

TableDefinition* unittest3TableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(unittest3TableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void unittest3TableBase::Get_ID(long long& out) const {

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

const TableColumn* unittest3TableBase::GetConstColumn_ID() const {

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

TableColumn* unittest3TableBase::GetColumn_ID() {

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

void unittest3TableBase::Set_ID(const long long& in) {

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

void unittest3TableBase::Get_UNITTEST1_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST1_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST1_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* unittest3TableBase::GetConstColumn_UNITTEST1_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST1_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST1_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* unittest3TableBase::GetColumn_UNITTEST1_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST1_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST1_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void unittest3TableBase::Set_UNITTEST1_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST1_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST1_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST1_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void unittest3TableBase::Get_UNITTEST2_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST2_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST2_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* unittest3TableBase::GetConstColumn_UNITTEST2_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST2_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST2_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* unittest3TableBase::GetColumn_UNITTEST2_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST2_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST2_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void unittest3TableBase::Set_UNITTEST2_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "UNITTEST2_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("UNITTEST2_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "UNITTEST2_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void unittest3TableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void unittest3TableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void unittest3TableBase::GetBy_UNITTEST1_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_UNITTEST1_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void unittest3TableBase::GetBy_UNITTEST1_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_UNITTEST1_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void unittest3TableBase::GetBy_UNITTEST2_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_UNITTEST2_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void unittest3TableBase::GetBy_UNITTEST2_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    unittest3TableBase::GetWhereColumnsFor_UNITTEST2_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(unittest3TableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void unittest3TableBase::AddInnerJoinLeftSideOn_UNITTEST1_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (unittest1TableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(unittest1TableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (unittest3TableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (unittest3TableBase::GetDefinition_UNITTEST1_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void unittest3TableBase::AddInnerJoinLeftSideOn_UNITTEST1_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_UNITTEST1_ID("","","","",stmt);
}

void unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST1_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (unittest3TableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(unittest3TableBase::GetDefinition_UNITTEST1_ID());
    TableDefinition*       joinTableDef       (unittest1TableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (unittest1TableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST1_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_UNITTEST1_ID("","","","",stmt);
}
void unittest3TableBase::AddInnerJoinLeftSideOn_UNITTEST2_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (unittest2TableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(unittest2TableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (unittest3TableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (unittest3TableBase::GetDefinition_UNITTEST2_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void unittest3TableBase::AddInnerJoinLeftSideOn_UNITTEST2_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_UNITTEST2_ID("","","","",stmt);
}

void unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST2_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (unittest3TableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(unittest3TableBase::GetDefinition_UNITTEST2_ID());
    TableDefinition*       joinTableDef       (unittest2TableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (unittest2TableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST2_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_UNITTEST2_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void unittest3TableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_ID());
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

void unittest3TableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_ID());
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

void unittest3TableBase::GetWhereColumnsFor_UNITTEST1_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_UNITTEST1_ID());
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

void unittest3TableBase::GetWhereColumnsFor_UNITTEST1_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_UNITTEST1_ID());
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

void unittest3TableBase::GetWhereColumnsFor_UNITTEST2_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_UNITTEST2_ID());
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

void unittest3TableBase::GetWhereColumnsFor_UNITTEST2_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(unittest3TableBase::GetDefinition_UNITTEST2_ID());
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
TableColumnDefinition* unittest3TableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest3");
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
TableColumnDefinition* unittest3TableBase::GetDefinition_UNITTEST1_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "UNITTEST1_ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "UNITTEST1_ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("UNITTEST1_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest3");
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
TableColumnDefinition* unittest3TableBase::GetDefinition_UNITTEST2_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "UNITTEST2_ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "UNITTEST2_ID";
      createParam.tableName    = "unittest3";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("UNITTEST2_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("unittest3");
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

}
