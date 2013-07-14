#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table keywordquery.
 */
class keywordqueryTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    keywordqueryTableDefinitionCreateParam();
    virtual ~keywordqueryTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
