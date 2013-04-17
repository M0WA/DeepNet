#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table cacheurl.
 */
class cacheurlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacheurlTableDefinitionCreateParam();
    virtual ~cacheurlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
