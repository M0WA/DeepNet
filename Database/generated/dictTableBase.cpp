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
    GetConstColumnByName("ID")->Get(out);
}

void dictTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void dictTableBase::Get_keyword(std::string& out) const {
    GetConstColumnByName("keyword")->Get(out);
}

void dictTableBase::Set_keyword(const std::string& in) {
    GetColumnByName("keyword")->Set(in);
}

void dictTableBase::Get_occurrence(long long& out) const {
    GetConstColumnByName("occurrence")->Get(out);
}

void dictTableBase::Set_occurrence(const long long& in) {
    GetColumnByName("occurrence")->Set(in);
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

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dictTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dictTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_keyword();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dictTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_keyword();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dictTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_occurrence();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dictTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dictTableBase::GetDefinition_occurrence();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dictTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "dict";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = true;
    createParam.isAutoGenerated    = true;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dictTableBase::GetDefinition_keyword() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "keyword";
    createParam.tableName          = "dict";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_VARCHAR;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = true;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dictTableBase::GetDefinition_occurrence() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "occurrence";
    createParam.tableName          = "dict";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      break;
    case DB_INVALID_TYPE:
    default:
      break;
    }
    createParam.columnType         = DB_TYPE_INTEGER;
    createParam.isPrimaryKey       = false;
    createParam.isAutoGenerated    = false;
    createParam.isForeignKey       = false;
    createParam.isUniqueKey        = false;
    createParam.isIndex            = true;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
