#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table urlstages.
 */
class urlstagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlstagesTableDefinitionCreateParam();
    virtual ~urlstagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
