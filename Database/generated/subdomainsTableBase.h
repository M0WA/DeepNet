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
 * @brief wrapper class for database table subdomains
 */
class subdomainsTableBase : public TableBase {

private:
    subdomainsTableBase(const TableBase& base);

public:
    subdomainsTableBase();
    virtual ~subdomainsTableBase();

public:
    /**
     * factory function for subdomains's table definition.
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
     * gets value of subdomain.
     * @param out value.
     */
	void Get_subdomain(std::string& out) const;

	/**
	 * sets value of subdomain.
	 * @param in value.
	 */
    void Set_subdomain(const std::string& in);


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
        SelectResultContainer<subdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<subdomainsTableBase>& results);
public:
	/**
	 * gets rows by a value of subdomain.
	 * @param db database connection.
	 * @param fieldValue value of subdomain.
	 * @param results contains results.
	 */
    static void GetBy_subdomain(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<subdomainsTableBase>& results);

	/**
	 * gets rows by multiple values of subdomain.
	 * @param db database connection.
	 * @param fieldValue values of subdomain.
	 * @param results contains results.
	 */
    static void GetBy_subdomain(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<subdomainsTableBase>& results);


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
     * creates where condition for a value of subdomain.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_subdomain(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of subdomain.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_subdomain(
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
     * create a column definition for column subdomain.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_subdomain();

};

}
