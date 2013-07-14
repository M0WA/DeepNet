#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingcriteriaalerts.
 */
class dataminingcriteriaalertsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingcriteriaalertsTableDefinitionCreateParam();
    virtual ~dataminingcriteriaalertsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
