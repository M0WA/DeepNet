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
 * @brief wrapper class for database table dataminingalerts
 */
class dataminingalertsTableBase : public TableBase {

private:
    dataminingalertsTableBase(const TableBase& base);

public:
    dataminingalertsTableBase();
    virtual ~dataminingalertsTableBase();

public:
    /**
     * factory function for dataminingalerts's table definition.
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
  /**
   * gets value of param.
   * @param out value.
   */
  void Get_param(std::string& out) const;

  /**
   * gets const column for param.
   * @return column for param.
   */
  const TableColumn* GetConstColumn_param() const;

  /**
   * gets column for param.
   * @return column for param.
   */
  TableColumn* GetColumn_param();

	/**
	 * sets value of param.
	 * @param in value.
	 */
  void Set_param(const std::string& in);


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
        SelectResultContainer<dataminingalertsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results);
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
        SelectResultContainer<dataminingalertsTableBase>& results);

	/**
	 * gets rows by multiple values of type.
	 * @param db database connection.
	 * @param fieldValue values of type.
	 * @param results contains results.
	 */
    static void GetBy_type(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results);
public:
	/**
	 * gets rows by a value of param.
	 * @param db database connection.
	 * @param fieldValue value of param.
	 * @param results contains results.
	 */
    static void GetBy_param(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results);

	/**
	 * gets rows by multiple values of param.
	 * @param db database connection.
	 * @param fieldValue values of param.
	 * @param results contains results.
	 */
    static void GetBy_param(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<dataminingalertsTableBase>& results);


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
     * creates where condition for a value of param.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_param(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of param.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_param(
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
     * create a column definition for column type.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_type();
	/**
     * create a column definition for column param.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_param();

};

}
