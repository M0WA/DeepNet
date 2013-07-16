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
 * @brief wrapper class for database table unittest1
 */
class unittest1TableBase : public TableBase {

private:
    unittest1TableBase(const TableBase& base);

public:
    unittest1TableBase();
    virtual ~unittest1TableBase();

public:
    /**
     * factory function for unittest1's table definition.
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
     * gets value of timestamp_test.
     * @param out value.
     */
	void Get_timestamp_test(struct tm& out) const;

	/**
	 * sets value of timestamp_test.
	 * @param in value.
	 */
    void Set_timestamp_test(const struct tm& in);
    /**
     * gets value of varchar_test.
     * @param out value.
     */
	void Get_varchar_test(std::string& out) const;

	/**
	 * sets value of varchar_test.
	 * @param in value.
	 */
    void Set_varchar_test(const std::string& in);
    /**
     * gets value of double_test.
     * @param out value.
     */
	void Get_double_test(double& out) const;

	/**
	 * sets value of double_test.
	 * @param in value.
	 */
    void Set_double_test(const double& in);
    /**
     * gets value of integer_test.
     * @param out value.
     */
	void Get_integer_test(long long& out) const;

	/**
	 * sets value of integer_test.
	 * @param in value.
	 */
    void Set_integer_test(const long long& in);


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
        SelectResultContainer<unittest1TableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);
public:
	/**
	 * gets rows by a value of timestamp_test.
	 * @param db database connection.
	 * @param fieldValue value of timestamp_test.
	 * @param results contains results.
	 */
    static void GetBy_timestamp_test(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);

	/**
	 * gets rows by multiple values of timestamp_test.
	 * @param db database connection.
	 * @param fieldValue values of timestamp_test.
	 * @param results contains results.
	 */
    static void GetBy_timestamp_test(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);
public:
	/**
	 * gets rows by a value of varchar_test.
	 * @param db database connection.
	 * @param fieldValue value of varchar_test.
	 * @param results contains results.
	 */
    static void GetBy_varchar_test(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);

	/**
	 * gets rows by multiple values of varchar_test.
	 * @param db database connection.
	 * @param fieldValue values of varchar_test.
	 * @param results contains results.
	 */
    static void GetBy_varchar_test(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);
public:
	/**
	 * gets rows by a value of double_test.
	 * @param db database connection.
	 * @param fieldValue value of double_test.
	 * @param results contains results.
	 */
    static void GetBy_double_test(
        DatabaseConnection* db,
        const double& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);

	/**
	 * gets rows by multiple values of double_test.
	 * @param db database connection.
	 * @param fieldValue values of double_test.
	 * @param results contains results.
	 */
    static void GetBy_double_test(
        DatabaseConnection* db, 
        const std::vector<double>& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);
public:
	/**
	 * gets rows by a value of integer_test.
	 * @param db database connection.
	 * @param fieldValue value of integer_test.
	 * @param results contains results.
	 */
    static void GetBy_integer_test(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);

	/**
	 * gets rows by multiple values of integer_test.
	 * @param db database connection.
	 * @param fieldValue values of integer_test.
	 * @param results contains results.
	 */
    static void GetBy_integer_test(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest1TableBase>& results);


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
     * creates where condition for a value of timestamp_test.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_timestamp_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of timestamp_test.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_timestamp_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of varchar_test.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_varchar_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of varchar_test.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_varchar_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of double_test.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_double_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const double& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of double_test.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_double_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<double>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of integer_test.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_integer_test(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of integer_test.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_integer_test(
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
     * create a column definition for column timestamp_test.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_timestamp_test();
	/**
     * create a column definition for column varchar_test.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_varchar_test();
	/**
     * create a column definition for column double_test.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_double_test();
	/**
     * create a column definition for column integer_test.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_integer_test();

};

}
