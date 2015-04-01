#include "matchcriteriaTableBase.h"

#include "matchcriteriaTableDefinitionCreateParam.h"
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

matchcriteriaTableBase::matchcriteriaTableBase()
: TableBase(matchcriteriaTableBase::CreateTableDefinition()) {
}

matchcriteriaTableBase::matchcriteriaTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy matchcriteriaTableBase");
}

matchcriteriaTableBase::~matchcriteriaTableBase() {
}

TableDefinition* matchcriteriaTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(matchcriteriaTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void matchcriteriaTableBase::Get_ID(long long& out) const {

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

const TableColumn* matchcriteriaTableBase::GetConstColumn_ID() const {

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

TableColumn* matchcriteriaTableBase::GetColumn_ID() {

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

void matchcriteriaTableBase::Set_ID(const long long& in) {

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

void matchcriteriaTableBase::Get_regex(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "regex";
      break;
    case DB_IBM_DB2:
      fieldName = "regex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("regex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "regex";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* matchcriteriaTableBase::GetConstColumn_regex() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "regex";
      break;
    case DB_IBM_DB2:
      fieldName = "regex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("regex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "regex";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* matchcriteriaTableBase::GetColumn_regex() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "regex";
      break;
    case DB_IBM_DB2:
      fieldName = "regex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("regex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "regex";
      break;
    }

    return GetColumnByName(fieldName);
}

void matchcriteriaTableBase::Set_regex(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "regex";
      break;
    case DB_IBM_DB2:
      fieldName = "regex";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("regex");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "regex";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void matchcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    matchcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(matchcriteriaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void matchcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    matchcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(matchcriteriaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void matchcriteriaTableBase::GetBy_regex(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    matchcriteriaTableBase::GetWhereColumnsFor_regex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(matchcriteriaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void matchcriteriaTableBase::GetBy_regex(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    matchcriteriaTableBase::GetWhereColumnsFor_regex(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(matchcriteriaTableBase::CreateTableDefinition());
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
void matchcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(matchcriteriaTableBase::GetDefinition_ID());
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

void matchcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(matchcriteriaTableBase::GetDefinition_ID());
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

void matchcriteriaTableBase::GetWhereColumnsFor_regex(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(matchcriteriaTableBase::GetDefinition_regex());
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

void matchcriteriaTableBase::GetWhereColumnsFor_regex(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(matchcriteriaTableBase::GetDefinition_regex());
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
TableColumnDefinition* matchcriteriaTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "matchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "matchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("matchcriteria");
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
TableColumnDefinition* matchcriteriaTableBase::GetDefinition_regex() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "regex";
      createParam.tableName    = "matchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "regex";
      createParam.tableName    = "matchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("regex");
      createParam.tableName    = tools::StringTools::ToLowerNP("matchcriteria");
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
    createParam.dataSize            = (2048);
    return TableColumnDefinition::CreateInstance(createParam);
}

}
