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
 * @brief wrapper class for database table customermatchcriteria
 */
class customermatchcriteriaTableBase : public TableBase {

private:
    customermatchcriteriaTableBase(const TableBase& base);

public:
    customermatchcriteriaTableBase();
    virtual ~customermatchcriteriaTableBase();

public:
    /**
     * factory function for customermatchcriteria's table definition.
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
   * gets value of CUSTOMERDOMAIN_ID.
   * @param out value.
   */
  void Get_CUSTOMERDOMAIN_ID(long long& out) const;

  /**
   * gets const column for CUSTOMERDOMAIN_ID.
   * @return column for CUSTOMERDOMAIN_ID.
   */
  const TableColumn* GetConstColumn_CUSTOMERDOMAIN_ID() const;

  /**
   * gets column for CUSTOMERDOMAIN_ID.
   * @return column for CUSTOMERDOMAIN_ID.
   */
  TableColumn* GetColumn_CUSTOMERDOMAIN_ID();

	/**
	 * sets value of CUSTOMERDOMAIN_ID.
	 * @param in value.
	 */
  void Set_CUSTOMERDOMAIN_ID(const long long& in);
  /**
   * gets value of MATCHCRITERIA_ID.
   * @param out value.
   */
  void Get_MATCHCRITERIA_ID(long long& out) const;

  /**
   * gets const column for MATCHCRITERIA_ID.
   * @return column for MATCHCRITERIA_ID.
   */
  const TableColumn* GetConstColumn_MATCHCRITERIA_ID() const;

  /**
   * gets column for MATCHCRITERIA_ID.
   * @return column for MATCHCRITERIA_ID.
   */
  TableColumn* GetColumn_MATCHCRITERIA_ID();

	/**
	 * sets value of MATCHCRITERIA_ID.
	 * @param in value.
	 */
  void Set_MATCHCRITERIA_ID(const long long& in);
  /**
   * gets value of type.
   * @param out value.
   */
  void Get_type(long long& out) const;

  /**
   * gets const column for type.
   * @return column for type.
   */
  const TableColumn* GetConstColumn_type() const;

  /**
   * gets column for type.
   * @return column for type.
   */
  TableColumn* GetColumn_type();

	/**
	 * sets value of type.
	 * @param in value.
	 */
  void Set_type(const long long& in);


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
        SelectResultContainer<customermatchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);
public:
	/**
	 * gets rows by a value of MATCHCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue value of MATCHCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_MATCHCRITERIA_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of MATCHCRITERIA_ID.
	 * @param db database connection.
	 * @param fieldValue values of MATCHCRITERIA_ID.
	 * @param results contains results.
	 */
    static void GetBy_MATCHCRITERIA_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);
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
        SelectResultContainer<customermatchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of type.
	 * @param db database connection.
	 * @param fieldValue values of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customermatchcriteriaTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_MATCHCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_MATCHCRITERIA_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_MATCHCRITERIA_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_MATCHCRITERIA_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of MATCHCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_MATCHCRITERIA_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of MATCHCRITERIA_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_MATCHCRITERIA_ID(
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
     * create a column definition for column CUSTOMERDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERDOMAIN_ID();
	/**
     * create a column definition for column MATCHCRITERIA_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_MATCHCRITERIA_ID();
	/**
     * create a column definition for column type.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_type();

};

}
