#include "fencedsearchTableBase.h"

#include "fencedsearchTableDefinitionCreateParam.h"
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

const TableColumn* fencedsearchTableBase::GetConstColumn_ID() const {

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

TableColumn* fencedsearchTableBase::GetColumn_ID() {

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

void fencedsearchTableBase::Set_ID(const long long& in) {

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

void fencedsearchTableBase::Get_CUSTOMER_ID(long long& out) const {

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

const TableColumn* fencedsearchTableBase::GetConstColumn_CUSTOMER_ID() const {

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

TableColumn* fencedsearchTableBase::GetColumn_CUSTOMER_ID() {

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

void fencedsearchTableBase::Set_CUSTOMER_ID(const long long& in) {

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

void fencedsearchTableBase::Get_SECONDLEVELDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* fencedsearchTableBase::GetConstColumn_SECONDLEVELDOMAIN_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* fencedsearchTableBase::GetColumn_SECONDLEVELDOMAIN_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void fencedsearchTableBase::Set_SECONDLEVELDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SECONDLEVELDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
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

    TableDefinition*       referencedTableDef (dataminingcustomerTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(dataminingcustomerTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (fencedsearchTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (fencedsearchTableBase::GetDefinition_CUSTOMER_ID());

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

    TableDefinition*       referencedTableDef (fencedsearchTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(fencedsearchTableBase::GetDefinition_CUSTOMER_ID());
    TableDefinition*       joinTableDef       (dataminingcustomerTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (dataminingcustomerTableBase::GetDefinition_ID());

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

    TableDefinition*       referencedTableDef (secondleveldomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(secondleveldomainsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (fencedsearchTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

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

    TableDefinition*       referencedTableDef (fencedsearchTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());
    TableDefinition*       joinTableDef       (secondleveldomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (secondleveldomainsTableBase::GetDefinition_ID());

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

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_ID());
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

void fencedsearchTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_ID());
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

void fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_CUSTOMER_ID());
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

void fencedsearchTableBase::GetWhereColumnsFor_CUSTOMER_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_CUSTOMER_ID());
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

void fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());
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

void fencedsearchTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());
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
TableColumnDefinition* fencedsearchTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("fencedsearch");
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
TableColumnDefinition* fencedsearchTableBase::GetDefinition_CUSTOMER_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMER_ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMER_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("fencedsearch");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* fencedsearchTableBase::GetDefinition_SECONDLEVELDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SECONDLEVELDOMAIN_ID";
      createParam.tableName    = "fencedsearch";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SECONDLEVELDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("fencedsearch");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
