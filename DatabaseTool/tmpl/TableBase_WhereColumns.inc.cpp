void __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
    const WhereConditionTableColumnCreateParam& createParam,
    const __TMPL_FIELD_CPP_TYPE__& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(__TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstanceFromValue(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}

void __TMPL_TABLE_NAME__TableBase::GetWhereColumnsFor___TMPL_FIELD_NAME__(
    const WhereConditionTableColumnCreateParam& createParam,
    const std::vector<__TMPL_FIELD_CPP_TYPE__>& fieldValue, 
    std::vector<WhereConditionTableColumn*>& container) {

    TableColumnDefinition* pTmpDef(__TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__());
    container.push_back(
      WhereConditionTableColumn::CreateInstance(
        createParam, 
        TableColumn::CreateInstancesFromValues(
          pTmpDef,
          fieldValue
        )
      )
    );
    delete pTmpDef;
}
