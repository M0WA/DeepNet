#pragma once

#include "TableDefinitionCreateParam.h"

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
};

}
