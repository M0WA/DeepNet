/*
 * CommerceSearchProduct.cpp
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchProduct.h"

#include <DatabaseLayer.h>

namespace parser {

CommerceSearchProduct::CommerceSearchProduct(){
}

CommerceSearchProduct::~CommerceSearchProduct() {
}

void CommerceSearchProduct::Store(database::DatabaseConnection* db) {

	database::customerproductsTableBase tblProduct;

	if(!productID.empty()) {
		tblProduct.Set_productNo(productID);}
	else
		//TODO: throw exception here
		//THROW_EXCEPTION();
		return;

	if(!productName.empty()) {
		tblProduct.Set_productName(productName);}

	if(!productBrand.empty()) {
		tblProduct.Set_productBrand(productBrand);}

	tblProduct.InsertOrUpdate(db);
	long long customerProductID = -1;
	db->LastInsertID(customerProductID);

}

}
