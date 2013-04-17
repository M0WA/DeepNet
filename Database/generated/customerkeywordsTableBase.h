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
 * @brief wrapper class for database table customerkeywords
 */
class customerkeywordsTableBase : public TableBase {

private:
    customerkeywordsTableBase(const TableBase& base);

public:
    customerkeywordsTableBase();
    virtual ~customerkeywordsTableBase();

public:
    /**
     * factory function for customerkeywords's table definition.
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
     * gets value of keyword.
     * @param out value.
     */
	void Get_keyword(std::string& out) const;

	/**
	 * sets value of keyword.
	 * @param in value.
	 */
    void Set_keyword(const std::string& in);
    /**
     * gets value of target.
     * @param out value.
     */
	void Get_target(std::string& out) const;

	/**
	 * sets value of target.
	 * @param in value.
	 */
    void Set_target(const std::string& in);
    /**
     * gets value of isKeywordRegex.
     * @param out value.
     */
	void Get_isKeywordRegex(long long& out) const;

	/**
	 * sets value of isKeywordRegex.
	 * @param in value.
	 */
    void Set_isKeywordRegex(const long long& in);


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
        SelectResultContainer<customerkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);
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
        SelectResultContainer<customerkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of keyword.
	 * @param db database connection.
	 * @param fieldValue value of keyword.
	 * @param results contains results.
	 */
    static void GetBy_keyword(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of keyword.
	 * @param db database connection.
	 * @param fieldValue values of keyword.
	 * @param results contains results.
	 */
    static void GetBy_keyword(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of target.
	 * @param db database connection.
	 * @param fieldValue value of target.
	 * @param results contains results.
	 */
    static void GetBy_target(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of target.
	 * @param db database connection.
	 * @param fieldValue values of target.
	 * @param results contains results.
	 */
    static void GetBy_target(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of isKeywordRegex.
	 * @param db database connection.
	 * @param fieldValue value of isKeywordRegex.
	 * @param results contains results.
	 */
    static void GetBy_isKeywordRegex(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of isKeywordRegex.
	 * @param db database connection.
	 * @param fieldValue values of isKeywordRegex.
	 * @param results contains results.
	 */
    static void GetBy_isKeywordRegex(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerkeywordsTableBase>& results);


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
     * creates where condition for a value of keyword.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_keyword(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of keyword.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_keyword(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of target.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_target(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of target.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_target(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of isKeywordRegex.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_isKeywordRegex(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of isKeywordRegex.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_isKeywordRegex(
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
     * create a column definition for column keyword.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_keyword();
    /**
     * create a column definition for column target.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_target();
    /**
     * create a column definition for column isKeywordRegex.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_isKeywordRegex();

};

}
