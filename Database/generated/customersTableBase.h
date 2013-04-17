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
 * @brief wrapper class for database table customers
 */
class customersTableBase : public TableBase {

private:
    customersTableBase(const TableBase& base);

public:
    customersTableBase();
    virtual ~customersTableBase();

public:
    /**
     * factory function for customers's table definition.
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
     * gets value of login.
     * @param out value.
     */
	void Get_login(std::string& out) const;

	/**
	 * sets value of login.
	 * @param in value.
	 */
    void Set_login(const std::string& in);
    /**
     * gets value of password.
     * @param out value.
     */
	void Get_password(std::string& out) const;

	/**
	 * sets value of password.
	 * @param in value.
	 */
    void Set_password(const std::string& in);


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
        SelectResultContainer<customersTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customersTableBase>& results);
public:
	/**
	 * gets rows by a value of login.
	 * @param db database connection.
	 * @param fieldValue value of login.
	 * @param results contains results.
	 */
    static void GetBy_login(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customersTableBase>& results);

	/**
	 * gets rows by multiple values of login.
	 * @param db database connection.
	 * @param fieldValue values of login.
	 * @param results contains results.
	 */
    static void GetBy_login(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customersTableBase>& results);
public:
	/**
	 * gets rows by a value of password.
	 * @param db database connection.
	 * @param fieldValue value of password.
	 * @param results contains results.
	 */
    static void GetBy_password(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customersTableBase>& results);

	/**
	 * gets rows by multiple values of password.
	 * @param db database connection.
	 * @param fieldValue values of password.
	 * @param results contains results.
	 */
    static void GetBy_password(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customersTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//


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
     * creates where condition for a value of login.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_login(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of login.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_login(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of password.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_password(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of password.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_password(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
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
     * create a column definition for column login.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_login();
	/**
     * create a column definition for column password.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_password();

};

}
