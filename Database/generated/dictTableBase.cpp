#include "dictTableBase.h"

#include "dictTableDefinitionCreateParam.h"
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

dictTableBase::dictTableBase()
: TableBase(dictTableBase::CreateTableDefinition()) {
}

dictTableBase::dictTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dictTableBase");
}

dictTableBase::~dictTableBase() {
}

TableDefinition* dictTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dictTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dictTableBase::Get_ID(long long& out) const {

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

const TableColumn* dictTableBase::GetConstColumn_ID() const {

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

TableColumn* dictTableBase::GetColumn_ID() {

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

void dictTableBase::Set_ID(const long long& in) {

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

void dictTableBase::Get_keyword(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "keyword";
      break;
    case DB_IBM_DB2:
      fieldName = "keyword";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("keyword");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "keyword";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* dictTableBase::GetConstColumn_keyword() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "keyword";
      break;
    case DB_IBM_DB2:
      fieldName = "keyword";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("keyword");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "keyword";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* dictTableBase::GetColumn_keyword() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "keyword";
      break;
    case DB_IBM_DB2:
      fieldName = "keyword";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("keyword");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "keyword";
      break;
    }

    return GetColumnByName(fieldName);
}

void dictTableBase::Set_keyword(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "keyword";
      break;
    case DB_IBM_DB2:
      fieldName = "keyword";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("keyword");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "keyword";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void dictTableBase::Get_occurrence(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "occurrence";
      break;
    case DB_IBM_DB2:
      fieldName = "occurrence";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("occurrence");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "occurrence";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* dictTableBase::GetConstColumn_occurrence() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "occurrence";
      break;
    case DB_IBM_DB2:
      fieldName = "occurrence";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("occurrence");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "occurrence";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* dictTableBase::GetColumn_occurrence() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "occurrence";
      break;
    case DB_IBM_DB2:
      fieldName = "occurrence";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("occurrence");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "occurrence";
      break;
    }

    return GetColumnByName(fieldName);
}

void dictTableBase::Set_occurrence(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "occurrence";
      break;
    case DB_IBM_DB2:
      fieldName = "occurrence";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("occurrence");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "occurrence";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dictTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dictTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dictTableBase::GetBy_keyword(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_keyword(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dictTableBase::GetBy_keyword(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_keyword(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dictTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dictTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dictTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dictTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dictTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//


//
// template: TableBase_WhereColumns.inc.cpp
//
void dictTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_ID());
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

void dictTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_ID());
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

void dictTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_keyword());
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

void dictTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_keyword());
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

void dictTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_occurrence());
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

void dictTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dictTableBase::GetDefinition_occurrence());
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
TableColumnDefinition* dictTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "ID";
      createParam.tableName    = "dict";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "dict";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("dict");
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
TableColumnDefinition* dictTableBase::GetDefinition_keyword() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "keyword";
      createParam.tableName    = "dict";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "keyword";
      createParam.tableName    = "dict";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("keyword");
      createParam.tableName    = tools::StringTools::ToLowerNP("dict");
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType          = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey        = false;
    createParam.isAutoGenerated     = false;
    createParam.isForeignKey        = false;
    createParam.isUniqueKey         = true;
    createParam.isCombinedUniqueKey = false;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dictTableBase::GetDefinition_occurrence() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "occurrence";
      createParam.tableName    = "dict";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "occurrence";
      createParam.tableName    = "dict";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("occurrence");
      createParam.tableName    = tools::StringTools::ToLowerNP("dict");
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
    return TableColumnDefinition::CreateInstance(createParam);
}

}
