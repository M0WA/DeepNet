void __TMPL_TABLE_NAME__TableBase::Get___TMPL_FIELD_NAME__(__TMPL_FIELD_CPP_TYPE__& out) const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_IBM_DB2:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("__TMPL_FIELD_NAME__");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    }

    GetConstColumnByName(fieldName)->Get(out);
}

const TableColumn* __TMPL_TABLE_NAME__TableBase::GetColumn___TMPL_FIELD_NAME__() const {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_IBM_DB2:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("__TMPL_FIELD_NAME__");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    }

    return GetConstColumnByName(fieldName);
}

void __TMPL_TABLE_NAME__TableBase::Set___TMPL_FIELD_NAME__(const __TMPL_FIELD_CPP_TYPE__& in) {

    std::string fieldName;
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_IBM_DB2:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    case DB_POSTGRESQL:
      fieldName = tools::StringTools::ToLowerNP("__TMPL_FIELD_NAME__");
      break;
    case DB_INVALID_TYPE:
    default:
      fieldName = "__TMPL_FIELD_NAME__";
      break;
    }

    GetColumnByName(fieldName)->Set(in);
}
