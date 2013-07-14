#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingblacklist.
 */
class dataminingblacklistTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingblacklistTableDefinitionCreateParam();
    virtual ~dataminingblacklistTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
