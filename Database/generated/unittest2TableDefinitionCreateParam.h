#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table unittest2.
 */
class unittest2TableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    unittest2TableDefinitionCreateParam();
    virtual ~unittest2TableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
