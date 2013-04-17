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
 * @brief wrapper class for database table urlstages
 */
class urlstagesTableBase : public TableBase {

private:
    urlstagesTableBase(const TableBase& base);

public:
    urlstagesTableBase();
    virtual ~urlstagesTableBase();

public:
    /**
     * factory function for urlstages's table definition.
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
     * gets value of URL_ID.
     * @param out value.
     */
	void Get_URL_ID(long long& out) const;

	/**
	 * sets value of URL_ID.
	 * @param in value.
	 */
    void Set_URL_ID(const long long& in);
    /**
     * gets value of response_code.
     * @param out value.
     */
	void Get_response_code(long long& out) const;

	/**
	 * sets value of response_code.
	 * @param in value.
	 */
    void Set_response_code(const long long& in);
    /**
     * gets value of content_md5.
     * @param out value.
     */
	void Get_content_md5(std::string& out) const;

	/**
	 * sets value of content_md5.
	 * @param in value.
	 */
    void Set_content_md5(const std::string& in);
    /**
     * gets value of last_change.
     * @param out value.
     */
	void Get_last_change(struct tm& out) const;

	/**
	 * sets value of last_change.
	 * @param in value.
	 */
    void Set_last_change(const struct tm& in);
    /**
     * gets value of redirect_count.
     * @param out value.
     */
	void Get_redirect_count(long long& out) const;

	/**
	 * sets value of redirect_count.
	 * @param in value.
	 */
    void Set_redirect_count(const long long& in);
    /**
     * gets value of download_speed.
     * @param out value.
     */
	void Get_download_speed(long long& out) const;

	/**
	 * sets value of download_speed.
	 * @param in value.
	 */
    void Set_download_speed(const long long& in);
    /**
     * gets value of upload_speed.
     * @param out value.
     */
	void Get_upload_speed(long long& out) const;

	/**
	 * sets value of upload_speed.
	 * @param in value.
	 */
    void Set_upload_speed(const long long& in);
    /**
     * gets value of content_length.
     * @param out value.
     */
	void Get_content_length(long long& out) const;

	/**
	 * sets value of content_length.
	 * @param in value.
	 */
    void Set_content_length(const long long& in);
    /**
     * gets value of content_type.
     * @param out value.
     */
	void Get_content_type(std::string& out) const;

	/**
	 * sets value of content_type.
	 * @param in value.
	 */
    void Set_content_type(const std::string& in);
    /**
     * gets value of primary_ip.
     * @param out value.
     */
	void Get_primary_ip(long long& out) const;

	/**
	 * sets value of primary_ip.
	 * @param in value.
	 */
    void Set_primary_ip(const long long& in);
    /**
     * gets value of primary_port.
     * @param out value.
     */
	void Get_primary_port(long long& out) const;

	/**
	 * sets value of primary_port.
	 * @param in value.
	 */
    void Set_primary_port(const long long& in);
    /**
     * gets value of int_links.
     * @param out value.
     */
	void Get_int_links(long long& out) const;

	/**
	 * sets value of int_links.
	 * @param in value.
	 */
    void Set_int_links(const long long& in);
    /**
     * gets value of ext_links.
     * @param out value.
     */
	void Get_ext_links(long long& out) const;

	/**
	 * sets value of ext_links.
	 * @param in value.
	 */
    void Set_ext_links(const long long& in);
    /**
     * gets value of download_time.
     * @param out value.
     */
	void Get_download_time(long long& out) const;

	/**
	 * sets value of download_time.
	 * @param in value.
	 */
    void Set_download_time(const long long& in);
    /**
     * gets value of html_errors.
     * @param out value.
     */
	void Get_html_errors(long long& out) const;

	/**
	 * sets value of html_errors.
	 * @param in value.
	 */
    void Set_html_errors(const long long& in);
    /**
     * gets value of found_date.
     * @param out value.
     */
	void Get_found_date(struct tm& out) const;

	/**
	 * sets value of found_date.
	 * @param in value.
	 */
    void Set_found_date(const struct tm& in);


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
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of URL_ID.
	 * @param db database connection.
	 * @param fieldValue value of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of URL_ID.
	 * @param db database connection.
	 * @param fieldValue values of URL_ID.
	 * @param results contains results.
	 */
    static void GetBy_URL_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of response_code.
	 * @param db database connection.
	 * @param fieldValue value of response_code.
	 * @param results contains results.
	 */
    static void GetBy_response_code(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of response_code.
	 * @param db database connection.
	 * @param fieldValue values of response_code.
	 * @param results contains results.
	 */
    static void GetBy_response_code(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of content_md5.
	 * @param db database connection.
	 * @param fieldValue value of content_md5.
	 * @param results contains results.
	 */
    static void GetBy_content_md5(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of content_md5.
	 * @param db database connection.
	 * @param fieldValue values of content_md5.
	 * @param results contains results.
	 */
    static void GetBy_content_md5(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of last_change.
	 * @param db database connection.
	 * @param fieldValue value of last_change.
	 * @param results contains results.
	 */
    static void GetBy_last_change(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of last_change.
	 * @param db database connection.
	 * @param fieldValue values of last_change.
	 * @param results contains results.
	 */
    static void GetBy_last_change(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of redirect_count.
	 * @param db database connection.
	 * @param fieldValue value of redirect_count.
	 * @param results contains results.
	 */
    static void GetBy_redirect_count(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of redirect_count.
	 * @param db database connection.
	 * @param fieldValue values of redirect_count.
	 * @param results contains results.
	 */
    static void GetBy_redirect_count(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of download_speed.
	 * @param db database connection.
	 * @param fieldValue value of download_speed.
	 * @param results contains results.
	 */
    static void GetBy_download_speed(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of download_speed.
	 * @param db database connection.
	 * @param fieldValue values of download_speed.
	 * @param results contains results.
	 */
    static void GetBy_download_speed(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of upload_speed.
	 * @param db database connection.
	 * @param fieldValue value of upload_speed.
	 * @param results contains results.
	 */
    static void GetBy_upload_speed(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of upload_speed.
	 * @param db database connection.
	 * @param fieldValue values of upload_speed.
	 * @param results contains results.
	 */
    static void GetBy_upload_speed(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of content_length.
	 * @param db database connection.
	 * @param fieldValue value of content_length.
	 * @param results contains results.
	 */
    static void GetBy_content_length(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of content_length.
	 * @param db database connection.
	 * @param fieldValue values of content_length.
	 * @param results contains results.
	 */
    static void GetBy_content_length(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of content_type.
	 * @param db database connection.
	 * @param fieldValue value of content_type.
	 * @param results contains results.
	 */
    static void GetBy_content_type(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of content_type.
	 * @param db database connection.
	 * @param fieldValue values of content_type.
	 * @param results contains results.
	 */
    static void GetBy_content_type(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of primary_ip.
	 * @param db database connection.
	 * @param fieldValue value of primary_ip.
	 * @param results contains results.
	 */
    static void GetBy_primary_ip(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of primary_ip.
	 * @param db database connection.
	 * @param fieldValue values of primary_ip.
	 * @param results contains results.
	 */
    static void GetBy_primary_ip(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of primary_port.
	 * @param db database connection.
	 * @param fieldValue value of primary_port.
	 * @param results contains results.
	 */
    static void GetBy_primary_port(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of primary_port.
	 * @param db database connection.
	 * @param fieldValue values of primary_port.
	 * @param results contains results.
	 */
    static void GetBy_primary_port(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of int_links.
	 * @param db database connection.
	 * @param fieldValue value of int_links.
	 * @param results contains results.
	 */
    static void GetBy_int_links(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of int_links.
	 * @param db database connection.
	 * @param fieldValue values of int_links.
	 * @param results contains results.
	 */
    static void GetBy_int_links(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of ext_links.
	 * @param db database connection.
	 * @param fieldValue value of ext_links.
	 * @param results contains results.
	 */
    static void GetBy_ext_links(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of ext_links.
	 * @param db database connection.
	 * @param fieldValue values of ext_links.
	 * @param results contains results.
	 */
    static void GetBy_ext_links(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of download_time.
	 * @param db database connection.
	 * @param fieldValue value of download_time.
	 * @param results contains results.
	 */
    static void GetBy_download_time(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of download_time.
	 * @param db database connection.
	 * @param fieldValue values of download_time.
	 * @param results contains results.
	 */
    static void GetBy_download_time(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of html_errors.
	 * @param db database connection.
	 * @param fieldValue value of html_errors.
	 * @param results contains results.
	 */
    static void GetBy_html_errors(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of html_errors.
	 * @param db database connection.
	 * @param fieldValue values of html_errors.
	 * @param results contains results.
	 */
    static void GetBy_html_errors(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);
public:
	/**
	 * gets rows by a value of found_date.
	 * @param db database connection.
	 * @param fieldValue value of found_date.
	 * @param results contains results.
	 */
    static void GetBy_found_date(
        DatabaseConnection* db,
        const struct tm& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);

	/**
	 * gets rows by multiple values of found_date.
	 * @param db database connection.
	 * @param fieldValue values of found_date.
	 * @param results contains results.
	 */
    static void GetBy_found_date(
        DatabaseConnection* db, 
        const std::vector<struct tm>& fieldValue, 
        SelectResultContainer<urlstagesTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URL_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URL_ID(Statement& stmt);


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
     * creates where condition for a value of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URL_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URL_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of response_code.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_response_code(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of response_code.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_response_code(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of content_md5.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_content_md5(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of content_md5.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_content_md5(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of last_change.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_last_change(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of last_change.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_last_change(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of redirect_count.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_redirect_count(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of redirect_count.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_redirect_count(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of download_speed.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_download_speed(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of download_speed.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_download_speed(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of upload_speed.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_upload_speed(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of upload_speed.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_upload_speed(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of content_length.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_content_length(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of content_length.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_content_length(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of content_type.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_content_type(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of content_type.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_content_type(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of primary_ip.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_primary_ip(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of primary_ip.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_primary_ip(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of primary_port.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_primary_port(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of primary_port.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_primary_port(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of int_links.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_int_links(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of int_links.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_int_links(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of ext_links.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_ext_links(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of ext_links.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_ext_links(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of download_time.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_download_time(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of download_time.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_download_time(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of html_errors.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_html_errors(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of html_errors.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_html_errors(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of found_date.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_found_date(
        const WhereConditionTableColumnCreateParam& createParam,
        const struct tm& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of found_date.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_found_date(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<struct tm>& fieldValue, 
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
     * create a column definition for column URL_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URL_ID();
	/**
     * create a column definition for column response_code.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_response_code();
	/**
     * create a column definition for column content_md5.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_content_md5();
	/**
     * create a column definition for column last_change.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_last_change();
	/**
     * create a column definition for column redirect_count.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_redirect_count();
	/**
     * create a column definition for column download_speed.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_download_speed();
	/**
     * create a column definition for column upload_speed.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_upload_speed();
	/**
     * create a column definition for column content_length.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_content_length();
	/**
     * create a column definition for column content_type.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_content_type();
	/**
     * create a column definition for column primary_ip.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_primary_ip();
	/**
     * create a column definition for column primary_port.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_primary_port();
	/**
     * create a column definition for column int_links.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_int_links();
	/**
     * create a column definition for column ext_links.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_ext_links();
	/**
     * create a column definition for column download_time.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_download_time();
	/**
     * create a column definition for column html_errors.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_html_errors();
	/**
     * create a column definition for column found_date.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_found_date();

};

}
