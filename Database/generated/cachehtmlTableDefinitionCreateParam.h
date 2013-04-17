#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table cachehtml.
 */
class cachehtmlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cachehtmlTableDefinitionCreateParam();
    virtual ~cachehtmlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
