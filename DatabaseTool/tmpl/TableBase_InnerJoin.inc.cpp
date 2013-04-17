void __TMPL_TABLE_NAME__TableBase::AddInnerJoinLeftSideOn___TMPL_FIELD_NAME__(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = __TMPL_JOIN_TABLE_NAME__TableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = __TMPL_JOIN_TABLE_NAME__TableBase::GetDefinition___TMPL_JOIN_FIELD_NAME__();
    TableDefinition*       joinTableDef        = __TMPL_TABLE_NAME__TableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = __TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = joinTableAlias;
    entry.joinColumnAlias        = joinColumnAlias;
    entry.referencedTableAlias   = referencedTableAlias;
    entry.referencedColumnsAlias = referencedColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void __TMPL_TABLE_NAME__TableBase::AddInnerJoinLeftSideOn___TMPL_FIELD_NAME__(Statement& stmt) {

    AddInnerJoinLeftSideOn___TMPL_FIELD_NAME__("","","","",stmt);
}

void __TMPL_TABLE_NAME__TableBase::AddInnerJoinRightSideOn___TMPL_FIELD_NAME__(
    const std::string& joinTableAlias,
    const std::string& joinColumnAlias,
    const std::string& referencedTableAlias,
    const std::string& referencedColumnAlias,
    Statement& stmt ) {

    TableDefinition*       referencedTableDef  = __TMPL_TABLE_NAME__TableBase::CreateTableDefinition();
    TableColumnDefinition* referencedColumnDef = __TMPL_TABLE_NAME__TableBase::GetDefinition___TMPL_FIELD_NAME__();
    TableDefinition*       joinTableDef        = __TMPL_JOIN_TABLE_NAME__TableBase::CreateTableDefinition();
    TableColumnDefinition* joinColumnDef       = __TMPL_JOIN_TABLE_NAME__TableBase::GetDefinition___TMPL_JOIN_FIELD_NAME__();

    InnerJoinEntry entry(joinTableDef,joinColumnDef,referencedTableDef,referencedColumnDef);
    entry.joinTableAlias         = referencedTableAlias;
    entry.joinColumnAlias        = referencedColumnAlias;
    entry.referencedTableAlias   = joinTableAlias;
    entry.referencedColumnsAlias = joinColumnAlias;
    stmt.InnerJoin().AddInnerJoin(entry);
}

void __TMPL_TABLE_NAME__TableBase::AddInnerJoinRightSideOn___TMPL_FIELD_NAME__(Statement& stmt) {

    AddInnerJoinRightSideOn___TMPL_FIELD_NAME__("","","","",stmt);
}
