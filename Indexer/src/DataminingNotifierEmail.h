/*
 * DataminingNotifierEmail.h
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include "DataminingNotifier.h"

namespace indexing {

class DataminingNotifierEmail: public indexing::DataminingNotifier {
public:
	DataminingNotifierEmail(const std::string& emailAddress, const std::string& emailSubject);
	virtual ~DataminingNotifierEmail();

private:
	virtual void OnNotify();

private:
	std::string emailAddress;
	std::string emailSubject;
};

}
