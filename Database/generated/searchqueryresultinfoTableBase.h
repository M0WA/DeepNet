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
 * @brief wrapper class for database table searchqueryresultinfo
 */
class searchqueryresultinfoTableBase : public TableBase {

private:
    searchqueryresultinfoTableBase(const TableBase& base);

public:
    searchqueryresultinfoTableBase();
    virtual ~searchqueryresultinfoTableBase();

public:
    /**
     * factory function for searchqueryresultinfo's table definition.
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
   * gets value of SEARCHQUERYRESULT_ID.
   * @param out value.
   */
  void Get_SEARCHQUERYRESULT_ID(long long& out) const;

  /**
   * gets const column for SEARCHQUERYRESULT_ID.
   * @return column for SEARCHQUERYRESULT_ID.
   */
  const TableColumn* GetConstColumn_SEARCHQUERYRESULT_ID() const;

  /**
   * gets column for SEARCHQUERYRESULT_ID.
   * @return column for SEARCHQUERYRESULT_ID.
   */
  TableColumn* GetColumn_SEARCHQUERYRESULT_ID();

	/**
	 * sets value of SEARCHQUERYRESULT_ID.
	 * @param in value.
	 */
  void Set_SEARCHQUERYRESULT_ID(const long long& in);
  /**
   * gets value of infotype.
   * @param out value.
   */
  void Get_infotype(long long& out) const;

  /**
   * gets const column for infotype.
   * @return column for infotype.
   */
  const TableColumn* GetConstColumn_infotype() const;

  /**
   * gets column for infotype.
   * @return column for infotype.
   */
  TableColumn* GetColumn_infotype();

	/**
	 * sets value of infotype.
	 * @param in value.
	 */
  void Set_infotype(const long long& in);
  /**
   * gets value of type.
   * @param out value.
   */
  void Get_type(std::string& out) const;

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
  void Set_type(const std::string& in);


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
        SelectResultContainer<searchqueryresultinfoTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);
public:
	/**
	 * gets rows by a value of SEARCHQUERYRESULT_ID.
	 * @param db database connection.
	 * @param fieldValue value of SEARCHQUERYRESULT_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERYRESULT_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);

	/**
	 * gets rows by multiple values of SEARCHQUERYRESULT_ID.
	 * @param db database connection.
	 * @param fieldValue values of SEARCHQUERYRESULT_ID.
	 * @param results contains results.
	 */
    static void GetBy_SEARCHQUERYRESULT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);
public:
	/**
	 * gets rows by a value of infotype.
	 * @param db database connection.
	 * @param fieldValue value of infotype.
	 * @param results contains results.
	 */
    static void GetBy_infotype(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);

	/**
	 * gets rows by multiple values of infotype.
	 * @param db database connection.
	 * @param fieldValue values of infotype.
	 * @param results contains results.
	 */
    static void GetBy_infotype(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);
public:
	/**
	 * gets rows by a value of type.
	 * @param db database connection.
	 * @param fieldValue value of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);

	/**
	 * gets rows by multiple values of type.
	 * @param db database connection.
	 * @param fieldValue values of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<searchqueryresultinfoTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_SEARCHQUERYRESULT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SEARCHQUERYRESULT_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERYRESULT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SEARCHQUERYRESULT_ID(Statement& stmt);


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
     * creates where condition for a value of SEARCHQUERYRESULT_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SEARCHQUERYRESULT_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SEARCHQUERYRESULT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of infotype.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_infotype(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of infotype.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_infotype(
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
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of type.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_type(
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
     * create a column definition for column SEARCHQUERYRESULT_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SEARCHQUERYRESULT_ID();
	/**
     * create a column definition for column infotype.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_infotype();
	/**
     * create a column definition for column type.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_type();

};

}
