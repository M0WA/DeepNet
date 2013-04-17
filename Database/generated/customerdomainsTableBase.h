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
 * @brief wrapper class for database table customerdomains
 */
class customerdomainsTableBase : public TableBase {

private:
    customerdomainsTableBase(const TableBase& base);

public:
    customerdomainsTableBase();
    virtual ~customerdomainsTableBase();

public:
    /**
     * factory function for customerdomains's table definition.
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
     * gets value of domain.
     * @param out value.
     */
	void Get_domain(std::string& out) const;

	/**
	 * sets value of domain.
	 * @param in value.
	 */
    void Set_domain(const std::string& in);
    /**
     * gets value of revisitInterval.
     * @param out value.
     */
	void Get_revisitInterval(long long& out) const;

	/**
	 * sets value of revisitInterval.
	 * @param in value.
	 */
    void Set_revisitInterval(const long long& in);
    /**
     * gets value of isDomainRegex.
     * @param out value.
     */
	void Get_isDomainRegex(long long& out) const;

	/**
	 * sets value of isDomainRegex.
	 * @param in value.
	 */
    void Set_isDomainRegex(const long long& in);


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
        SelectResultContainer<customerdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);
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
        SelectResultContainer<customerdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMER_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMER_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);
public:
	/**
	 * gets rows by a value of domain.
	 * @param db database connection.
	 * @param fieldValue value of domain.
	 * @param results contains results.
	 */
    static void GetBy_domain(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of domain.
	 * @param db database connection.
	 * @param fieldValue values of domain.
	 * @param results contains results.
	 */
    static void GetBy_domain(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);
public:
	/**
	 * gets rows by a value of revisitInterval.
	 * @param db database connection.
	 * @param fieldValue value of revisitInterval.
	 * @param results contains results.
	 */
    static void GetBy_revisitInterval(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of revisitInterval.
	 * @param db database connection.
	 * @param fieldValue values of revisitInterval.
	 * @param results contains results.
	 */
    static void GetBy_revisitInterval(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);
public:
	/**
	 * gets rows by a value of isDomainRegex.
	 * @param db database connection.
	 * @param fieldValue value of isDomainRegex.
	 * @param results contains results.
	 */
    static void GetBy_isDomainRegex(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of isDomainRegex.
	 * @param db database connection.
	 * @param fieldValue values of isDomainRegex.
	 * @param results contains results.
	 */
    static void GetBy_isDomainRegex(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt);


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
     * creates where condition for a value of domain.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_domain(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of domain.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_domain(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of revisitInterval.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_revisitInterval(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of revisitInterval.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_revisitInterval(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of isDomainRegex.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_isDomainRegex(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of isDomainRegex.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_isDomainRegex(
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
     * create a column definition for column domain.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_domain();
	/**
     * create a column definition for column revisitInterval.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_revisitInterval();
	/**
     * create a column definition for column isDomainRegex.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_isDomainRegex();

};

}
