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
 * @brief wrapper class for database table customermatchcriteriagrouptype
 */
class customermatchcriteriagrouptypeTableBase : public TableBase {

private:
    customermatchcriteriagrouptypeTableBase(const TableBase& base);

public:
    customermatchcriteriagrouptypeTableBase();
    virtual ~customermatchcriteriagrouptypeTableBase();

public:
    /**
     * factory function for customermatchcriteriagrouptype's table definition.
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
   * gets value of CUSTOMERMATCHCRITERIA_ID.
   * @param out value.
   */
  void Get_CUSTOMERMATCHCRITERIA_ID(long long& out) const;

  /**
   * gets column for CUSTOMERMATCHCRITERIA_ID.
   * @return column for CUSTOMERMATCHCRITERIA_ID.
   */
  const TableColumn* GetColumn_CUSTOMERMATCHCRITERIA_ID() const;

	/**
	 * sets value of CUSTOMERMATCHCRITERIA_ID.
	 * @param in value.
	 */
  void Set_CUSTOMERMATCHCRITERIA_ID(const long long& in);
  /**
   * gets value of type.
   * @param out value.
   */
  void Get_type(long long& out) const;

  /**
   * gets column for type.
   * @return column for type.
   */
  const TableColumn* GetColumn_type() const;

	/**
	 * sets value of type.
	 * @param in value.
	 */
  void Set_type(const long long& in);
  /**
   * gets value of groupPosition.
   * @param out value.
   */
  void Get_groupPosition(long long& out) const;

  /**
   * gets column for groupPosition.
   * @return column for groupPosition.
   */
  const TableColumn* GetColumn_groupPosition() const;

	/**
	 * sets value of groupPosition.
	 * @param in value.
	 */
  void Set_groupPosition(const long long& in);
  /**
   * gets value of isPrimaryKey.
   * @param out value.
   */
  void Get_isPrimaryKey(long long& out) const;

  /**
   * gets column for isPrimaryKey.
   * @return column for isPrimaryKey.
   */
  const TableColumn* GetColumn_isPrimaryKey() const;

	/**
	 * sets value of isPrimaryKey.
	 * @param in value.
	 */
  void Set_isPrimaryKey(const long long& in);


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
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMERMATCHCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMERMATCHCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERMATCHCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERMATCHCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERMATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);
public:
	/**
	 * gets rows by a value of type.
	 * @param db database connection.
	 * @param fieldValue value of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);

	/**
	 * gets rows by multiple values of type.
	 * @param db database connection.
	 * @param fieldValue values of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);
public:
	/**
	 * gets rows by a value of groupPosition.
	 * @param db database connection.
	 * @param fieldValue value of groupPosition.
	 * @param results contains results.
	 */
    static void GetBy_groupPosition(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);

	/**
	 * gets rows by multiple values of groupPosition.
	 * @param db database connection.
	 * @param fieldValue values of groupPosition.
	 * @param results contains results.
	 */
    static void GetBy_groupPosition(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);
public:
	/**
	 * gets rows by a value of isPrimaryKey.
	 * @param db database connection.
	 * @param fieldValue value of isPrimaryKey.
	 * @param results contains results.
	 */
    static void GetBy_isPrimaryKey(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);

	/**
	 * gets rows by multiple values of isPrimaryKey.
	 * @param db database connection.
	 * @param fieldValue values of isPrimaryKey.
	 * @param results contains results.
	 */
    static void GetBy_isPrimaryKey(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriagrouptypeTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERMATCHCRITERIA_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMERMATCHCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMERMATCHCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMERMATCHCRITERIA_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of type.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_type(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of type.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_type(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of groupPosition.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_groupPosition(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of groupPosition.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_groupPosition(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of isPrimaryKey.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_isPrimaryKey(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of isPrimaryKey.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_isPrimaryKey(
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
     * create a column definition for column CUSTOMERMATCHCRITERIA_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERMATCHCRITERIA_ID();
	/**
     * create a column definition for column type.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_type();
	/**
     * create a column definition for column groupPosition.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_groupPosition();
	/**
     * create a column definition for column isPrimaryKey.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_isPrimaryKey();

};

}
