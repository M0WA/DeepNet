#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table unittest1.
 */
class unittest1TableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    unittest1TableDefinitionCreateParam();
    virtual ~unittest1TableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
