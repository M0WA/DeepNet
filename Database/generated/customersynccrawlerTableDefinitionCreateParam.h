#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customersynccrawler.
 */
class customersynccrawlerTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customersynccrawlerTableDefinitionCreateParam();
    virtual ~customersynccrawlerTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
