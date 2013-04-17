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
 * @brief wrapper class for database table dataminingcriteriaalerts
 */
class dataminingcriteriaalertsTableBase : public TableBase {

private:
    dataminingcriteriaalertsTableBase(const TableBase& base);

public:
    dataminingcriteriaalertsTableBase();
    virtual ~dataminingcriteriaalertsTableBase();

public:
    /**
     * factory function for dataminingcriteriaalerts's table definition.
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
     * gets value of CUSTOMER_ID.
     * @param out value.
     */
	void Get_CUSTOMER_ID(long long& out) const;

	/**
	 * sets value of CUSTOMER_ID.
	 * @param in value.
	 */
    void Set_CUSTOMER_ID(const long long& in);
    /**
     * gets value of DATAMININGALERT_ID.
     * @param out value.
     */
	void Get_DATAMININGALERT_ID(long long& out) const;

	/**
	 * sets value of DATAMININGALERT_ID.
	 * @param in value.
	 */
    void Set_DATAMININGALERT_ID(const long long& in);
    /**
     * gets value of DATAMININGCRITERIA_ID.
     * @param out value.
     */
	void Get_DATAMININGCRITERIA_ID(long long& out) const;

	/**
	 * sets value of DATAMININGCRITERIA_ID.
	 * @param in value.
	 */
    void Set_DATAMININGCRITERIA_ID(const long long& in);


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
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMER_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMER_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMER_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMER_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMER_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);
public:
	/**
	 * gets rows by a value of DATAMININGALERT_ID.
	 * @param db database connection.
	 * @param fieldValue value of DATAMININGALERT_ID.
	 * @param results contains results.
	 */
    static void GetBy_DATAMININGALERT_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);

	/**
	 * gets rows by multiple values of DATAMININGALERT_ID.
	 * @param db database connection.
	 * @param fieldValue values of DATAMININGALERT_ID.
	 * @param results contains results.
	 */
    static void GetBy_DATAMININGALERT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);
public:
	/**
	 * gets rows by a value of DATAMININGCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue value of DATAMININGCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_DATAMININGCRITERIA_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);

	/**
	 * gets rows by multiple values of DATAMININGCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue values of DATAMININGCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_DATAMININGCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingcriteriaalertsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_DATAMININGALERT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_DATAMININGALERT_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_DATAMININGALERT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_DATAMININGALERT_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_DATAMININGCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_DATAMININGCRITERIA_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_DATAMININGCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_DATAMININGCRITERIA_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMER_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMER_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMER_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMER_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of DATAMININGALERT_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_DATAMININGALERT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of DATAMININGALERT_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_DATAMININGALERT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of DATAMININGCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_DATAMININGCRITERIA_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of DATAMININGCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_DATAMININGCRITERIA_ID(
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
     * create a column definition for column CUSTOMER_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMER_ID();
	/**
     * create a column definition for column DATAMININGALERT_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_DATAMININGALERT_ID();
	/**
     * create a column definition for column DATAMININGCRITERIA_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_DATAMININGCRITERIA_ID();

};

}
