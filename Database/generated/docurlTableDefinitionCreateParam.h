#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table docurl.
 */
class docurlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    docurlTableDefinitionCreateParam();
    virtual ~docurlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
