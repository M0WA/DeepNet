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
 * @brief wrapper class for database table customersynccrawler
 */
class customersynccrawlerTableBase : public TableBase {

private:
    customersynccrawlerTableBase(const TableBase& base);

public:
    customersynccrawlerTableBase();
    virtual ~customersynccrawlerTableBase();

public:
    /**
     * factory function for customersynccrawler's table definition.
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
     * gets value of CUSTOMERDOMAIN_ID.
     * @param out value.
     */
	void Get_CUSTOMERDOMAIN_ID(long long& out) const;

	/**
	 * sets value of CUSTOMERDOMAIN_ID.
	 * @param in value.
	 */
    void Set_CUSTOMERDOMAIN_ID(const long long& in);
    /**
     * gets value of CRAWLERSESSION_ID.
     * @param out value.
     */
	void Get_CRAWLERSESSION_ID(long long& out) const;

	/**
	 * sets value of CRAWLERSESSION_ID.
	 * @param in value.
	 */
    void Set_CRAWLERSESSION_ID(const long long& in);
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
        SelectResultContainer<customersynccrawlerTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);
public:
	/**
	 * gets rows by a value of CRAWLERSESSION_ID.
	 * @param db database connection.
	 * @param fieldValue value of CRAWLERSESSION_ID.
	 * @param results contains results.
	 */
    static void GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);

	/**
	 * gets rows by multiple values of CRAWLERSESSION_ID.
	 * @param db database connection.
	 * @param fieldValue values of CRAWLERSESSION_ID.
	 * @param results contains results.
	 */
    static void GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);
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
        SelectResultContainer<customersynccrawlerTableBase>& results);

	/**
	 * gets rows by multiple values of scheduled.
	 * @param db database connection.
	 * @param fieldValue values of scheduled.
	 * @param results contains results.
	 */
    static void GetBy_scheduled(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<customersynccrawlerTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of CRAWLERSESSION_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CRAWLERSESSION_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CRAWLERSESSION_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CRAWLERSESSION_ID(
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
     * create a column definition for column CUSTOMERDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERDOMAIN_ID();
	/**
     * create a column definition for column CRAWLERSESSION_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CRAWLERSESSION_ID();
	/**
     * create a column definition for column scheduled.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_scheduled();

};

}
