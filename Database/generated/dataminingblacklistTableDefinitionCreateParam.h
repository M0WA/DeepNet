#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingblacklist.
 */
class dataminingblacklistTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingblacklistTableDefinitionCreateParam();
    virtual ~dataminingblacklistTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
