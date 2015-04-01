#include "docmetaTableBase.h"

#include "docmetaTableDefinitionCreateParam.h"
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



#include "dictTableBase.h"
#include "urlstagesTableBase.h"


namespace database {

docmetaTableBase::docmetaTableBase()
: TableBase(docmetaTableBase::CreateTableDefinition()) {
}

docmetaTableBase::docmetaTableBase(const TableBase& base) {
    THROW_EXCEPTION(errors::NotImplementedException,"cannot copy docmetaTableBase");
}

docmetaTableBase::~docmetaTableBase() {
}

TableDefinition* docmetaTableBase::CreateTableDefinition(){
    return TableDefinition::CreateInstance(docmetaTableDefinitionCreateParam());
}

//
// template: TableBase_GetSetFields.inc.cpp
//
void docmetaTableBase::Get_ID(long long& out) const {

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

const TableColumn* docmetaTableBase::GetConstColumn_ID() const {

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

TableColumn* docmetaTableBase::GetColumn_ID() {

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

void docmetaTableBase::Set_ID(const long long& in) {

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

void docmetaTableBase::Get_DICT_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* docmetaTableBase::GetConstColumn_DICT_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* docmetaTableBase::GetColumn_DICT_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void docmetaTableBase::Set_DICT_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "DICT_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "DICT_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("DICT_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "DICT_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void docmetaTableBase::Get_URLSTAGE_ID(long long& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* docmetaTableBase::GetConstColumn_URLSTAGE_ID() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    return GetConstColumnByName(fieldName);
}

TableColumn* docmetaTableBase::GetColumn_URLSTAGE_ID() {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    return GetColumnByName(fieldName);
}

void docmetaTableBase::Set_URLSTAGE_ID(const long long& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_IBM_DB2:
      fieldName = "URLSTAGE_ID";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "URLSTAGE_ID";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}

void docmetaTableBase::Get_occurrence(long long& out) const {

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

const TableColumn* docmetaTableBase::GetConstColumn_occurrence() const {

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

TableColumn* docmetaTableBase::GetColumn_occurrence() {

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

void docmetaTableBase::Set_occurrence(const long long& in) {

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

void docmetaTableBase::Get_type(long long& out) const {

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

const TableColumn* docmetaTableBase::GetConstColumn_type() const {

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

TableColumn* docmetaTableBase::GetColumn_type() {

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

void docmetaTableBase::Set_type(const long long& in) {

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
void docmetaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_DICT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_DICT_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_URLSTAGE_ID(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_occurrence(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_occurrence(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const long long& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}

void docmetaTableBase::GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<docmetaTableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    docmetaTableBase::GetWhereColumnsFor_type(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    TableDefinition* pTblDef(docmetaTableBase::CreateTableDefinition());
    SelectStatement stmt(pTblDef);
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
    delete pTblDef;
}



//
// template: TableBase_InnerJoin.inc.cpp
//
void docmetaTableBase::AddInnerJoinLeftSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (dictTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(dictTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (docmetaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (docmetaTableBase::GetDefinition_DICT_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void docmetaTableBase::AddInnerJoinLeftSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_DICT_ID("","","","",stmt);
}

void docmetaTableBase::AddInnerJoinRightSideOn_DICT_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (docmetaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(docmetaTableBase::GetDefinition_DICT_ID());
    TableDefinition*       joinTableDef       (dictTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (dictTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void docmetaTableBase::AddInnerJoinRightSideOn_DICT_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_DICT_ID("","","","",stmt);
}
void docmetaTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (urlstagesTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(urlstagesTableBase::GetDefinition_ID());
    TableDefinition*       joinTableDef       (docmetaTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (docmetaTableBase::GetDefinition_URLSTAGE_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void docmetaTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinLeftSideOn_URLSTAGE_ID("","","","",stmt);
}

void docmetaTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef (docmetaTableBase::CreateTableDefinition());
    TableColumnDefinition* referencedColumnDef(docmetaTableBase::GetDefinition_URLSTAGE_ID());
    TableDefinition*       joinTableDef       (urlstagesTableBase::CreateTableDefinition());
    TableColumnDefinition* joinColumnDef      (urlstagesTableBase::GetDefinition_ID());

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void docmetaTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt) {

    AddInnerJoinRightSideOn_URLSTAGE_ID("","","","",stmt);
}


//
// template: TableBase_WhereColumns.inc.cpp
//
void docmetaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_ID());
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

void docmetaTableBase::GetWhereColumnsFor_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_ID());
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

void docmetaTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_DICT_ID());
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

void docmetaTableBase::GetWhereColumnsFor_DICT_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_DICT_ID());
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

void docmetaTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_URLSTAGE_ID());
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

void docmetaTableBase::GetWhereColumnsFor_URLSTAGE_ID(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_URLSTAGE_ID());
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

void docmetaTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_occurrence());
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

void docmetaTableBase::GetWhereColumnsFor_occurrence(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_occurrence());
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

void docmetaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const long long& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_type());
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

void docmetaTableBase::GetWhereColumnsFor_type(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<long long>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(docmetaTableBase::GetDefinition_type());
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
TableColumnDefinition* docmetaTableBase::GetDefinition_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("docmeta");
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
TableColumnDefinition* docmetaTableBase::GetDefinition_DICT_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "DICT_ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "DICT_ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("DICT_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("docmeta");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* docmetaTableBase::GetDefinition_URLSTAGE_ID() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "URLSTAGE_ID";
      createParam.tableName    = "docmeta";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("URLSTAGE_ID");
      createParam.tableName    = tools::StringTools::ToLowerNP("docmeta");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}
TableColumnDefinition* docmetaTableBase::GetDefinition_occurrence() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "occurrence";
      createParam.tableName    = "docmeta";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "occurrence";
      createParam.tableName    = "docmeta";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("occurrence");
      createParam.tableName    = tools::StringTools::ToLowerNP("docmeta");
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
TableColumnDefinition* docmetaTableBase::GetDefinition_type() {

    TableColumnDefinitionCreateParam createParam;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      createParam.databaseName = "lexicon";
      createParam.columnName   = "type";
      createParam.tableName    = "docmeta";
      break;
    case DB_IBM_DB2:
      createParam.databaseName = "deepnet";
      createParam.columnName   = "type";
      createParam.tableName    = "docmeta";
      break;
    case DB_POSTGRESQL:
      createParam.databaseName = "deepnet.public";
      createParam.columnName   = tools::StringTools::ToLowerNP("type");
      createParam.tableName    = tools::StringTools::ToLowerNP("docmeta");
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
    createParam.isCombinedUniqueKey = true;
    createParam.isIndex             = false;
    createParam.isNullable          = false;
    createParam.hasDefaultValue     = false;
    createParam.dataSize            = 0;
    return TableColumnDefinition::CreateInstance(createParam);
}

}
