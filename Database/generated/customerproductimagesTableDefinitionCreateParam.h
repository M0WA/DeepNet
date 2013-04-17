#pragma once

#include "TableDefinitionCreateParam.h"

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
};

}
