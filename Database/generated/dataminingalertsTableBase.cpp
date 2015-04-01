#include "dataminingalertsTableBase.h"

#include "dataminingalertsTableDefinitionCreateParam.h"
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

dataminingalertsTableBase::dataminingalertsTableBase()
: TableBase(dataminingalertsTableBase::CreateTableDefinition()) {
}

dataminingalertsTableBase::dataminingalertsTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy dataminingalertsTableBase");
}

dataminingalertsTableBase::~dataminingalertsTableBase() {
}

TableDefinition* dataminingalertsTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(dataminingalertsTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void dataminingalertsTableBase::Get_ID(long long& out) const {

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

const TableColumn* dataminingalertsTableBase::GetConstColumn_ID() const {

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

TableColumn* dataminingalertsTableBase::GetColumn_ID() {

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

void dataminingalertsTableBase::Set_ID(const long long& in) {

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

void dataminingalertsTableBase::Get_type(long long& out) const {

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

const TableColumn* dataminingalertsTableBase::GetConstColumn_type() const {

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

TableColumn* dataminingalertsTableBase::GetColumn_type() {

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

void dataminingalertsTableBase::Set_type(const long long& in) {

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

void dataminingalertsTableBase::Get_param(std::string& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "param";
      break;
    case DB_IBM_DB2:
      fieldName = "param";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("param");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "param";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* dataminingalertsTableBase::GetConstColumn_param() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "param";
      break;
    case DB_IBM_DB2:
      fieldName = "param";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("param");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "param";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* dataminingalertsTableBase::GetColumn_param() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "param";
      break;
    case DB_IBM_DB2:
      fieldName = "param";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("param");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "param";
      break;
    }

    return GetColumnByName(fieldName);
}

void dataminingalertsTableBase::Set_param(const std::string& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "param";
      break;
    case DB_IBM_DB2:
      fieldName = "param";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("param");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "param";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void dataminingalertsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void dataminingalertsTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void dataminingalertsTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void dataminingalertsTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void dataminingalertsTableBase::GetBy_param(
        DatabaseConnection* db, 
        const std::string& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_param(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void dataminingalertsTableBase::GetBy_param(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    dataminingalertsTableBase::GetWhereColumnsFor_param(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(dataminingalertsTableBase::CreateTableDefinition());
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
void dataminingalertsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_ID());
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

void dataminingalertsTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_ID());
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

void dataminingalertsTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_type());
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

void dataminingalertsTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_type());
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

void dataminingalertsTableBase::GetWhereColumnsFor_param(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::string& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_param());
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

void dataminingalertsTableBase::GetWhereColumnsFor_param(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<std::string>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(dataminingalertsTableBase::GetDefinition_param());
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
TableColumnDefinition* dataminingalertsTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "ID";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingalerts");
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
TableColumnDefinition* dataminingalertsTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "type";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "type";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("type");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingalerts");
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
TableColumnDefinition* dataminingalertsTableBase::GetDefinition_param() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "datamining";
      createParam.columnName   = "param";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "param";
      createParam.tableName    = "dataminingalerts";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("param");
      createParam.tableName    = tools::StringTools::ToLowerNP("dataminingalerts");
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
    createParam.isNullable          = true;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = (2048);
    return TableColumnDefinition::CreateInstance(createParam);
}

}
