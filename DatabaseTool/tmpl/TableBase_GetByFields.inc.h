public:
	/**
	 * gets rows by a value of __TMPL_FIELD_NAME__.
	 * @param db database connection.
	 * @param fieldValue value of __TMPL_FIELD_NAME__.
	 * @param results contains results.
	 */
    static void GetBy___TMPL_FIELD_NAME__(
        DatabaseConnection* db,
        const __TMPL_FIELD_CPP_TYPE__& fieldValue, 
        SelectResultContainer<__TMPL_TABLE_NAME__TableBase>& results);

	/**
	 * gets rows by multiple values of __TMPL_FIELD_NAME__.
	 * @param db database connection.
	 * @param fieldValue values of __TMPL_FIELD_NAME__.
	 * @param results contains results.
	 */
    static void GetBy___TMPL_FIELD_NAME__(
        DatabaseConnection* db, 
        const std::vector<__TMPL_FIELD_CPP_TYPE__>& fieldValue, 
        SelectResultContainer<__TMPL_TABLE_NAME__TableBase>& results);
