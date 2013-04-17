#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table hyperlinks.
 */
class hyperlinksTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    hyperlinksTableDefinitionCreateParam();
    virtual ~hyperlinksTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
