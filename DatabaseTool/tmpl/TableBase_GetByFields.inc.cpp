void __TMPL_TABLE_NAME__TableBase::GetBy___TMPL_FIELD_NAME__(
        DatabaseConnection* db, 
        const __TMPL_FIELD_CPP_TYPE__& fieldValue, 
        SelectResultContainer<__TMPL_TABLE_NAME__TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(__TMPL_TABLE_NAME__TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}

void __TMPL_TABLE_NAME__TableBase::GetBy___TMPL_FIELD_NAME__(
        DatabaseConnection* db, 
        const std::vector<__TMPL_FIELD_CPP_TYPE__>& fieldValue, 
        SelectResultContainer<__TMPL_TABLE_NAME__TableBase>& results) {
    
    std::vector<WhereConditionTableColumn*> container;
    __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
        WhereConditionTableColumnCreateParam( WhereCondition::Equals(), WhereCondition::InitialComp() ),
        fieldValue, 
        container);

    SelectStatement stmt(__TMPL_TABLE_NAME__TableBase::CreateTableDefinition());
    stmt.SelectAllColumns();
    stmt.Where().AddColumns( container );
    db->Select(stmt,results);
}
