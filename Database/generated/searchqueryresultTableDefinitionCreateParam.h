#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table searchqueryresult.
 */
class searchqueryresultTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchqueryresultTableDefinitionCreateParam();
    virtual ~searchqueryresultTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
