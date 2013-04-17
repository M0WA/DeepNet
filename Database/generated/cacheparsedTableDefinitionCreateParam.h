#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table cacheparsed.
 */
class cacheparsedTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacheparsedTableDefinitionCreateParam();
    virtual ~cacheparsedTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
