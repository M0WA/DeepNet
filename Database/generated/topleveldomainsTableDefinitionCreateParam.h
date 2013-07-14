#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table topleveldomains.
 */
class topleveldomainsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    topleveldomainsTableDefinitionCreateParam();
    virtual ~topleveldomainsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
