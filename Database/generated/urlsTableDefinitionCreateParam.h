#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table urls.
 */
class urlsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlsTableDefinitionCreateParam();
    virtual ~urlsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
