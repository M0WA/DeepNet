#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table metainfo.
 */
class metainfoTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    metainfoTableDefinitionCreateParam();
    virtual ~metainfoTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
