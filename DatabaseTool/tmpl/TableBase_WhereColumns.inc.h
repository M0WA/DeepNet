    /**
     * creates where condition for a value of __TMPL_FIELD_NAME__.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor___TMPL_FIELD_NAME__(
        const WhereConditionTableColumnCreateParam& createParam,
        const __TMPL_FIELD_CPP_TYPE__& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of __TMPL_FIELD_NAME__.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor___TMPL_FIELD_NAME__(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<__TMPL_FIELD_CPP_TYPE__>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
