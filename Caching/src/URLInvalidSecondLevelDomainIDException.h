/*
 * URLInvalidSecondLevelDomainIDException.h
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

class URLInvalidSecondLevelDomainIDException: public errors::Exception {
public:
	URLInvalidSecondLevelDomainIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& sndLvlID,
		const long long& urlID);
	virtual ~URLInvalidSecondLevelDomainIDException();
};

