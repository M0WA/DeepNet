#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table images.
 */
class imagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    imagesTableDefinitionCreateParam();
    virtual ~imagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
