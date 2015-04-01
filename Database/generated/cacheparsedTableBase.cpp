#include "cacheparsedTableBase.h"

#include "cacheparsedTableDefinitionCreateParam.h"
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





namespace database {

cacheparsedTableBase::cacheparsedTableBase()
: TableBase(cacheparsedTableBase::CreateTableDefinition()) {
}

cacheparsedTableBase::cacheparsedTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy cacheparsedTableBase");
}

cacheparsedTableBase::~cacheparsedTableBase() {
}

TableDefinition* cacheparsedTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(cacheparsedTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void cacheparsedTableBase::Get_ID(long long& out) const {

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

const TableColumn* cacheparsedTableBase::GetConstColumn_ID() const {

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

TableColumn* cacheparsedTableBase::GetColumn_ID() {

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

void cacheparsedTableBase::Set_ID(const long long& in) {

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

void cacheparsedTableBase::Get_size(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* cacheparsedTableBase::GetConstColumn_size() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* cacheparsedTableBase::GetColumn_size() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    return GetColumnByName(fieldName);
}

void cacheparsedTableBase::Set_size(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "size";
      break;
    case DB_IBM_DB2:
      fieldName = "size";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("size");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "size";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cacheparsedTableBase::Get_matches(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* cacheparsedTableBase::GetConstColumn_matches() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* cacheparsedTableBase::GetColumn_matches() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    return GetColumnByName(fieldName);
}

void cacheparsedTableBase::Set_matches(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "matches";
      break;
    case DB_IBM_DB2:
      fieldName = "matches";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("matches");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "matches";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cacheparsedTableBase::Get_misses(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* cacheparsedTableBase::GetConstColumn_misses() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* cacheparsedTableBase::GetColumn_misses() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    return GetColumnByName(fieldName);
}

void cacheparsedTableBase::Set_misses(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "misses";
      break;
    case DB_IBM_DB2:
      fieldName = "misses";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("misses");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "misses";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void cacheparsedTableBase::Get_action_time(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* cacheparsedTableBase::GetConstColumn_action_time() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* cacheparsedTableBase::GetColumn_action_time() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    return GetColumnByName(fieldName);
}

void cacheparsedTableBase::Set_action_time(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "action_time";
      break;
    case DB_IBM_DB2:
      fieldName = "action_time";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("action_time");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "action_time";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void cacheparsedTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_size(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_size(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_size(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_matches(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_matches(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_misses(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_misses(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void cacheparsedTableBase::GetBy_action_time(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<cacheparsedTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    cacheparsedTableBase::GetWhereColumnsFor_action_time(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(cacheparsedTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//


//
// template: TableBase_WhereColumns.inc.cpp
//
void cacheparsedTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_ID());
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

void cacheparsedTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_ID());
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

void cacheparsedTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_size());
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

void cacheparsedTableBase::GetWhereColumnsFor_size(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_size());
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

void cacheparsedTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_matches());
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

void cacheparsedTableBase::GetWhereColumnsFor_matches(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_matches());
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

void cacheparsedTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_misses());
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

void cacheparsedTableBase::GetWhereColumnsFor_misses(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_misses());
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

void cacheparsedTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_action_time());
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

void cacheparsedTableBase::GetWhereColumnsFor_action_time(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(cacheparsedTableBase::GetDefinition_action_time());
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
TableColumnDefinition* cacheparsedTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "ID";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("cacheparsed");
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
TableColumnDefinition* cacheparsedTableBase::GetDefinition_size() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "size";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "size";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("size");
      createParam.tableName    = tools::StringTools::ToLowerNP("cacheparsed");
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
TableColumnDefinition* cacheparsedTableBase::GetDefinition_matches() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "matches";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "matches";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("matches");
      createParam.tableName    = tools::StringTools::ToLowerNP("cacheparsed");
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
TableColumnDefinition* cacheparsedTableBase::GetDefinition_misses() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "misses";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "misses";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("misses");
      createParam.tableName    = tools::StringTools::ToLowerNP("cacheparsed");
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
TableColumnDefinition* cacheparsedTableBase::GetDefinition_action_time() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "logging";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "action_time";
      createParam.tableName    = "cacheparsed";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("action_time");
      createParam.tableName    = tools::StringTools::ToLowerNP("cacheparsed");
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
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
