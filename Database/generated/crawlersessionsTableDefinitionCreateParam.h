#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table crawlersessions.
 */
class crawlersessionsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    crawlersessionsTableDefinitionCreateParam();
    virtual ~crawlersessionsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
