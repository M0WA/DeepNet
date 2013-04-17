#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table docurl.
 */
class docurlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    docurlTableDefinitionCreateParam();
    virtual ~docurlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
