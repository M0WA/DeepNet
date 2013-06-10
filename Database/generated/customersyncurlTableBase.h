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
 * @brief wrapper class for database table customersyncurl
 */
class customersyncurlTableBase : public TableBase {

private:
    customersyncurlTableBase(const TableBase& base);

public:
    customersyncurlTableBase();
    virtual ~customersyncurlTableBase();

public:
    /**
     * factory function for customersyncurl's table definition.
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
     * gets value of URL_ID.
     * @param out value.
     */
	void Get_URL_ID(long long& out) const;

	/**
	 * sets value of URL_ID.
	 * @param in value.
	 */
    void Set_URL_ID(const long long& in);
    /**
     * gets value of scheduled.
     * @param out value.
     */
	void Get_scheduled(struct tm& out) const;

	/**
	 * sets value of scheduled.
	 * @param in value.
	 */
    void Set_scheduled(const struct tm& in);


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
        SelectResultContainer<customersyncurlTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results);
public:
	/**
	 * gets rows by a value of URL_ID.
	 * @param db database connection.
	 * @param fieldValue value of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results);

	/**
	 * gets rows by multiple values of URL_ID.
	 * @param db database connection.
	 * @param fieldValue values of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results);
public:
	/**
	 * gets rows by a value of scheduled.
	 * @param db database connection.
	 * @param fieldValue value of scheduled.
	 * @param results contains results.
	 */
    static void GetBy_scheduled(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results);

	/**
	 * gets rows by multiple values of scheduled.
	 * @param db database connection.
	 * @param fieldValue values of scheduled.
	 * @param results contains results.
	 */
    static void GetBy_scheduled(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<customersyncurlTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URL_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(Statement& stmt);


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
     * creates where condition for a value of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of scheduled.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_scheduled(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of scheduled.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_scheduled(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
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
     * create a column definition for column URL_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URL_ID();
	/**
     * create a column definition for column scheduled.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_scheduled();

};

}
