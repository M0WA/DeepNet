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
 * @brief wrapper class for database table searchquery
 */
class searchqueryTableBase : public TableBase {

private:
    searchqueryTableBase(const TableBase& base);

public:
    searchqueryTableBase();
    virtual ~searchqueryTableBase();

public:
    /**
     * factory function for searchquery's table definition.
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
   * gets value of session.
   * @param out value.
   */
  void Get_session(std::string& out) const;

  /**
   * gets const column for session.
   * @return column for session.
   */
  const TableColumn* GetConstColumn_session() const;

  /**
   * gets column for session.
   * @return column for session.
   */
  TableColumn* GetColumn_session();

	/**
	 * sets value of session.
	 * @param in value.
	 */
  void Set_session(const std::string& in);
  /**
   * gets value of query.
   * @param out value.
   */
  void Get_query(std::string& out) const;

  /**
   * gets const column for query.
   * @return column for query.
   */
  const TableColumn* GetConstColumn_query() const;

  /**
   * gets column for query.
   * @return column for query.
   */
  TableColumn* GetColumn_query();

	/**
	 * sets value of query.
	 * @param in value.
	 */
  void Set_query(const std::string& in);
  /**
   * gets value of age.
   * @param out value.
   */
  void Get_age(struct tm& out) const;

  /**
   * gets const column for age.
   * @return column for age.
   */
  const TableColumn* GetConstColumn_age() const;

  /**
   * gets column for age.
   * @return column for age.
   */
  TableColumn* GetColumn_age();

	/**
	 * sets value of age.
	 * @param in value.
	 */
  void Set_age(const struct tm& in);
  /**
   * gets value of total.
   * @param out value.
   */
  void Get_total(long long& out) const;

  /**
   * gets const column for total.
   * @return column for total.
   */
  const TableColumn* GetConstColumn_total() const;

  /**
   * gets column for total.
   * @return column for total.
   */
  TableColumn* GetColumn_total();

	/**
	 * sets value of total.
	 * @param in value.
	 */
  void Set_total(const long long& in);


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
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of session.
	 * @param db database connection.
	 * @param fieldValue value of session.
	 * @param results contains results.
	 */
    static void GetBy_session(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of session.
	 * @param db database connection.
	 * @param fieldValue values of session.
	 * @param results contains results.
	 */
    static void GetBy_session(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of query.
	 * @param db database connection.
	 * @param fieldValue value of query.
	 * @param results contains results.
	 */
    static void GetBy_query(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of query.
	 * @param db database connection.
	 * @param fieldValue values of query.
	 * @param results contains results.
	 */
    static void GetBy_query(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of age.
	 * @param db database connection.
	 * @param fieldValue value of age.
	 * @param results contains results.
	 */
    static void GetBy_age(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of age.
	 * @param db database connection.
	 * @param fieldValue values of age.
	 * @param results contains results.
	 */
    static void GetBy_age(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of total.
	 * @param db database connection.
	 * @param fieldValue value of total.
	 * @param results contains results.
	 */
    static void GetBy_total(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of total.
	 * @param db database connection.
	 * @param fieldValue values of total.
	 * @param results contains results.
	 */
    static void GetBy_total(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);


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
     * creates where condition for a value of session.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_session(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of session.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_session(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of query.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_query(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of query.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_query(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of age.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_age(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of age.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_age(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of total.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_total(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of total.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_total(
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
     * create a column definition for column session.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_session();
	/**
     * create a column definition for column query.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_query();
	/**
     * create a column definition for column age.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_age();
	/**
     * create a column definition for column total.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_total();

};

}
