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
 * @brief wrapper class for database table locksecondleveldomain
 */
class locksecondleveldomainTableBase : public TableBase {

private:
    locksecondleveldomainTableBase(const TableBase& base);

public:
    locksecondleveldomainTableBase();
    virtual ~locksecondleveldomainTableBase();

public:
    /**
     * factory function for locksecondleveldomain's table definition.
     * @return table definition.
     */
    static TableDefinition* CreateTableDefinition();

public:
//
// template: TableBase_GetSetFields.inc.h
//
    /**
     * gets value of SECONDLEVELDOMAIN_ID.
     * @param out value.
     */
	void Get_SECONDLEVELDOMAIN_ID(long long& out) const;

	/**
	 * sets value of SECONDLEVELDOMAIN_ID.
	 * @param in value.
	 */
    void Set_SECONDLEVELDOMAIN_ID(const long long& in);
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
     * gets value of schedule.
     * @param out value.
     */
	void Get_schedule(struct tm& out) const;

	/**
	 * sets value of schedule.
	 * @param in value.
	 */
    void Set_schedule(const struct tm& in);


public:
//
// template: TableBase_GetByFields.inc.h
//
public:
	/**
	 * gets rows by a value of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results);

	/**
	 * gets rows by multiple values of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results);
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
        SelectResultContainer<locksecondleveldomainTableBase>& results);

	/**
	 * gets rows by multiple values of CRAWLERSESSION_ID.
	 * @param db database connection.
	 * @param fieldValue values of CRAWLERSESSION_ID.
	 * @param results contains results.
	 */
    static void GetBy_CRAWLERSESSION_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results);
public:
	/**
	 * gets rows by a value of schedule.
	 * @param db database connection.
	 * @param fieldValue value of schedule.
	 * @param results contains results.
	 */
    static void GetBy_schedule(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results);

	/**
	 * gets rows by multiple values of schedule.
	 * @param db database connection.
	 * @param fieldValue values of schedule.
	 * @param results contains results.
	 */
    static void GetBy_schedule(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<locksecondleveldomainTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//


public:
//
// template: TableBase_WhereColumns.inc.h
//
    /**
     * creates where condition for a value of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
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
     * creates where condition for a value of schedule.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_schedule(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of schedule.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_schedule(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);


public:
//
// template: TableDefinitionCreateParam_CreateColumn.inc.h
//
    /**
     * create a column definition for column SECONDLEVELDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SECONDLEVELDOMAIN_ID();
    /**
     * create a column definition for column CRAWLERSESSION_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CRAWLERSESSION_ID();
    /**
     * create a column definition for column schedule.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_schedule();

};

}
