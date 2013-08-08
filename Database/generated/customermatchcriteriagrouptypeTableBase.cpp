#include "customermatchcriteriagrouptypeTableBase.h"

#include "customermatchcriteriagrouptypeTableDefinitionCreateParam.h"
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



#include "customermatchcriteriaTableBase.h"


namespace database {

customermatchcriteriagrouptypeTableBase::customermatchcriteriagrouptypeTableBase()
: TableBase(customermatchcriteriagrouptypeTableBase::CreateTableDefinition()) {
}

customermatchcriteriagrouptypeTableBase::customermatchcriteriagrouptypeTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy customermatchcriteriagrouptypeTableBase");
}

customermatchcriteriagrouptypeTableBase::~customermatchcriteriagrouptypeTableBase() {
}

TableDefinition* customermatchcriteriagrouptypeTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(customermatchcriteriagrouptypeTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::Get_ID(long long& out) const {

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

const TableColumn* customermatchcriteriagrouptypeTableBase::GetConstColumn_ID() const {

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

TableColumn* customermatchcriteriagrouptypeTableBase::GetColumn_ID() {

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

void customermatchcriteriagrouptypeTableBase::Set_ID(const long long& in) {

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

void customermatchcriteriagrouptypeTableBase::Get_CUSTOMERMATCHCRITERIA_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERMATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customermatchcriteriagrouptypeTableBase::GetConstColumn_CUSTOMERMATCHCRITERIA_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERMATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customermatchcriteriagrouptypeTableBase::GetColumn_CUSTOMERMATCHCRITERIA_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERMATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void customermatchcriteriagrouptypeTableBase::Set_CUSTOMERMATCHCRITERIA_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("CUSTOMERMATCHCRITERIA_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "CUSTOMERMATCHCRITERIA_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_type(long long& out) const {

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

const TableColumn* customermatchcriteriagrouptypeTableBase::GetConstColumn_type() const {

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

TableColumn* customermatchcriteriagrouptypeTableBase::GetColumn_type() {

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

void customermatchcriteriagrouptypeTableBase::Set_type(const long long& in) {

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

void customermatchcriteriagrouptypeTableBase::Get_groupPosition(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "groupPosition";
      break;
    case DB_IBM_DB2:
      fieldName = "groupPosition";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("groupPosition");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "groupPosition";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customermatchcriteriagrouptypeTableBase::GetConstColumn_groupPosition() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "groupPosition";
      break;
    case DB_IBM_DB2:
      fieldName = "groupPosition";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("groupPosition");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "groupPosition";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customermatchcriteriagrouptypeTableBase::GetColumn_groupPosition() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "groupPosition";
      break;
    case DB_IBM_DB2:
      fieldName = "groupPosition";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("groupPosition");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "groupPosition";
      break;
    }

    return GetColumnByName(fieldName);
}

void customermatchcriteriagrouptypeTableBase::Set_groupPosition(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "groupPosition";
      break;
    case DB_IBM_DB2:
      fieldName = "groupPosition";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("groupPosition");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "groupPosition";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void customermatchcriteriagrouptypeTableBase::Get_isPrimaryKey(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPrimaryKey";
      break;
    case DB_IBM_DB2:
      fieldName = "isPrimaryKey";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPrimaryKey");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPrimaryKey";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* customermatchcriteriagrouptypeTableBase::GetConstColumn_isPrimaryKey() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPrimaryKey";
      break;
    case DB_IBM_DB2:
      fieldName = "isPrimaryKey";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPrimaryKey");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPrimaryKey";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* customermatchcriteriagrouptypeTableBase::GetColumn_isPrimaryKey() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPrimaryKey";
      break;
    case DB_IBM_DB2:
      fieldName = "isPrimaryKey";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPrimaryKey");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPrimaryKey";
      break;
    }

    return GetColumnByName(fieldName);
}

void customermatchcriteriagrouptypeTableBase::Set_isPrimaryKey(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "isPrimaryKey";
      break;
    case DB_IBM_DB2:
      fieldName = "isPrimaryKey";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("isPrimaryKey");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "isPrimaryKey";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}



//
// template: TableBase_GetByFields.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_groupPosition(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_groupPosition(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_isPrimaryKey(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void customermatchcriteriagrouptypeTableBase::GetBy_isPrimaryKey(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customermatchcriteriaTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID("","","","",stmt);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (customermatchcriteriagrouptypeTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());
    TableDefinition*       joinTableDef       (customermatchcriteriaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (customermatchcriteriaTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void customermatchcriteriagrouptypeTableBase::AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_ID());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_ID());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_type());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_type());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_groupPosition(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey());
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

void customermatchcriteriagrouptypeTableBase::GetWhereColumnsFor_isPrimaryKey(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey());
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "ID";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteriagrouptype");
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_CUSTOMERMATCHCRITERIA_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "CUSTOMERMATCHCRITERIA_ID";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "CUSTOMERMATCHCRITERIA_ID";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("CUSTOMERMATCHCRITERIA_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteriagrouptype");
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "type";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "type";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("type");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteriagrouptype");
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_groupPosition() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "groupPosition";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "groupPosition";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("groupPosition");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteriagrouptype");
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
TableColumnDefinition* customermatchcriteriagrouptypeTableBase::GetDefinition_isPrimaryKey() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "commercesearch";
      createParam.columnName   = "isPrimaryKey";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "isPrimaryKey";
      createParam.tableName    = "customermatchcriteriagrouptype";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("isPrimaryKey");
      createParam.tableName    = tools::StringTools::ToLowerNP("customermatchcriteriagrouptype");
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
