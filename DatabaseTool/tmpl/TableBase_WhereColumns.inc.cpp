void __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
    const WhereConditionTableColumnCreateParam& createParam,
    const __TMPL_FIELD_CPP_TYPE__& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = __TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__();
    TableColumn* pCol = TableColumn::CreateInstanceFromValue(pTmpDef,fieldValue);

    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, pCol));
    delete pTmpDef;
}

void __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<__TMPL_FIELD_CPP_TYPE__>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef = __TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__();
    std::vector<TableColumn*> cols = TableColumn::CreateInstancesFromValues(pTmpDef,fieldValue);
    
    container.push_back(WhereConditionTableColumn::CreateInstance(createParam, cols));
    delete pTmpDef;
}
