#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customerdomainblacklist.
 */
class customerdomainblacklistTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerdomainblacklistTableDefinitionCreateParam();
    virtual ~customerdomainblacklistTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
