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
 * @brief wrapper class for database table urlpathparts
 */
class urlpathpartsTableBase : public TableBase {

private:
    urlpathpartsTableBase(const TableBase& base);

public:
    urlpathpartsTableBase();
    virtual ~urlpathpartsTableBase();

public:
    /**
     * factory function for urlpathparts's table definition.
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
   * gets value of PATHPART_ID.
   * @param out value.
   */
  void Get_PATHPART_ID(long long& out) const;

  /**
   * gets const column for PATHPART_ID.
   * @return column for PATHPART_ID.
   */
  const TableColumn* GetConstColumn_PATHPART_ID() const;

  /**
   * gets column for PATHPART_ID.
   * @return column for PATHPART_ID.
   */
  TableColumn* GetColumn_PATHPART_ID();

	/**
	 * sets value of PATHPART_ID.
	 * @param in value.
	 */
  void Set_PATHPART_ID(const long long& in);
  /**
   * gets value of URLPATHPART_ID_NEXT.
   * @param out value.
   */
  void Get_URLPATHPART_ID_NEXT(long long& out) const;

  /**
   * gets const column for URLPATHPART_ID_NEXT.
   * @return column for URLPATHPART_ID_NEXT.
   */
  const TableColumn* GetConstColumn_URLPATHPART_ID_NEXT() const;

  /**
   * gets column for URLPATHPART_ID_NEXT.
   * @return column for URLPATHPART_ID_NEXT.
   */
  TableColumn* GetColumn_URLPATHPART_ID_NEXT();

	/**
	 * sets value of URLPATHPART_ID_NEXT.
	 * @param in value.
	 */
  void Set_URLPATHPART_ID_NEXT(const long long& in);


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
        SelectResultContainer<urlpathpartsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results);
public:
	/**
	 * gets rows by a value of PATHPART_ID.
	 * @param db database connection.
	 * @param fieldValue value of PATHPART_ID.
	 * @param results contains results.
	 */
    static void GetBy_PATHPART_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results);

	/**
	 * gets rows by multiple values of PATHPART_ID.
	 * @param db database connection.
	 * @param fieldValue values of PATHPART_ID.
	 * @param results contains results.
	 */
    static void GetBy_PATHPART_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results);
public:
	/**
	 * gets rows by a value of URLPATHPART_ID_NEXT.
	 * @param db database connection.
	 * @param fieldValue value of URLPATHPART_ID_NEXT.
	 * @param results contains results.
	 */
    static void GetBy_URLPATHPART_ID_NEXT(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results);

	/**
	 * gets rows by multiple values of URLPATHPART_ID_NEXT.
	 * @param db database connection.
	 * @param fieldValue values of URLPATHPART_ID_NEXT.
	 * @param results contains results.
	 */
    static void GetBy_URLPATHPART_ID_NEXT(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlpathpartsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_PATHPART_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_PATHPART_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_PATHPART_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_PATHPART_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLPATHPART_ID_NEXT(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLPATHPART_ID_NEXT(Statement& stmt);
    static void AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URLPATHPART_ID_NEXT(Statement& stmt);


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
     * creates where condition for a value of PATHPART_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_PATHPART_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of PATHPART_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_PATHPART_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of URLPATHPART_ID_NEXT.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URLPATHPART_ID_NEXT(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URLPATHPART_ID_NEXT.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URLPATHPART_ID_NEXT(
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
     * create a column definition for column PATHPART_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_PATHPART_ID();
	/**
     * create a column definition for column URLPATHPART_ID_NEXT.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URLPATHPART_ID_NEXT();

};

}
