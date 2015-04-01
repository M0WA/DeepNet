#include "urlspathpartTableBase.h"

#include "urlspathpartTableDefinitionCreateParam.h"
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



#include "pathpartsTableBase.h"
#include "urlsTableBase.h"


namespace database {

urlspathpartTableBase::urlspathpartTableBase()
: TableBase(urlspathpartTableBase::CreateTableDefinition()) {
}

urlspathpartTableBase::urlspathpartTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy urlspathpartTableBase");
}

urlspathpartTableBase::~urlspathpartTableBase() {
}

TableDefinition* urlspathpartTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(urlspathpartTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void urlspathpartTableBase::Get_ID(long long& out) const {

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

const TableColumn* urlspathpartTableBase::GetConstColumn_ID() const {

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

TableColumn* urlspathpartTableBase::GetColumn_ID() {

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

void urlspathpartTableBase::Set_ID(const long long& in) {

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

void urlspathpartTableBase::Get_PATHPART_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PATHPART_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlspathpartTableBase::GetConstColumn_PATHPART_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PATHPART_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlspathpartTableBase::GetColumn_PATHPART_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PATHPART_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlspathpartTableBase::Set_PATHPART_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "PATHPART_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "PATHPART_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("PATHPART_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "PATHPART_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void urlspathpartTableBase::Get_URL_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlspathpartTableBase::GetConstColumn_URL_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlspathpartTableBase::GetColumn_URL_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlspathpartTableBase::Set_URL_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URL_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URL_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URL_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URL_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void urlspathpartTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlspathpartTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlspathpartTableBase::GetBy_PATHPART_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlspathpartTableBase::GetBy_PATHPART_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlspathpartTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlspathpartTableBase::GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlspathpartTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlspathpartTableBase::GetWhereColumnsFor_URL_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlspathpartTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void urlspathpartTableBase::AddInnerJoinLeftSideOn_PATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (pathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(pathpartsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (urlspathpartTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlspathpartTableBase::GetDefinition_PATHPART_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlspathpartTableBase::AddInnerJoinLeftSideOn_PATHPART_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_PATHPART_ID("","","","",stmt);
}

void urlspathpartTableBase::AddInnerJoinRightSideOn_PATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlspathpartTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlspathpartTableBase::GetDefinition_PATHPART_ID());
    TableDefinition*       joinTableDef       (pathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (pathpartsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlspathpartTableBase::AddInnerJoinRightSideOn_PATHPART_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_PATHPART_ID("","","","",stmt);
}
void urlspathpartTableBase::AddInnerJoinLeftSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (urlspathpartTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlspathpartTableBase::GetDefinition_URL_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlspathpartTableBase::AddInnerJoinLeftSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URL_ID("","","","",stmt);
}

void urlspathpartTableBase::AddInnerJoinRightSideOn_URL_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlspathpartTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlspathpartTableBase::GetDefinition_URL_ID());
    TableDefinition*       joinTableDef       (urlsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlspathpartTableBase::AddInnerJoinRightSideOn_URL_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URL_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void urlspathpartTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_ID());
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

void urlspathpartTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_ID());
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

void urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_PATHPART_ID());
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

void urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_PATHPART_ID());
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

void urlspathpartTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_URL_ID());
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

void urlspathpartTableBase::GetWhereColumnsFor_URL_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlspathpartTableBase::GetDefinition_URL_ID());
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
TableColumnDefinition* urlspathpartTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlspathpart");
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
TableColumnDefinition* urlspathpartTableBase::GetDefinition_PATHPART_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "PATHPART_ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "PATHPART_ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("PATHPART_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlspathpart");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* urlspathpartTableBase::GetDefinition_URL_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URL_ID";
      createParam.tableName    = "urlspathpart";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URL_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlspathpart");
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
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
