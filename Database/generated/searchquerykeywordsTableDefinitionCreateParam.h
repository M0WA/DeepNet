#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table searchquerykeywords.
 */
class searchquerykeywordsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchquerykeywordsTableDefinitionCreateParam();
    virtual ~searchquerykeywordsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
