#pragma once

#include "TableDefinitionCreateParam.h"

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
};

}
