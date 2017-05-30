#include "searchqueryresultinfoTableBase.h"

#include "searchqueryresultinfoTableDefinitionCreateParam.h"
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



#include "searchqueryresultTableBase.h"


namespace database {

searchqueryresultinfoTableBase::searchqueryresultinfoTableBase()
: TableBase(searchqueryresultinfoTableBase::CreateTableDefinition()) {
}

searchqueryresultinfoTableBase::searchqueryresultinfoTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy searchqueryresultinfoTableBase");
}

searchqueryresultinfoTableBase::~searchqueryresultinfoTableBase() {
}

TableDefinition* searchqueryresultinfoTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(searchqueryresultinfoTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void searchqueryresultinfoTableBase::Get_ID(long long& out) const {

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

const TableColumn* searchqueryresultinfoTableBase::GetConstColumn_ID() const {

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

TableColumn* searchqueryresultinfoTableBase::GetColumn_ID() {

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

void searchqueryresultinfoTableBase::Set_ID(const long long& in) {

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

void searchqueryresultinfoTableBase::Get_SEARCHQUERYRESULT_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERYRESULT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryresultinfoTableBase::GetConstColumn_SEARCHQUERYRESULT_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERYRESULT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryresultinfoTableBase::GetColumn_SEARCHQUERYRESULT_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERYRESULT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryresultinfoTableBase::Set_SEARCHQUERYRESULT_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("SEARCHQUERYRESULT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "SEARCHQUERYRESULT_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void searchqueryresultinfoTableBase::Get_infotype(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "infotype";
      break;
    case DB_IBM_DB2:
      fieldName = "infotype";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("infotype");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "infotype";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryresultinfoTableBase::GetConstColumn_infotype() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "infotype";
      break;
    case DB_IBM_DB2:
      fieldName = "infotype";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("infotype");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "infotype";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryresultinfoTableBase::GetColumn_infotype() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "infotype";
      break;
    case DB_IBM_DB2:
      fieldName = "infotype";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("infotype");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "infotype";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryresultinfoTableBase::Set_infotype(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "infotype";
      break;
    case DB_IBM_DB2:
      fieldName = "infotype";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("infotype");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "infotype";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void searchqueryresultinfoTableBase::Get_type(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "type";
      break;
    case DB_IBM_DB2:
      fieldName = "type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "type";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryresultinfoTableBase::GetConstColumn_type() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "type";
      break;
    case DB_IBM_DB2:
      fieldName = "type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "type";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryresultinfoTableBase::GetColumn_type() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "type";
      break;
    case DB_IBM_DB2:
      fieldName = "type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "type";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryresultinfoTableBase::Set_type(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "type";
      break;
    case DB_IBM_DB2:
      fieldName = "type";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("type");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "type";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void searchqueryresultinfoTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_SEARCHQUERYRESULT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_SEARCHQUERYRESULT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_infotype(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_infotype(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_infotype(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_infotype(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryresultinfoTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryresultinfoTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryresultinfoTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void searchqueryresultinfoTableBase::AddInnerJoinLeftSideOn_SEARCHQUERYRESULT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (searchqueryresultTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(searchqueryresultTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (searchqueryresultinfoTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchqueryresultinfoTableBase::AddInnerJoinLeftSideOn_SEARCHQUERYRESULT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_SEARCHQUERYRESULT_ID("","","","",stmt);
}

void searchqueryresultinfoTableBase::AddInnerJoinRightSideOn_SEARCHQUERYRESULT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (searchqueryresultinfoTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID());
    TableDefinition*       joinTableDef       (searchqueryresultTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (searchqueryresultTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void searchqueryresultinfoTableBase::AddInnerJoinRightSideOn_SEARCHQUERYRESULT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_SEARCHQUERYRESULT_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void searchqueryresultinfoTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_ID());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_ID());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_infotype(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_infotype());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_infotype(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_infotype());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_type());
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

void searchqueryresultinfoTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryresultinfoTableBase::GetDefinition_type());
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
TableColumnDefinition* searchqueryresultinfoTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchqueryresultinfo");
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
TableColumnDefinition* searchqueryresultinfoTableBase::GetDefinition_SEARCHQUERYRESULT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "SEARCHQUERYRESULT_ID";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "SEARCHQUERYRESULT_ID";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("SEARCHQUERYRESULT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchqueryresultinfo");
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
TableColumnDefinition* searchqueryresultinfoTableBase::GetDefinition_infotype() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "infotype";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "infotype";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("infotype");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchqueryresultinfo");
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
TableColumnDefinition* searchqueryresultinfoTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "type";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "type";
      createParam.tableName    = "searchqueryresultinfo";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("type");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchqueryresultinfo");
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
    createParam.dataSize            = (255);
    return TableColumnDefinition::CreateInstance(createParam);
}

}
