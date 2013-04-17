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
 * @brief wrapper class for database table customerdomainblacklist
 */
class customerdomainblacklistTableBase : public TableBase {

private:
    customerdomainblacklistTableBase(const TableBase& base);

public:
    customerdomainblacklistTableBase();
    virtual ~customerdomainblacklistTableBase();

public:
    /**
     * factory function for customerdomainblacklist's table definition.
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
     * gets value of path.
     * @param out value.
     */
	void Get_path(std::string& out) const;

	/**
	 * sets value of path.
	 * @param in value.
	 */
    void Set_path(const std::string& in);
    /**
     * gets value of isPathRegex.
     * @param out value.
     */
	void Get_isPathRegex(long long& out) const;

	/**
	 * sets value of isPathRegex.
	 * @param in value.
	 */
    void Set_isPathRegex(const long long& in);


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
        SelectResultContainer<customerdomainblacklistTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);
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
        SelectResultContainer<customerdomainblacklistTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);
public:
	/**
	 * gets rows by a value of path.
	 * @param db database connection.
	 * @param fieldValue value of path.
	 * @param results contains results.
	 */
    static void GetBy_path(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);

	/**
	 * gets rows by multiple values of path.
	 * @param db database connection.
	 * @param fieldValue values of path.
	 * @param results contains results.
	 */
    static void GetBy_path(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);
public:
	/**
	 * gets rows by a value of isPathRegex.
	 * @param db database connection.
	 * @param fieldValue value of isPathRegex.
	 * @param results contains results.
	 */
    static void GetBy_isPathRegex(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);

	/**
	 * gets rows by multiple values of isPathRegex.
	 * @param db database connection.
	 * @param fieldValue values of isPathRegex.
	 * @param results contains results.
	 */
    static void GetBy_isPathRegex(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerdomainblacklistTableBase>& results);


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
     * creates where condition for a value of path.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_path(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of path.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_path(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of isPathRegex.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_isPathRegex(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of isPathRegex.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_isPathRegex(
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
     * create a column definition for column CUSTOMERDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERDOMAIN_ID();
	/**
     * create a column definition for column path.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_path();
	/**
     * create a column definition for column isPathRegex.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_isPathRegex();

};

}
