#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingcustomersession.
 */
class dataminingcustomersessionTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingcustomersessionTableDefinitionCreateParam();
    virtual ~dataminingcustomersessionTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
