/**
 *
 * @file UnitTestHttpClientCURL.h
 * @author Moritz Wagner
 * @date May 31, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTest.h"

#include <HttpUrl.h>

namespace toolbot {

class UnitTestHttpClientCURL : public UnitTest{

public:
	UnitTestHttpClientCURL(const std::string& get,const std::string& post);
	virtual ~UnitTestHttpClientCURL();

	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestHttpClientCURL"; }

private:
	bool ReadURLFile(const std::string& urlFileName, std::vector<network::HttpUrl>& testUrls);

private:
	std::string get;
	std::string post;
};

}
