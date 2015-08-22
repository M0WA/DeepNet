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
   * gets value of RESULTTHREAD_ID.
   * @param out value.
   */
  void Get_RESULTTHREAD_ID(long long& out) const;

  /**
   * gets const column for RESULTTHREAD_ID.
   * @return column for RESULTTHREAD_ID.
   */
  const TableColumn* GetConstColumn_RESULTTHREAD_ID() const;

  /**
   * gets column for RESULTTHREAD_ID.
   * @return column for RESULTTHREAD_ID.
   */
  TableColumn* GetColumn_RESULTTHREAD_ID();

	/**
	 * sets value of RESULTTHREAD_ID.
	 * @param in value.
	 */
  void Set_RESULTTHREAD_ID(const long long& in);
  /**
   * gets value of PROPERTIES_ID.
   * @param out value.
   */
  void Get_PROPERTIES_ID(long long& out) const;

  /**
   * gets const column for PROPERTIES_ID.
   * @return column for PROPERTIES_ID.
   */
  const TableColumn* GetConstColumn_PROPERTIES_ID() const;

  /**
   * gets column for PROPERTIES_ID.
   * @return column for PROPERTIES_ID.
   */
  TableColumn* GetColumn_PROPERTIES_ID();

	/**
	 * sets value of PROPERTIES_ID.
	 * @param in value.
	 */
  void Set_PROPERTIES_ID(const long long& in);
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
   * gets value of started.
   * @param out value.
   */
  void Get_started(struct tm& out) const;

  /**
   * gets const column for started.
   * @return column for started.
   */
  const TableColumn* GetConstColumn_started() const;

  /**
   * gets column for started.
   * @return column for started.
   */
  TableColumn* GetColumn_started();

	/**
	 * sets value of started.
	 * @param in value.
	 */
  void Set_started(const struct tm& in);
  /**
   * gets value of modified.
   * @param out value.
   */
  void Get_modified(struct tm& out) const;

  /**
   * gets const column for modified.
   * @return column for modified.
   */
  const TableColumn* GetConstColumn_modified() const;

  /**
   * gets column for modified.
   * @return column for modified.
   */
  TableColumn* GetColumn_modified();

	/**
	 * sets value of modified.
	 * @param in value.
	 */
  void Set_modified(const struct tm& in);
  /**
   * gets value of finished.
   * @param out value.
   */
  void Get_finished(long long& out) const;

  /**
   * gets const column for finished.
   * @return column for finished.
   */
  const TableColumn* GetConstColumn_finished() const;

  /**
   * gets column for finished.
   * @return column for finished.
   */
  TableColumn* GetColumn_finished();

	/**
	 * sets value of finished.
	 * @param in value.
	 */
  void Set_finished(const long long& in);
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
  /**
   * gets value of identifier.
   * @param out value.
   */
  void Get_identifier(std::string& out) const;

  /**
   * gets const column for identifier.
   * @return column for identifier.
   */
  const TableColumn* GetConstColumn_identifier() const;

  /**
   * gets column for identifier.
   * @return column for identifier.
   */
  TableColumn* GetColumn_identifier();

	/**
	 * sets value of identifier.
	 * @param in value.
	 */
  void Set_identifier(const std::string& in);


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
	 * gets rows by a value of RESULTTHREAD_ID.
	 * @param db database connection.
	 * @param fieldValue value of RESULTTHREAD_ID.
	 * @param results contains results.
	 */
    static void GetBy_RESULTTHREAD_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of RESULTTHREAD_ID.
	 * @param db database connection.
	 * @param fieldValue values of RESULTTHREAD_ID.
	 * @param results contains results.
	 */
    static void GetBy_RESULTTHREAD_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of PROPERTIES_ID.
	 * @param db database connection.
	 * @param fieldValue value of PROPERTIES_ID.
	 * @param results contains results.
	 */
    static void GetBy_PROPERTIES_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of PROPERTIES_ID.
	 * @param db database connection.
	 * @param fieldValue values of PROPERTIES_ID.
	 * @param results contains results.
	 */
    static void GetBy_PROPERTIES_ID(
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
	 * gets rows by a value of started.
	 * @param db database connection.
	 * @param fieldValue value of started.
	 * @param results contains results.
	 */
    static void GetBy_started(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of started.
	 * @param db database connection.
	 * @param fieldValue values of started.
	 * @param results contains results.
	 */
    static void GetBy_started(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of modified.
	 * @param db database connection.
	 * @param fieldValue value of modified.
	 * @param results contains results.
	 */
    static void GetBy_modified(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of modified.
	 * @param db database connection.
	 * @param fieldValue values of modified.
	 * @param results contains results.
	 */
    static void GetBy_modified(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);
public:
	/**
	 * gets rows by a value of finished.
	 * @param db database connection.
	 * @param fieldValue value of finished.
	 * @param results contains results.
	 */
    static void GetBy_finished(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of finished.
	 * @param db database connection.
	 * @param fieldValue values of finished.
	 * @param results contains results.
	 */
    static void GetBy_finished(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
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
	/**
	 * gets rows by a value of identifier.
	 * @param db database connection.
	 * @param fieldValue value of identifier.
	 * @param results contains results.
	 */
    static void GetBy_identifier(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);

	/**
	 * gets rows by multiple values of identifier.
	 * @param db database connection.
	 * @param fieldValue values of identifier.
	 * @param results contains results.
	 */
    static void GetBy_identifier(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_RESULTTHREAD_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_RESULTTHREAD_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_RESULTTHREAD_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_RESULTTHREAD_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_PROPERTIES_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_PROPERTIES_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_PROPERTIES_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_PROPERTIES_ID(Statement& stmt);


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
     * creates where condition for a value of RESULTTHREAD_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_RESULTTHREAD_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of RESULTTHREAD_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_RESULTTHREAD_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of PROPERTIES_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_PROPERTIES_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of PROPERTIES_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_PROPERTIES_ID(
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
     * creates where condition for a value of started.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_started(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of started.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_started(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of modified.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_modified(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of modified.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_modified(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of finished.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_finished(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of finished.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_finished(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
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
    /**
     * creates where condition for a value of identifier.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_identifier(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of identifier.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_identifier(
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
     * create a column definition for column RESULTTHREAD_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_RESULTTHREAD_ID();
	/**
     * create a column definition for column PROPERTIES_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_PROPERTIES_ID();
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
     * create a column definition for column started.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_started();
	/**
     * create a column definition for column modified.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_modified();
	/**
     * create a column definition for column finished.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_finished();
	/**
     * create a column definition for column total.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_total();
	/**
     * create a column definition for column identifier.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_identifier();

};

}
