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
 * @brief wrapper class for database table unittest2
 */
class unittest2TableBase : public TableBase {

private:
    unittest2TableBase(const TableBase& base);

public:
    unittest2TableBase();
    virtual ~unittest2TableBase();

public:
    /**
     * factory function for unittest2's table definition.
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
   * gets const column for ID.
   * @return column for ID.
   */
  const TableColumn* GetConstColumn_ID() const;

  /**
   * gets column for ID.
   * @return column for ID.
   */
  TableColumn* GetColumn_ID();

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
   * gets const column for timestamp_test.
   * @return column for timestamp_test.
   */
  const TableColumn* GetConstColumn_timestamp_test() const;

  /**
   * gets column for timestamp_test.
   * @return column for timestamp_test.
   */
  TableColumn* GetColumn_timestamp_test();

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
   * gets const column for varchar_test.
   * @return column for varchar_test.
   */
  const TableColumn* GetConstColumn_varchar_test() const;

  /**
   * gets column for varchar_test.
   * @return column for varchar_test.
   */
  TableColumn* GetColumn_varchar_test();

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
   * gets const column for double_test.
   * @return column for double_test.
   */
  const TableColumn* GetConstColumn_double_test() const;

  /**
   * gets column for double_test.
   * @return column for double_test.
   */
  TableColumn* GetColumn_double_test();

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
   * gets const column for integer_test.
   * @return column for integer_test.
   */
  const TableColumn* GetConstColumn_integer_test() const;

  /**
   * gets column for integer_test.
   * @return column for integer_test.
   */
  TableColumn* GetColumn_integer_test();

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
        SelectResultContainer<unittest2TableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results);
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
        SelectResultContainer<unittest2TableBase>& results);

	/**
	 * gets rows by multiple values of timestamp_test.
	 * @param db database connection.
	 * @param fieldValue values of timestamp_test.
	 * @param results contains results.
	 */
    static void GetBy_timestamp_test(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results);
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
        SelectResultContainer<unittest2TableBase>& results);

	/**
	 * gets rows by multiple values of varchar_test.
	 * @param db database connection.
	 * @param fieldValue values of varchar_test.
	 * @param results contains results.
	 */
    static void GetBy_varchar_test(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results);
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
        SelectResultContainer<unittest2TableBase>& results);

	/**
	 * gets rows by multiple values of double_test.
	 * @param db database connection.
	 * @param fieldValue values of double_test.
	 * @param results contains results.
	 */
    static void GetBy_double_test(
        DatabaseConnection* db, 
        const std::vector<double>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results);
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
        SelectResultContainer<unittest2TableBase>& results);

	/**
	 * gets rows by multiple values of integer_test.
	 * @param db database connection.
	 * @param fieldValue values of integer_test.
	 * @param results contains results.
	 */
    static void GetBy_integer_test(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest2TableBase>& results);


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
