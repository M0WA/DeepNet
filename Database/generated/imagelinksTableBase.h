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
 * @brief wrapper class for database table imagelinks
 */
class imagelinksTableBase : public TableBase {

private:
    imagelinksTableBase(const TableBase& base);

public:
    imagelinksTableBase();
    virtual ~imagelinksTableBase();

public:
    /**
     * factory function for imagelinks's table definition.
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
   * gets value of TARGET_URL_ID.
   * @param out value.
   */
  void Get_TARGET_URL_ID(long long& out) const;

  /**
   * gets const column for TARGET_URL_ID.
   * @return column for TARGET_URL_ID.
   */
  const TableColumn* GetConstColumn_TARGET_URL_ID() const;

  /**
   * gets column for TARGET_URL_ID.
   * @return column for TARGET_URL_ID.
   */
  TableColumn* GetColumn_TARGET_URL_ID();

	/**
	 * sets value of TARGET_URL_ID.
	 * @param in value.
	 */
  void Set_TARGET_URL_ID(const long long& in);
  /**
   * gets value of IMAGE_URL_ID.
   * @param out value.
   */
  void Get_IMAGE_URL_ID(long long& out) const;

  /**
   * gets const column for IMAGE_URL_ID.
   * @return column for IMAGE_URL_ID.
   */
  const TableColumn* GetConstColumn_IMAGE_URL_ID() const;

  /**
   * gets column for IMAGE_URL_ID.
   * @return column for IMAGE_URL_ID.
   */
  TableColumn* GetColumn_IMAGE_URL_ID();

	/**
	 * sets value of IMAGE_URL_ID.
	 * @param in value.
	 */
  void Set_IMAGE_URL_ID(const long long& in);
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
        SelectResultContainer<imagelinksTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);
public:
	/**
	 * gets rows by a value of TARGET_URL_ID.
	 * @param db database connection.
	 * @param fieldValue value of TARGET_URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_TARGET_URL_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);

	/**
	 * gets rows by multiple values of TARGET_URL_ID.
	 * @param db database connection.
	 * @param fieldValue values of TARGET_URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_TARGET_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);
public:
	/**
	 * gets rows by a value of IMAGE_URL_ID.
	 * @param db database connection.
	 * @param fieldValue value of IMAGE_URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_IMAGE_URL_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);

	/**
	 * gets rows by multiple values of IMAGE_URL_ID.
	 * @param db database connection.
	 * @param fieldValue values of IMAGE_URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_IMAGE_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);
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
        SelectResultContainer<imagelinksTableBase>& results);

	/**
	 * gets rows by multiple values of URLSTAGE_ID.
	 * @param db database connection.
	 * @param fieldValue values of URLSTAGE_ID.
	 * @param results contains results.
	 */
    static void GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<imagelinksTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_TARGET_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_TARGET_URL_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_TARGET_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_TARGET_URL_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_IMAGE_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_IMAGE_URL_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_IMAGE_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_IMAGE_URL_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt);


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
     * creates where condition for a value of TARGET_URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_TARGET_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of TARGET_URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_TARGET_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of IMAGE_URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_IMAGE_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of IMAGE_URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_IMAGE_URL_ID(
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
     * create a column definition for column TARGET_URL_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_TARGET_URL_ID();
	/**
     * create a column definition for column IMAGE_URL_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_IMAGE_URL_ID();
	/**
     * create a column definition for column URLSTAGE_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URLSTAGE_ID();

};

}
