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
   * gets value of resultXML.
   * @param out value.
   */
  void Get_resultXML(std::string& out) const;

  /**
   * gets const column for resultXML.
   * @return column for resultXML.
   */
  const TableColumn* GetConstColumn_resultXML() const;

  /**
   * gets column for resultXML.
   * @return column for resultXML.
   */
  TableColumn* GetColumn_resultXML();

	/**
	 * sets value of resultXML.
	 * @param in value.
	 */
  void Set_resultXML(const std::string& in);
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
	 * gets rows by a value of resultXML.
	 * @param db database connection.
	 * @param fieldValue value of resultXML.
	 * @param results contains results.
	 */
    static void GetBy_resultXML(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<queryresultsTableBase>& results);

	/**
	 * gets rows by multiple values of resultXML.
	 * @param db database connection.
	 * @param fieldValue values of resultXML.
	 * @param results contains results.
	 */
    static void GetBy_resultXML(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
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
     * creates where condition for a value of resultXML.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_resultXML(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of resultXML.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_resultXML(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
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
     * create a column definition for column resultXML.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_resultXML();
	/**
     * create a column definition for column position.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_position();

};

}
