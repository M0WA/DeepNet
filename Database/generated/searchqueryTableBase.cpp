#include "searchqueryTableBase.h"

#include "searchqueryTableDefinitionCreateParam.h"
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

searchqueryTableBase::searchqueryTableBase()
: TableBase(searchqueryTableBase::CreateTableDefinition()) {
}

searchqueryTableBase::searchqueryTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy searchqueryTableBase");
}

searchqueryTableBase::~searchqueryTableBase() {
}

TableDefinition* searchqueryTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(searchqueryTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void searchqueryTableBase::Get_ID(long long& out) const {

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

const TableColumn* searchqueryTableBase::GetConstColumn_ID() const {

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

TableColumn* searchqueryTableBase::GetColumn_ID() {

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

void searchqueryTableBase::Set_ID(const long long& in) {

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

void searchqueryTableBase::Get_session(std::string& out) const {

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

const TableColumn* searchqueryTableBase::GetConstColumn_session() const {

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

TableColumn* searchqueryTableBase::GetColumn_session() {

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

void searchqueryTableBase::Set_session(const std::string& in) {

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

void searchqueryTableBase::Get_query(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "query";
      break;
    case DB_IBM_DB2:
      fieldName = "query";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("query");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "query";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryTableBase::GetConstColumn_query() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "query";
      break;
    case DB_IBM_DB2:
      fieldName = "query";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("query");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "query";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryTableBase::GetColumn_query() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "query";
      break;
    case DB_IBM_DB2:
      fieldName = "query";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("query");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "query";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryTableBase::Set_query(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "query";
      break;
    case DB_IBM_DB2:
      fieldName = "query";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("query");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "query";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void searchqueryTableBase::Get_age(struct tm& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "age";
      break;
    case DB_IBM_DB2:
      fieldName = "age";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("age");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "age";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryTableBase::GetConstColumn_age() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "age";
      break;
    case DB_IBM_DB2:
      fieldName = "age";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("age");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "age";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryTableBase::GetColumn_age() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "age";
      break;
    case DB_IBM_DB2:
      fieldName = "age";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("age");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "age";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryTableBase::Set_age(const struct tm& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "age";
      break;
    case DB_IBM_DB2:
      fieldName = "age";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("age");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "age";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void searchqueryTableBase::Get_total(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "total";
      break;
    case DB_IBM_DB2:
      fieldName = "total";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("total");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "total";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* searchqueryTableBase::GetConstColumn_total() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "total";
      break;
    case DB_IBM_DB2:
      fieldName = "total";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("total");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "total";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* searchqueryTableBase::GetColumn_total() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "total";
      break;
    case DB_IBM_DB2:
      fieldName = "total";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("total");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "total";
      break;
    }

    return GetColumnByName(fieldName);
}

void searchqueryTableBase::Set_total(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "total";
      break;
    case DB_IBM_DB2:
      fieldName = "total";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("total");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "total";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void searchqueryTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_session(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_session(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_session(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_session(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_query(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_query(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_query(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_query(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_age(
        DatabaseConnection* db, 
        const struct tm& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_age(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_age(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_age(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_total(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_total(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void searchqueryTableBase::GetBy_total(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    searchqueryTableBase::GetWhereColumnsFor_total(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(searchqueryTableBase::CreateTableDefinition());
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
void searchqueryTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_ID());
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

void searchqueryTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_ID());
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

void searchqueryTableBase::GetWhereColumnsFor_session(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_session());
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

void searchqueryTableBase::GetWhereColumnsFor_session(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_session());
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

void searchqueryTableBase::GetWhereColumnsFor_query(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_query());
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

void searchqueryTableBase::GetWhereColumnsFor_query(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_query());
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

void searchqueryTableBase::GetWhereColumnsFor_age(
    const WhereConditionTableColumnCreateParam& createParam,
    const struct tm& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_age());
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

void searchqueryTableBase::GetWhereColumnsFor_age(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<struct tm>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_age());
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

void searchqueryTableBase::GetWhereColumnsFor_total(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_total());
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

void searchqueryTableBase::GetWhereColumnsFor_total(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(searchqueryTableBase::GetDefinition_total());
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
TableColumnDefinition* searchqueryTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchquery";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "searchquery";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquery");
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
TableColumnDefinition* searchqueryTableBase::GetDefinition_session() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "session";
      createParam.tableName    = "searchquery";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "session";
      createParam.tableName    = "searchquery";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("session");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquery");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_CHAR;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = false;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = (64);
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* searchqueryTableBase::GetDefinition_query() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "query";
      createParam.tableName    = "searchquery";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "query";
      createParam.tableName    = "searchquery";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("query");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquery");
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
TableColumnDefinition* searchqueryTableBase::GetDefinition_age() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "age";
      createParam.tableName    = "searchquery";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "age";
      createParam.tableName    = "searchquery";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("age");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquery");
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
TableColumnDefinition* searchqueryTableBase::GetDefinition_total() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "queryserver";
      createParam.columnName   = "total";
      createParam.tableName    = "searchquery";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "total";
      createParam.tableName    = "searchquery";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("total");
      createParam.tableName    = tools::StringTools::ToLowerNP("searchquery");
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
