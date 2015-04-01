#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customerproductimages.
 */
class customerproductimagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerproductimagesTableDefinitionCreateParam();
    virtual ~customerproductimagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
