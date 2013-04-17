#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table searchquery.
 */
class searchqueryTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchqueryTableDefinitionCreateParam();
    virtual ~searchqueryTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
