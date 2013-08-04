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
 * @brief wrapper class for database table urls
 */
class urlsTableBase : public TableBase {

private:
    urlsTableBase(const TableBase& base);

public:
    urlsTableBase();
    virtual ~urlsTableBase();

public:
    /**
     * factory function for urls's table definition.
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
   * gets value of SCHEME_ID.
   * @param out value.
   */
  void Get_SCHEME_ID(long long& out) const;

  /**
   * gets column for SCHEME_ID.
   * @return column for SCHEME_ID.
   */
  const TableColumn* GetColumn_SCHEME_ID() const;

	/**
	 * sets value of SCHEME_ID.
	 * @param in value.
	 */
  void Set_SCHEME_ID(const long long& in);
  /**
   * gets value of TOPLEVELDOMAIN_ID.
   * @param out value.
   */
  void Get_TOPLEVELDOMAIN_ID(long long& out) const;

  /**
   * gets column for TOPLEVELDOMAIN_ID.
   * @return column for TOPLEVELDOMAIN_ID.
   */
  const TableColumn* GetColumn_TOPLEVELDOMAIN_ID() const;

	/**
	 * sets value of TOPLEVELDOMAIN_ID.
	 * @param in value.
	 */
  void Set_TOPLEVELDOMAIN_ID(const long long& in);
  /**
   * gets value of SUBDOMAIN_ID.
   * @param out value.
   */
  void Get_SUBDOMAIN_ID(long long& out) const;

  /**
   * gets column for SUBDOMAIN_ID.
   * @return column for SUBDOMAIN_ID.
   */
  const TableColumn* GetColumn_SUBDOMAIN_ID() const;

	/**
	 * sets value of SUBDOMAIN_ID.
	 * @param in value.
	 */
  void Set_SUBDOMAIN_ID(const long long& in);
  /**
   * gets value of SECONDLEVELDOMAIN_ID.
   * @param out value.
   */
  void Get_SECONDLEVELDOMAIN_ID(long long& out) const;

  /**
   * gets column for SECONDLEVELDOMAIN_ID.
   * @return column for SECONDLEVELDOMAIN_ID.
   */
  const TableColumn* GetColumn_SECONDLEVELDOMAIN_ID() const;

	/**
	 * sets value of SECONDLEVELDOMAIN_ID.
	 * @param in value.
	 */
  void Set_SECONDLEVELDOMAIN_ID(const long long& in);
  /**
   * gets value of port.
   * @param out value.
   */
  void Get_port(long long& out) const;

  /**
   * gets column for port.
   * @return column for port.
   */
  const TableColumn* GetColumn_port() const;

	/**
	 * sets value of port.
	 * @param in value.
	 */
  void Set_port(const long long& in);
  /**
   * gets value of path_part.
   * @param out value.
   */
  void Get_path_part(std::string& out) const;

  /**
   * gets column for path_part.
   * @return column for path_part.
   */
  const TableColumn* GetColumn_path_part() const;

	/**
	 * sets value of path_part.
	 * @param in value.
	 */
  void Set_path_part(const std::string& in);
  /**
   * gets value of search_part.
   * @param out value.
   */
  void Get_search_part(std::string& out) const;

  /**
   * gets column for search_part.
   * @return column for search_part.
   */
  const TableColumn* GetColumn_search_part() const;

	/**
	 * sets value of search_part.
	 * @param in value.
	 */
  void Set_search_part(const std::string& in);
  /**
   * gets value of url_md5.
   * @param out value.
   */
  void Get_url_md5(std::string& out) const;

  /**
   * gets column for url_md5.
   * @return column for url_md5.
   */
  const TableColumn* GetColumn_url_md5() const;

	/**
	 * sets value of url_md5.
	 * @param in value.
	 */
  void Set_url_md5(const std::string& in);
  /**
   * gets value of found_date.
   * @param out value.
   */
  void Get_found_date(struct tm& out) const;

  /**
   * gets column for found_date.
   * @return column for found_date.
   */
  const TableColumn* GetColumn_found_date() const;

	/**
	 * sets value of found_date.
	 * @param in value.
	 */
  void Set_found_date(const struct tm& in);


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
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of SCHEME_ID.
	 * @param db database connection.
	 * @param fieldValue value of SCHEME_ID.
	 * @param results contains results.
	 */
    static void GetBy_SCHEME_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of SCHEME_ID.
	 * @param db database connection.
	 * @param fieldValue values of SCHEME_ID.
	 * @param results contains results.
	 */
    static void GetBy_SCHEME_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of TOPLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of TOPLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of TOPLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of TOPLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_TOPLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of SUBDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of SUBDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of SUBDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of SUBDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SUBDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of port.
	 * @param db database connection.
	 * @param fieldValue value of port.
	 * @param results contains results.
	 */
    static void GetBy_port(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of port.
	 * @param db database connection.
	 * @param fieldValue values of port.
	 * @param results contains results.
	 */
    static void GetBy_port(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of path_part.
	 * @param db database connection.
	 * @param fieldValue value of path_part.
	 * @param results contains results.
	 */
    static void GetBy_path_part(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of path_part.
	 * @param db database connection.
	 * @param fieldValue values of path_part.
	 * @param results contains results.
	 */
    static void GetBy_path_part(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of search_part.
	 * @param db database connection.
	 * @param fieldValue value of search_part.
	 * @param results contains results.
	 */
    static void GetBy_search_part(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of search_part.
	 * @param db database connection.
	 * @param fieldValue values of search_part.
	 * @param results contains results.
	 */
    static void GetBy_search_part(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of url_md5.
	 * @param db database connection.
	 * @param fieldValue value of url_md5.
	 * @param results contains results.
	 */
    static void GetBy_url_md5(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of url_md5.
	 * @param db database connection.
	 * @param fieldValue values of url_md5.
	 * @param results contains results.
	 */
    static void GetBy_url_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);
public:
	/**
	 * gets rows by a value of found_date.
	 * @param db database connection.
	 * @param fieldValue value of found_date.
	 * @param results contains results.
	 */
    static void GetBy_found_date(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);

	/**
	 * gets rows by multiple values of found_date.
	 * @param db database connection.
	 * @param fieldValue values of found_date.
	 * @param results contains results.
	 */
    static void GetBy_found_date(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_SCHEME_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SCHEME_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SCHEME_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SCHEME_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_TOPLEVELDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_TOPLEVELDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_SUBDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SUBDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SUBDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SUBDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt);


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
     * creates where condition for a value of SCHEME_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SCHEME_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SCHEME_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SCHEME_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of TOPLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of TOPLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_TOPLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of SUBDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SUBDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SUBDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SUBDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of port.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_port(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of port.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_port(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of path_part.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_path_part(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of path_part.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_path_part(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of search_part.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_search_part(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of search_part.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_search_part(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of url_md5.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_url_md5(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of url_md5.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_url_md5(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of found_date.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_found_date(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of found_date.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_found_date(
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
     * create a column definition for column SCHEME_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SCHEME_ID();
	/**
     * create a column definition for column TOPLEVELDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_TOPLEVELDOMAIN_ID();
	/**
     * create a column definition for column SUBDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SUBDOMAIN_ID();
	/**
     * create a column definition for column SECONDLEVELDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SECONDLEVELDOMAIN_ID();
	/**
     * create a column definition for column port.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_port();
	/**
     * create a column definition for column path_part.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_path_part();
	/**
     * create a column definition for column search_part.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_search_part();
	/**
     * create a column definition for column url_md5.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_url_md5();
	/**
     * create a column definition for column found_date.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_found_date();

};

}
