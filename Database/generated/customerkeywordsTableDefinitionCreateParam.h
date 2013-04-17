#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customerkeywords.
 */
class customerkeywordsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerkeywordsTableDefinitionCreateParam();
    virtual ~customerkeywordsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
