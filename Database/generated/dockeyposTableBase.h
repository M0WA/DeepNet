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
 * @brief wrapper class for database table dockeypos
 */
class dockeyposTableBase : public TableBase {

private:
    dockeyposTableBase(const TableBase& base);

public:
    dockeyposTableBase();
    virtual ~dockeyposTableBase();

public:
    /**
     * factory function for dockeypos's table definition.
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
   * gets value of DOCKEY_ID.
   * @param out value.
   */
  void Get_DOCKEY_ID(long long& out) const;

  /**
   * gets const column for DOCKEY_ID.
   * @return column for DOCKEY_ID.
   */
  const TableColumn* GetConstColumn_DOCKEY_ID() const;

  /**
   * gets column for DOCKEY_ID.
   * @return column for DOCKEY_ID.
   */
  TableColumn* GetColumn_DOCKEY_ID();

	/**
	 * sets value of DOCKEY_ID.
	 * @param in value.
	 */
  void Set_DOCKEY_ID(const long long& in);
  /**
   * gets value of paragraph.
   * @param out value.
   */
  void Get_paragraph(long long& out) const;

  /**
   * gets const column for paragraph.
   * @return column for paragraph.
   */
  const TableColumn* GetConstColumn_paragraph() const;

  /**
   * gets column for paragraph.
   * @return column for paragraph.
   */
  TableColumn* GetColumn_paragraph();

	/**
	 * sets value of paragraph.
	 * @param in value.
	 */
  void Set_paragraph(const long long& in);
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
        SelectResultContainer<dockeyposTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);
public:
	/**
	 * gets rows by a value of DOCKEY_ID.
	 * @param db database connection.
	 * @param fieldValue value of DOCKEY_ID.
	 * @param results contains results.
	 */
    static void GetBy_DOCKEY_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);

	/**
	 * gets rows by multiple values of DOCKEY_ID.
	 * @param db database connection.
	 * @param fieldValue values of DOCKEY_ID.
	 * @param results contains results.
	 */
    static void GetBy_DOCKEY_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);
public:
	/**
	 * gets rows by a value of paragraph.
	 * @param db database connection.
	 * @param fieldValue value of paragraph.
	 * @param results contains results.
	 */
    static void GetBy_paragraph(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);

	/**
	 * gets rows by multiple values of paragraph.
	 * @param db database connection.
	 * @param fieldValue values of paragraph.
	 * @param results contains results.
	 */
    static void GetBy_paragraph(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);
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
        SelectResultContainer<dockeyposTableBase>& results);

	/**
	 * gets rows by multiple values of position.
	 * @param db database connection.
	 * @param fieldValue values of position.
	 * @param results contains results.
	 */
    static void GetBy_position(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyposTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_DOCKEY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_DOCKEY_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_DOCKEY_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_DOCKEY_ID(Statement& stmt);


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
     * creates where condition for a value of DOCKEY_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_DOCKEY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of DOCKEY_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_DOCKEY_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of paragraph.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_paragraph(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of paragraph.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_paragraph(
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
     * create a column definition for column DOCKEY_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_DOCKEY_ID();
	/**
     * create a column definition for column paragraph.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_paragraph();
	/**
     * create a column definition for column position.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_position();

};

}
