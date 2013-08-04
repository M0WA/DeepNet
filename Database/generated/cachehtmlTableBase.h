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
 * @brief wrapper class for database table cachehtml
 */
class cachehtmlTableBase : public TableBase {

private:
    cachehtmlTableBase(const TableBase& base);

public:
    cachehtmlTableBase();
    virtual ~cachehtmlTableBase();

public:
    /**
     * factory function for cachehtml's table definition.
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
   * gets column for ID.
   * @return column for ID.
   */
  const TableColumn* GetColumn_ID() const;

	/**
	 * sets value of ID.
	 * @param in value.
	 */
  void Set_ID(const long long& in);
  /**
   * gets value of size.
   * @param out value.
   */
  void Get_size(long long& out) const;

  /**
   * gets column for size.
   * @return column for size.
   */
  const TableColumn* GetColumn_size() const;

	/**
	 * sets value of size.
	 * @param in value.
	 */
  void Set_size(const long long& in);
  /**
   * gets value of matches.
   * @param out value.
   */
  void Get_matches(long long& out) const;

  /**
   * gets column for matches.
   * @return column for matches.
   */
  const TableColumn* GetColumn_matches() const;

	/**
	 * sets value of matches.
	 * @param in value.
	 */
  void Set_matches(const long long& in);
  /**
   * gets value of misses.
   * @param out value.
   */
  void Get_misses(long long& out) const;

  /**
   * gets column for misses.
   * @return column for misses.
   */
  const TableColumn* GetColumn_misses() const;

	/**
	 * sets value of misses.
	 * @param in value.
	 */
  void Set_misses(const long long& in);
  /**
   * gets value of action_time.
   * @param out value.
   */
  void Get_action_time(struct tm& out) const;

  /**
   * gets column for action_time.
   * @return column for action_time.
   */
  const TableColumn* GetColumn_action_time() const;

	/**
	 * sets value of action_time.
	 * @param in value.
	 */
  void Set_action_time(const struct tm& in);


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
        SelectResultContainer<cachehtmlTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);
public:
	/**
	 * gets rows by a value of size.
	 * @param db database connection.
	 * @param fieldValue value of size.
	 * @param results contains results.
	 */
    static void GetBy_size(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);

	/**
	 * gets rows by multiple values of size.
	 * @param db database connection.
	 * @param fieldValue values of size.
	 * @param results contains results.
	 */
    static void GetBy_size(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);
public:
	/**
	 * gets rows by a value of matches.
	 * @param db database connection.
	 * @param fieldValue value of matches.
	 * @param results contains results.
	 */
    static void GetBy_matches(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);

	/**
	 * gets rows by multiple values of matches.
	 * @param db database connection.
	 * @param fieldValue values of matches.
	 * @param results contains results.
	 */
    static void GetBy_matches(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);
public:
	/**
	 * gets rows by a value of misses.
	 * @param db database connection.
	 * @param fieldValue value of misses.
	 * @param results contains results.
	 */
    static void GetBy_misses(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);

	/**
	 * gets rows by multiple values of misses.
	 * @param db database connection.
	 * @param fieldValue values of misses.
	 * @param results contains results.
	 */
    static void GetBy_misses(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);
public:
	/**
	 * gets rows by a value of action_time.
	 * @param db database connection.
	 * @param fieldValue value of action_time.
	 * @param results contains results.
	 */
    static void GetBy_action_time(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);

	/**
	 * gets rows by multiple values of action_time.
	 * @param db database connection.
	 * @param fieldValue values of action_time.
	 * @param results contains results.
	 */
    static void GetBy_action_time(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<cachehtmlTableBase>& results);


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
     * creates where condition for a value of size.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_size(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of size.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_size(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of matches.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_matches(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of matches.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_matches(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of misses.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_misses(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of misses.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_misses(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of action_time.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_action_time(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of action_time.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_action_time(
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
     * create a column definition for column size.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_size();
	/**
     * create a column definition for column matches.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_matches();
	/**
     * create a column definition for column misses.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_misses();
	/**
     * create a column definition for column action_time.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_action_time();

};

}
