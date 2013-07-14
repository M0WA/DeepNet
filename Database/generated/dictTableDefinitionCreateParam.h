#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dict.
 */
class dictTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dictTableDefinitionCreateParam();
    virtual ~dictTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
