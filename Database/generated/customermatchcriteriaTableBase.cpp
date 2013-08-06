#include "customermatchcriteriaTableBase.h"

#include "customermatchcriteriaTableDefinitionCreateParam.h"
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



#include "customerdomainsTableBase.h"
#include "matchcriteriaTableBase.h"


namespace database {

customermatchcriteriaTableBase::customermatchcriteriaTableBase()
: TableBase(customermatchcriteriaTableBase::CreateTableDefinition()) {
}

customermatchcriteriaTableBase::customermatchcriteriaTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customermatchcriteriaTableBase");
}

customermatchcriteriaTableBase::~customermatchcriteriaTableBase() {
}

TableDefinition* customermatchcriteriaTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customermatchcriteriaTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customermatchcriteriaTableBase::Get_ID(long long& out) const {

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

const TableColumn* customermatchcriteriaTableBase::GetConstColumn_ID() const {

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

TableColumn* customermatchcriteriaTableBase::GetColumn_ID() {

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

void customermatchcriteriaTableBase::Set_ID(const long long& in) {

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

void customermatchcriteriaTableBase::Get_CUSTOMERDOMAIN_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customermatchcriteriaTableBase::GetConstColumn_CUSTOMERDOMAIN_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customermatchcriteriaTableBase::GetColumn_CUSTOMERDOMAIN_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customermatchcriteriaTableBase::Set_CUSTOMERDOMAIN_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERDOMAIN_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customermatchcriteriaTableBase::Get_MATCHCRITERIA_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("MATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "MATCHCRITERIA_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customermatchcriteriaTableBase::GetConstColumn_MATCHCRITERIA_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("MATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "MATCHCRITERIA_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customermatchcriteriaTableBase::GetColumn_MATCHCRITERIA_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("MATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "MATCHCRITERIA_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customermatchcriteriaTableBase::Set_MATCHCRITERIA_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "MATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("MATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "MATCHCRITERIA_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customermatchcriteriaTableBase::Get_type(long long& out) const {

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

const TableColumn* customermatchcriteriaTableBase::GetConstColumn_type() const {

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

TableColumn* customermatchcriteriaTableBase::GetColumn_type() {

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

void customermatchcriteriaTableBase::Set_type(const long long& in) {

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
void customermatchcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_MATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_MATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_MATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_MATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void customermatchcriteriaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(customermatchcriteriaTableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customermatchcriteriaTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customerdomainsTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriaTableBase::AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}

void customermatchcriteriaTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
    TableDefinition*       joinTableDef       (customerdomainsTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customerdomainsTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriaTableBase::AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID("","","","",stmt);
}
void customermatchcriteriaTableBase::AddInnerJoinLeftSideOn_MATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (matchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(matchcriteriaTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriaTableBase::AddInnerJoinLeftSideOn_MATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_MATCHCRITERIA_ID("","","","",stmt);
}

void customermatchcriteriaTableBase::AddInnerJoinRightSideOn_MATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());
    TableDefinition*       joinTableDef       (matchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (matchcriteriaTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriaTableBase::AddInnerJoinRightSideOn_MATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_MATCHCRITERIA_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customermatchcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_MATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_MATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_type());
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

void customermatchcriteriaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriaTableBase::GetDefinition_type());
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
TableColumnDefinition* customermatchcriteriaTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteria");
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
TableColumnDefinition* customermatchcriteriaTableBase::GetDefinition_CUSTOMERDOMAIN_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMERDOMAIN_ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMERDOMAIN_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteria");
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
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customermatchcriteriaTableBase::GetDefinition_MATCHCRITERIA_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "MATCHCRITERIA_ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "MATCHCRITERIA_ID";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("MATCHCRITERIA_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteria");
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
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* customermatchcriteriaTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "type";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "type";
      createParam.tableName    = "customermatchcriteria";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("type");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteria");
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
    return TableColumnDefinition::CreateInstance(createParam);
}

}
