#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customerdomains.
 */
class customerdomainsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerdomainsTableDefinitionCreateParam();
    virtual ~customerdomainsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
