/*
 * CommerceSearchProduct.h
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace database {
	class DatabaseConnection;
}

namespace parser {

class CommerceSearchProduct {
public:
	CommerceSearchProduct();
	virtual ~CommerceSearchProduct();

public:
	void Store(database::DatabaseConnection* db);

public:
	std::string productID;
	std::string productName;
	std::string productBrand;
	std::string productImage;
	std::string productDescription;

	std::string productURL;
};

}

