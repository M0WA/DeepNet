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
 * @brief wrapper class for database table customerproducts
 */
class customerproductsTableBase : public TableBase {

private:
    customerproductsTableBase(const TableBase& base);

public:
    customerproductsTableBase();
    virtual ~customerproductsTableBase();

public:
    /**
     * factory function for customerproducts's table definition.
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
	 * sets value of CUSTOMERDOMAIN_ID.
	 * @param in value.
	 */
    void Set_CUSTOMERDOMAIN_ID(const long long& in);
    /**
     * gets value of productNo.
     * @param out value.
     */
	void Get_productNo(std::string& out) const;

	/**
	 * sets value of productNo.
	 * @param in value.
	 */
    void Set_productNo(const std::string& in);
    /**
     * gets value of productName.
     * @param out value.
     */
	void Get_productName(std::string& out) const;

	/**
	 * sets value of productName.
	 * @param in value.
	 */
    void Set_productName(const std::string& in);
    /**
     * gets value of productBrand.
     * @param out value.
     */
	void Get_productBrand(std::string& out) const;

	/**
	 * sets value of productBrand.
	 * @param in value.
	 */
    void Set_productBrand(const std::string& in);


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
        SelectResultContainer<customerproductsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);
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
        SelectResultContainer<customerproductsTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);
public:
	/**
	 * gets rows by a value of productNo.
	 * @param db database connection.
	 * @param fieldValue value of productNo.
	 * @param results contains results.
	 */
    static void GetBy_productNo(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);

	/**
	 * gets rows by multiple values of productNo.
	 * @param db database connection.
	 * @param fieldValue values of productNo.
	 * @param results contains results.
	 */
    static void GetBy_productNo(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);
public:
	/**
	 * gets rows by a value of productName.
	 * @param db database connection.
	 * @param fieldValue value of productName.
	 * @param results contains results.
	 */
    static void GetBy_productName(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);

	/**
	 * gets rows by multiple values of productName.
	 * @param db database connection.
	 * @param fieldValue values of productName.
	 * @param results contains results.
	 */
    static void GetBy_productName(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);
public:
	/**
	 * gets rows by a value of productBrand.
	 * @param db database connection.
	 * @param fieldValue value of productBrand.
	 * @param results contains results.
	 */
    static void GetBy_productBrand(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);

	/**
	 * gets rows by multiple values of productBrand.
	 * @param db database connection.
	 * @param fieldValue values of productBrand.
	 * @param results contains results.
	 */
    static void GetBy_productBrand(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerproductsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);


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
     * creates where condition for a value of productNo.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_productNo(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of productNo.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_productNo(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of productName.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_productName(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of productName.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_productName(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of productBrand.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_productBrand(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of productBrand.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_productBrand(
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
     * create a column definition for column CUSTOMERDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERDOMAIN_ID();
	/**
     * create a column definition for column productNo.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_productNo();
	/**
     * create a column definition for column productName.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_productName();
	/**
     * create a column definition for column productBrand.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_productBrand();

};

}
