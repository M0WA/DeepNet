#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table searchquery.
 */
class searchqueryTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchqueryTableDefinitionCreateParam();
    virtual ~searchqueryTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
