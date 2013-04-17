#pragma once

#include "TableBase.h"
#include "SelectResultContainer.h"

namespace database {

class WhereConditionTableColumn;
class WhereConditionTableColumnCreateParam;
class TableDefinition;
class TableColumnDefinition;
class DatabaseConnection;

/**
 * @brief wrapper class for database table searchquerykeywords
 */
class searchquerykeywordsTableBase : public TableBase {

private:
    searchquerykeywordsTableBase(const TableBase& base);

public:
    searchquerykeywordsTableBase();
    virtual ~searchquerykeywordsTableBase();

public:
    /**
     * factory function for searchquerykeywords's table definition.
     * @return table definition.
     */
    static TableDefinition* CreateTableDefinition();

public:
//
// template: TableBase_GetSetFields.inc.h
//
    /**
     * gets value of ID.
     * @param out value.
     */
	void Get_ID(long long& out) const;

	/**
	 * sets value of ID.
	 * @param in value.
	 */
    void Set_ID(const long long& in);
    /**
     * gets value of KEYWORDQUERY_ID.
     * @param out value.
     */
	void Get_KEYWORDQUERY_ID(long long& out) const;

	/**
	 * sets value of KEYWORDQUERY_ID.
	 * @param in value.
	 */
    void Set_KEYWORDQUERY_ID(const long long& in);
    /**
     * gets value of SEARCHQUERY_ID.
     * @param out value.
     */
	void Get_SEARCHQUERY_ID(long long& out) const;

	/**
	 * sets value of SEARCHQUERY_ID.
	 * @param in value.
	 */
    void Set_SEARCHQUERY_ID(const long long& in);


public:
//
// template: TableBase_GetByFields.inc.h
//
public:
	/**
	 * gets rows by a value of ID.
	 * @param db database connection.
	 * @param fieldValue value of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of KEYWORDQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue value of KEYWORDQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_KEYWORDQUERY_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of KEYWORDQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue values of KEYWORDQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_KEYWORDQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of SEARCHQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue value of SEARCHQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of SEARCHQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue values of SEARCHQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchquerykeywordsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_KEYWORDQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_KEYWORDQUERY_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_KEYWORDQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_KEYWORDQUERY_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_SEARCHQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SEARCHQUERY_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERY_ID(Statement& stmt);


public:
//
// template: TableBase_WhereColumns.inc.h
//
    /**
     * creates where condition for a value of ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of KEYWORDQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_KEYWORDQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of KEYWORDQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_KEYWORDQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of SEARCHQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SEARCHQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SEARCHQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SEARCHQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);


public:
//
// template: TableDefinitionCreateParam_CreateColumn.inc.h
//
	/**
     * create a column definition for column ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_ID();
	/**
     * create a column definition for column KEYWORDQUERY_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_KEYWORDQUERY_ID();
	/**
     * create a column definition for column SEARCHQUERY_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SEARCHQUERY_ID();

};

}
