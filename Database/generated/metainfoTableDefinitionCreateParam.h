#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table metainfo.
 */
class metainfoTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    metainfoTableDefinitionCreateParam();
    virtual ~metainfoTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
