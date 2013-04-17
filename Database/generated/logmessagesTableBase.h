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
 * @brief wrapper class for database table logmessages
 */
class logmessagesTableBase : public TableBase {

private:
    logmessagesTableBase(const TableBase& base);

public:
    logmessagesTableBase();
    virtual ~logmessagesTableBase();

public:
    /**
     * factory function for logmessages's table definition.
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
     * gets value of loglevel.
     * @param out value.
     */
	void Get_loglevel(long long& out) const;

	/**
	 * sets value of loglevel.
	 * @param in value.
	 */
    void Set_loglevel(const long long& in);
    /**
     * gets value of message.
     * @param out value.
     */
	void Get_message(std::string& out) const;

	/**
	 * sets value of message.
	 * @param in value.
	 */
    void Set_message(const std::string& in);
    /**
     * gets value of actiontime.
     * @param out value.
     */
	void Get_actiontime(struct tm& out) const;

	/**
	 * sets value of actiontime.
	 * @param in value.
	 */
    void Set_actiontime(const struct tm& in);
    /**
     * gets value of pid.
     * @param out value.
     */
	void Get_pid(long long& out) const;

	/**
	 * sets value of pid.
	 * @param in value.
	 */
    void Set_pid(const long long& in);
    /**
     * gets value of tid.
     * @param out value.
     */
	void Get_tid(long long& out) const;

	/**
	 * sets value of tid.
	 * @param in value.
	 */
    void Set_tid(const long long& in);
    /**
     * gets value of appName.
     * @param out value.
     */
	void Get_appName(std::string& out) const;

	/**
	 * sets value of appName.
	 * @param in value.
	 */
    void Set_appName(const std::string& in);
    /**
     * gets value of threadName.
     * @param out value.
     */
	void Get_threadName(std::string& out) const;

	/**
	 * sets value of threadName.
	 * @param in value.
	 */
    void Set_threadName(const std::string& in);


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
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of loglevel.
	 * @param db database connection.
	 * @param fieldValue value of loglevel.
	 * @param results contains results.
	 */
    static void GetBy_loglevel(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of loglevel.
	 * @param db database connection.
	 * @param fieldValue values of loglevel.
	 * @param results contains results.
	 */
    static void GetBy_loglevel(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of message.
	 * @param db database connection.
	 * @param fieldValue value of message.
	 * @param results contains results.
	 */
    static void GetBy_message(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of message.
	 * @param db database connection.
	 * @param fieldValue values of message.
	 * @param results contains results.
	 */
    static void GetBy_message(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of actiontime.
	 * @param db database connection.
	 * @param fieldValue value of actiontime.
	 * @param results contains results.
	 */
    static void GetBy_actiontime(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of actiontime.
	 * @param db database connection.
	 * @param fieldValue values of actiontime.
	 * @param results contains results.
	 */
    static void GetBy_actiontime(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of pid.
	 * @param db database connection.
	 * @param fieldValue value of pid.
	 * @param results contains results.
	 */
    static void GetBy_pid(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of pid.
	 * @param db database connection.
	 * @param fieldValue values of pid.
	 * @param results contains results.
	 */
    static void GetBy_pid(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of tid.
	 * @param db database connection.
	 * @param fieldValue value of tid.
	 * @param results contains results.
	 */
    static void GetBy_tid(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of tid.
	 * @param db database connection.
	 * @param fieldValue values of tid.
	 * @param results contains results.
	 */
    static void GetBy_tid(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of appName.
	 * @param db database connection.
	 * @param fieldValue value of appName.
	 * @param results contains results.
	 */
    static void GetBy_appName(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of appName.
	 * @param db database connection.
	 * @param fieldValue values of appName.
	 * @param results contains results.
	 */
    static void GetBy_appName(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);
public:
	/**
	 * gets rows by a value of threadName.
	 * @param db database connection.
	 * @param fieldValue value of threadName.
	 * @param results contains results.
	 */
    static void GetBy_threadName(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);

	/**
	 * gets rows by multiple values of threadName.
	 * @param db database connection.
	 * @param fieldValue values of threadName.
	 * @param results contains results.
	 */
    static void GetBy_threadName(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<logmessagesTableBase>& results);


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
     * creates where condition for a value of loglevel.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_loglevel(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of loglevel.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_loglevel(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of message.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_message(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of message.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_message(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of actiontime.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_actiontime(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of actiontime.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_actiontime(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of pid.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_pid(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of pid.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_pid(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of tid.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_tid(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of tid.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_tid(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of appName.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_appName(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of appName.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_appName(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of threadName.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_threadName(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of threadName.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_threadName(
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
     * create a column definition for column loglevel.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_loglevel();
    /**
     * create a column definition for column message.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_message();
    /**
     * create a column definition for column actiontime.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_actiontime();
    /**
     * create a column definition for column pid.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_pid();
    /**
     * create a column definition for column tid.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_tid();
    /**
     * create a column definition for column appName.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_appName();
    /**
     * create a column definition for column threadName.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_threadName();

};

}
