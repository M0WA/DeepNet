#include "dataminingcriteriaTableBase.h"

#include "dataminingcriteriaTableDefinitionCreateParam.h"
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

dataminingcriteriaTableBase::dataminingcriteriaTableBase()
: TableBase(dataminingcriteriaTableBase::CreateTableDefinition()) {
}

dataminingcriteriaTableBase::dataminingcriteriaTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dataminingcriteriaTableBase");
}

dataminingcriteriaTableBase::~dataminingcriteriaTableBase() {
}

TableDefinition* dataminingcriteriaTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dataminingcriteriaTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dataminingcriteriaTableBase::Get_ID(long long& out) const {
    GetConstColumnByName("ID")->Get(out);
}

void dataminingcriteriaTableBase::Set_ID(const long long& in) {
    GetColumnByName("ID")->Set(in);
}

void dataminingcriteriaTableBase::Get_keyword(std::string& out) const {
    GetConstColumnByName("keyword")->Get(out);
}

void dataminingcriteriaTableBase::Set_keyword(const std::string& in) {
    GetColumnByName("keyword")->Set(in);
}

void dataminingcriteriaTableBase::Get_type(long long& out) const {
    GetConstColumnByName("type")->Get(out);
}

void dataminingcriteriaTableBase::Set_type(const long long& in) {
    GetColumnByName("type")->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dataminingcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaTableBase::GetBy_keyword(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_keyword(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaTableBase::GetBy_keyword(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_keyword(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void dataminingcriteriaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingcriteriaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(dataminingcriteriaTableBase::CreateTableDefinition());
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
void dataminingcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_ID();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_ID();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcriteriaTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_keyword();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaTableBase::GetWhereColumnsFor_keyword(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_keyword();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}

void dataminingcriteriaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_type();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void dataminingcriteriaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = dataminingcriteriaTableBase::GetDefinition_type();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}



//
// template: TableDefinitionCreateParam_CreateColumn.inc.cpp
//
TableColumnDefinition* dataminingcriteriaTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "ID";
    createParam.tableName          = "dataminingcriteria";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
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
TableColumnDefinition* dataminingcriteriaTableBase::GetDefinition_keyword() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "keyword";
    createParam.tableName          = "dataminingcriteria";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
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
    createParam.isUniqueKey        = false;
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* dataminingcriteriaTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    createParam.columnName         = "type";
    createParam.tableName          = "dataminingcriteria";
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
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
    createParam.isIndex            = false;
    createParam.isNullable         = false;
    createParam.hasDefaultValue    = false;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
