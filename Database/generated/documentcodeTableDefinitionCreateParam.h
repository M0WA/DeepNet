#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table documentcode.
 */
class documentcodeTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    documentcodeTableDefinitionCreateParam();
    virtual ~documentcodeTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
