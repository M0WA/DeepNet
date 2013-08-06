#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cacheurlpathparts.
 */
class cacheurlpathpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacheurlpathpartsTableDefinitionCreateParam();
    virtual ~cacheurlpathpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
