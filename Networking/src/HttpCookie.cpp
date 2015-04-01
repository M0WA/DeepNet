/**
 * @file HttpCookie.h
 * @author Moritz Wagner
 * @date 29.06.2012
 */

#include "HttpCookie.h"

#include <Regex.h>
#include <Logging.h>

namespace network {

HttpCookie::HttpCookie() {
}

HttpCookie::~HttpCookie() {
}

bool HttpCookie::FromString(const std::string& rawCookieString)
{
	std::vector<std::string> groups;
	tools::Regex::Match("([^[:space:]]+)[:space:]*=[:space:]*([^[:space:]]+)",rawCookieString,groups);
	if(groups.size()!=2){
		log::Logging::LogWarn("could not parse cookie entry: %s",rawCookieString.c_str());
		return false;}

	keyValuePair.first = groups.at(0);
	keyValuePair.second = groups.at(1);
	return true;
}

bool HttpCookieHelper::GetCookieByKey(const std::string& key, const std::vector<HttpCookie>& cookies, HttpCookie& cookie)
{
	std::vector<HttpCookie>::const_iterator iterCookies = cookies.begin();
	for(;iterCookies != cookies.end(); ++iterCookies){

		if(iterCookies->GetKey().compare(key) == 0) {
			cookie = *iterCookies;
			return true; }
	}
	return false;
}

}
