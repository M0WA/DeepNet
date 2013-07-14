#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table __TMPL_TABLE_NAME__.
 */
class __TMPL_TABLE_NAME__TableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    __TMPL_TABLE_NAME__TableDefinitionCreateParam();
    virtual ~__TMPL_TABLE_NAME__TableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
