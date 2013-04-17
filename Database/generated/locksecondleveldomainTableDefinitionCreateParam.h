#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table locksecondleveldomain.
 */
class locksecondleveldomainTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    locksecondleveldomainTableDefinitionCreateParam();
    virtual ~locksecondleveldomainTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
