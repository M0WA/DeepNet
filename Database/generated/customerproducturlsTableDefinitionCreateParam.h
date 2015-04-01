#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customerproducturls.
 */
class customerproducturlsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerproducturlsTableDefinitionCreateParam();
    virtual ~customerproducturlsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
