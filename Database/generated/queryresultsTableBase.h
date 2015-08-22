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
 * @brief wrapper class for database table queryresults
 */
class queryresultsTableBase : public TableBase {

private:
    queryresultsTableBase(const TableBase& base);

public:
    queryresultsTableBase();
    virtual ~queryresultsTableBase();

public:
    /**
     * factory function for queryresults's table definition.
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
   * gets value of SEARCHQUERY_ID.
   * @param out value.
   */
  void Get_SEARCHQUERY_ID(long long& out) const;

  /**
   * gets const column for SEARCHQUERY_ID.
   * @return column for SEARCHQUERY_ID.
   */
  const TableColumn* GetConstColumn_SEARCHQUERY_ID() const;

  /**
   * gets column for SEARCHQUERY_ID.
   * @return column for SEARCHQUERY_ID.
   */
  TableColumn* GetColumn_SEARCHQUERY_ID();

	/**
	 * sets value of SEARCHQUERY_ID.
	 * @param in value.
	 */
  void Set_SEARCHQUERY_ID(const long long& in);
  /**
   * gets value of URLSTAGE_ID.
   * @param out value.
   */
  void Get_URLSTAGE_ID(long long& out) const;

  /**
   * gets const column for URLSTAGE_ID.
   * @return column for URLSTAGE_ID.
   */
  const TableColumn* GetConstColumn_URLSTAGE_ID() const;

  /**
   * gets column for URLSTAGE_ID.
   * @return column for URLSTAGE_ID.
   */
  TableColumn* GetColumn_URLSTAGE_ID();

	/**
	 * sets value of URLSTAGE_ID.
	 * @param in value.
	 */
  void Set_URLSTAGE_ID(const long long& in);
  /**
   * gets value of URL_ID.
   * @param out value.
   */
  void Get_URL_ID(long long& out) const;

  /**
   * gets const column for URL_ID.
   * @return column for URL_ID.
   */
  const TableColumn* GetConstColumn_URL_ID() const;

  /**
   * gets column for URL_ID.
   * @return column for URL_ID.
   */
  TableColumn* GetColumn_URL_ID();

	/**
	 * sets value of URL_ID.
	 * @param in value.
	 */
  void Set_URL_ID(const long long& in);
  /**
   * gets value of position.
   * @param out value.
   */
  void Get_position(long long& out) const;

  /**
   * gets const column for position.
   * @return column for position.
   */
  const TableColumn* GetConstColumn_position() const;

  /**
   * gets column for position.
   * @return column for position.
   */
  TableColumn* GetColumn_position();

	/**
	 * sets value of position.
	 * @param in value.
	 */
  void Set_position(const long long& in);


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
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);
public:
	/**
	 * gets rows by a value of SEARCHQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue value of SEARCHQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of SEARCHQUERY_ID.
	 * @param db database connection.
	 * @param fieldValue values of SEARCHQUERY_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);
public:
	/**
	 * gets rows by a value of URLSTAGE_ID.
	 * @param db database connection.
	 * @param fieldValue value of URLSTAGE_ID.
	 * @param results contains results.
	 */
    static void GetBy_URLSTAGE_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of URLSTAGE_ID.
	 * @param db database connection.
	 * @param fieldValue values of URLSTAGE_ID.
	 * @param results contains results.
	 */
    static void GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);
public:
	/**
	 * gets rows by a value of URL_ID.
	 * @param db database connection.
	 * @param fieldValue value of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of URL_ID.
	 * @param db database connection.
	 * @param fieldValue values of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);
public:
	/**
	 * gets rows by a value of position.
	 * @param db database connection.
	 * @param fieldValue value of position.
	 * @param results contains results.
	 */
    static void GetBy_position(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of position.
	 * @param db database connection.
	 * @param fieldValue values of position.
	 * @param results contains results.
	 */
    static void GetBy_position(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_SEARCHQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SEARCHQUERY_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERY_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URL_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(Statement& stmt);


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
     * creates where condition for a value of SEARCHQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SEARCHQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SEARCHQUERY_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SEARCHQUERY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of URLSTAGE_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URLSTAGE_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URLSTAGE_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URLSTAGE_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of position.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_position(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of position.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_position(
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
     * create a column definition for column SEARCHQUERY_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SEARCHQUERY_ID();
	/**
     * create a column definition for column URLSTAGE_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URLSTAGE_ID();
	/**
     * create a column definition for column URL_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URL_ID();
	/**
     * create a column definition for column position.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_position();

};

}
