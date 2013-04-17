#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table cacherobots.
 */
class cacherobotsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacherobotsTableDefinitionCreateParam();
    virtual ~cacherobotsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
