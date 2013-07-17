#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table unittest3.
 */
class unittest3TableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    unittest3TableDefinitionCreateParam();
    virtual ~unittest3TableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
