#include "urlstagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "urlstagesTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

urlstagesTableDefinitionCreateParam::urlstagesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"urlstages") {

    CreateColumnDefinitions();
}

urlstagesTableDefinitionCreateParam::~urlstagesTableDefinitionCreateParam() {
}

void urlstagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_ID());

    //creating column definition for URL_ID
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_URL_ID());

    //creating column definition for response_code
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_response_code());

    //creating column definition for content_md5
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_content_md5());

    //creating column definition for last_change
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_last_change());

    //creating column definition for redirect_count
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_redirect_count());

    //creating column definition for download_speed
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_download_speed());

    //creating column definition for upload_speed
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_upload_speed());

    //creating column definition for content_length
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_content_length());

    //creating column definition for content_type
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_content_type());

    //creating column definition for primary_ip
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_primary_ip());

    //creating column definition for primary_port
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_primary_port());

    //creating column definition for int_links
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_int_links());

    //creating column definition for ext_links
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_ext_links());

    //creating column definition for download_time
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_download_time());

    //creating column definition for html_errors
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_html_errors());

    //creating column definition for found_date
    columnDefinitions.push_back(urlstagesTableBase::GetDefinition_found_date());

}

std::string urlstagesTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "contents";
    case DB_IBM_DB2:
      return "deepnet";
    case DB_POSTGRESQL:
      return "deepnet.public";
    case DB_INVALID_TYPE:
    default:
      return "";
    }
}

}
