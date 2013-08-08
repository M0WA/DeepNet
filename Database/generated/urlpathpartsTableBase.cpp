#include "urlpathpartsTableBase.h"

#include "urlpathpartsTableDefinitionCreateParam.h"
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
#include "urlpathpartsTableBase.h"


namespace database {

urlpathpartsTableBase::urlpathpartsTableBase()
: TableBase(urlpathpartsTableBase::CreateTableDefinition()) {
}

urlpathpartsTableBase::urlpathpartsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy urlpathpartsTableBase");
}

urlpathpartsTableBase::~urlpathpartsTableBase() {
}

TableDefinition* urlpathpartsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(urlpathpartsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void urlpathpartsTableBase::Get_ID(long long& out) const {

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

const TableColumn* urlpathpartsTableBase::GetConstColumn_ID() const {

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

TableColumn* urlpathpartsTableBase::GetColumn_ID() {

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

void urlpathpartsTableBase::Set_ID(const long long& in) {

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

void urlpathpartsTableBase::Get_PATHPART_ID(long long& out) const {

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

const TableColumn* urlpathpartsTableBase::GetConstColumn_PATHPART_ID() const {

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

TableColumn* urlpathpartsTableBase::GetColumn_PATHPART_ID() {

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

void urlpathpartsTableBase::Set_PATHPART_ID(const long long& in) {

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

void urlpathpartsTableBase::Get_URLPATHPART_ID_NEXT(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID_NEXT");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* urlpathpartsTableBase::GetConstColumn_URLPATHPART_ID_NEXT() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID_NEXT");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* urlpathpartsTableBase::GetColumn_URLPATHPART_ID_NEXT() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID_NEXT");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    }

    return GetColumnByName(fieldName);
}

void urlpathpartsTableBase::Set_URLPATHPART_ID_NEXT(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_IBM_DB2:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLPATHPART_ID_NEXT");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLPATHPART_ID_NEXT";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void urlpathpartsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlpathpartsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlpathpartsTableBase::GetBy_PATHPART_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlpathpartsTableBase::GetBy_PATHPART_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlpathpartsTableBase::GetBy_URLPATHPART_ID_NEXT(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_URLPATHPART_ID_NEXT(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void urlpathpartsTableBase::GetBy_URLPATHPART_ID_NEXT(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    urlpathpartsTableBase::GetWhereColumnsFor_URLPATHPART_ID_NEXT(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(urlpathpartsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void urlpathpartsTableBase::AddInnerJoinLeftSideOn_PATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (pathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(pathpartsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlpathpartsTableBase::GetDefinition_PATHPART_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlpathpartsTableBase::AddInnerJoinLeftSideOn_PATHPART_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_PATHPART_ID("","","","",stmt);
}

void urlpathpartsTableBase::AddInnerJoinRightSideOn_PATHPART_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlpathpartsTableBase::GetDefinition_PATHPART_ID());
    TableDefinition*       joinTableDef       (pathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (pathpartsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlpathpartsTableBase::AddInnerJoinRightSideOn_PATHPART_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_PATHPART_ID("","","","",stmt);
}
void urlpathpartsTableBase::AddInnerJoinLeftSideOn_URLPATHPART_ID_NEXT(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlpathpartsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlpathpartsTableBase::AddInnerJoinLeftSideOn_URLPATHPART_ID_NEXT(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLPATHPART_ID_NEXT("","","","",stmt);
}

void urlpathpartsTableBase::AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT());
    TableDefinition*       joinTableDef       (urlpathpartsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlpathpartsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void urlpathpartsTableBase::AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT(Statement& stmt) {

    AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void urlpathpartsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_ID());
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

void urlpathpartsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_ID());
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

void urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_PATHPART_ID());
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

void urlpathpartsTableBase::GetWhereColumnsFor_PATHPART_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_PATHPART_ID());
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

void urlpathpartsTableBase::GetWhereColumnsFor_URLPATHPART_ID_NEXT(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT());
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

void urlpathpartsTableBase::GetWhereColumnsFor_URLPATHPART_ID_NEXT(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT());
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
TableColumnDefinition* urlpathpartsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlpathparts");
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
TableColumnDefinition* urlpathpartsTableBase::GetDefinition_PATHPART_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "PATHPART_ID";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "PATHPART_ID";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("PATHPART_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlpathparts");
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
TableColumnDefinition* urlpathpartsTableBase::GetDefinition_URLPATHPART_ID_NEXT() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "documents";
      createParam.columnName   = "URLPATHPART_ID_NEXT";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLPATHPART_ID_NEXT";
      createParam.tableName    = "urlpathparts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLPATHPART_ID_NEXT");
      createParam.tableName    = tools::StringTools::ToLowerNP("urlpathparts");
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
