#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingalerts.
 */
class dataminingalertsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingalertsTableDefinitionCreateParam();
    virtual ~dataminingalertsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
