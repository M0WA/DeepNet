void __TMPL_TABLE_NAME__TableBase::Get___TMPL_FIELD_NAME__(__TMPL_FIELD_CPP_TYPE__& out) const {
    GetConstColumnByName("__TMPL_FIELD_NAME__")->Get(out);
}

void __TMPL_TABLE_NAME__TableBase::Set___TMPL_FIELD_NAME__(const __TMPL_FIELD_CPP_TYPE__& in) {
    GetColumnByName("__TMPL_FIELD_NAME__")->Set(in);
}
