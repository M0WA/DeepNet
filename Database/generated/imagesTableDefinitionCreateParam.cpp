#include "imagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "imagesTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

imagesTableDefinitionCreateParam::imagesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"images") {

    CreateColumnDefinitions();
}

imagesTableDefinitionCreateParam::~imagesTableDefinitionCreateParam() {
}

void imagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_ID());

    //creating column definition for SCHEME_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SCHEME_ID());

    //creating column definition for TOPLEVELDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_TOPLEVELDOMAIN_ID());

    //creating column definition for SUBDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SUBDOMAIN_ID());

    //creating column definition for SECONDLEVELDOMAIN_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_SECONDLEVELDOMAIN_ID());

    //creating column definition for port
    columnDefinitions.push_back(imagesTableBase::GetDefinition_port());

    //creating column definition for URLPATHPART_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_URLPATHPART_ID());

    //creating column definition for URLSEARCHPART_ID
    columnDefinitions.push_back(imagesTableBase::GetDefinition_URLSEARCHPART_ID());

    //creating column definition for found_date
    columnDefinitions.push_back(imagesTableBase::GetDefinition_found_date());


	std::vector<std::string> tmpCombined;
	tmpCombined.clear();
	tmpCombined.push_back("SCHEME_ID");
	tmpCombined.push_back("SUBDOMAIN_ID");
	tmpCombined.push_back("SECONDLEVELDOMAIN_ID");
	tmpCombined.push_back("TOPLEVELDOMAIN_ID");
	tmpCombined.push_back("port");
	tmpCombined.push_back("URLPATHPART_ID");
	tmpCombined.push_back("URLSEARCHPART_ID");
	combinedUniqueKeys.push_back(tmpCombined);

}

std::string imagesTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "documents";
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
