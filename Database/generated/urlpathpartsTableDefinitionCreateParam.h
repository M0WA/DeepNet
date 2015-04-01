#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table urlpathparts.
 */
class urlpathpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlpathpartsTableDefinitionCreateParam();
    virtual ~urlpathpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
