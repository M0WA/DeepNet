#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table hyperlinks.
 */
class hyperlinksTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    hyperlinksTableDefinitionCreateParam();
    virtual ~hyperlinksTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
