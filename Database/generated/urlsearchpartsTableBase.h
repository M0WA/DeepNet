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
 * @brief wrapper class for database table urlsearchparts
 */
class urlsearchpartsTableBase : public TableBase {

private:
    urlsearchpartsTableBase(const TableBase& base);

public:
    urlsearchpartsTableBase();
    virtual ~urlsearchpartsTableBase();

public:
    /**
     * factory function for urlsearchparts's table definition.
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
   * gets value of searchpart.
   * @param out value.
   */
  void Get_searchpart(std::string& out) const;

  /**
   * gets const column for searchpart.
   * @return column for searchpart.
   */
  const TableColumn* GetConstColumn_searchpart() const;

  /**
   * gets column for searchpart.
   * @return column for searchpart.
   */
  TableColumn* GetColumn_searchpart();

	/**
	 * sets value of searchpart.
	 * @param in value.
	 */
  void Set_searchpart(const std::string& in);
  /**
   * gets value of md5.
   * @param out value.
   */
  void Get_md5(std::string& out) const;

  /**
   * gets const column for md5.
   * @return column for md5.
   */
  const TableColumn* GetConstColumn_md5() const;

  /**
   * gets column for md5.
   * @return column for md5.
   */
  TableColumn* GetColumn_md5();

	/**
	 * sets value of md5.
	 * @param in value.
	 */
  void Set_md5(const std::string& in);


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
        SelectResultContainer<urlsearchpartsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results);
public:
	/**
	 * gets rows by a value of searchpart.
	 * @param db database connection.
	 * @param fieldValue value of searchpart.
	 * @param results contains results.
	 */
    static void GetBy_searchpart(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results);

	/**
	 * gets rows by multiple values of searchpart.
	 * @param db database connection.
	 * @param fieldValue values of searchpart.
	 * @param results contains results.
	 */
    static void GetBy_searchpart(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results);
public:
	/**
	 * gets rows by a value of md5.
	 * @param db database connection.
	 * @param fieldValue value of md5.
	 * @param results contains results.
	 */
    static void GetBy_md5(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results);

	/**
	 * gets rows by multiple values of md5.
	 * @param db database connection.
	 * @param fieldValue values of md5.
	 * @param results contains results.
	 */
    static void GetBy_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsearchpartsTableBase>& results);


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
     * creates where condition for a value of searchpart.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_searchpart(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of searchpart.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_searchpart(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of md5.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_md5(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of md5.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_md5(
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
     * create a column definition for column searchpart.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_searchpart();
	/**
     * create a column definition for column md5.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_md5();

};

}
