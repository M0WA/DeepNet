#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customerproducts.
 */
class customerproductsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerproductsTableDefinitionCreateParam();
    virtual ~customerproductsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
