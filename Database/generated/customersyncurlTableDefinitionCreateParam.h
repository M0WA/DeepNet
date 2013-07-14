#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customersyncurl.
 */
class customersyncurlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customersyncurlTableDefinitionCreateParam();
    virtual ~customersyncurlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
