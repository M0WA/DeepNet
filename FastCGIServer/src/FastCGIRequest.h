/**
 * @file FastCGIRequest.h
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#pragma once

#include <fcgio.h>
#include <fcgi_config.h>  // HAVE_IOSTREAM_WITHASSIGN_STREAMBUF

#include <libxml/xmlschemas.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/SAX2.h>

#include <list>
#include <vector>
#include <map>
#include <string>
#include <sstream>

#include <StringTools.h>
#include <HttpCookie.h>

namespace fastcgiserver {
class FastCGIServerThread;

/**
 * @brief container for a fastcgi client request.
 */
class FastCGIRequest {
public:
	/**
	 * constructs client request.
	 * @param serverThread originating server thread.
	 */
	FastCGIRequest(FastCGIServerThread* serverThread);
	virtual ~FastCGIRequest();

public:
	/**
	 * handles a request.
	 * @param request raw fastcgi request.
	 */
	void Handle(FCGX_Request& request);

	/**
	 * checks if request completed.
	 * @return false if not completed, true if completed.
	 */
	bool IsComplete() const { return completed; }

public:
	/**
	 * gets converted value from fastcgi request parameters.
	 * @param request raw fastcgi request.
	 * @param key keyname of parameter.
	 * @param value gets filled with value of key.
	 * @return false if key does not exists, true if it does.
	 */
	template <class T>
	bool GetParam(FCGX_Request& request, const std::string& key, T& value)
	{
		std::string valueString;
		if(!GetParam(request, key, valueString))
			return false;

		std::stringstream in;
		in << std::skipws;
		in << valueString;
		in >> value;

		return true;
	}

	/**
	 * gets parameter from fastcgi request.
	 * @param request raw fastcgi request.
	 * @param key keyname of parameter.
	 * @param value gets filled with value of key
	 * @return false if key does not exists, true if it does.
	 */
	bool GetParam(FCGX_Request& request, const std::string& key, std::string& value)
	{
		char* pszValue = FCGX_GetParam(tools::StringTools::ToLowerNP(key).c_str(), request.envp);
		if(!pszValue)
			return false;

		value = std::string(pszValue);
		return true;
	}

public:
	/**
	 * gets connected endpoint as string.
	 * @return connected endpoint as string.
	 */
	std::string GetClientAddress() const { return clientIP+":"+clientPort; }

	/**
	 * gets originating server thread.
	 * @return originating server thread.
	 */
	FastCGIServerThread* ServerThread() { return serverThread; }

	/**
	 * gets client's user agent.
	 * @return client's user agent.
	 */
	const std::string& UserAgent() const { return userAgent; }

	/**
	 * gets requested uri.
	 * @return requested uri.
	 */
	const std::string& RequestURI() const { return requestUri; }

	/**
	 * gets cookies from current request.
	 * @return cookies.
	 */
	const std::vector<network::HttpCookie>& Cookies() const { return cookies; }

protected:
	/**
	 * registers namespaces from nsList in xpathCtx.
	 * @param xpathCtx xpathCtx the pointer to an XPath context.
	 * @param nsList nsList the list of known namespaces in "<prefix1>=<href1> <prefix2>=href2> ..." format.
	 * @return 0 on success and a negative value otherwise.
	 */
	int register_namespaces(xmlXPathContextPtr xpathCtx, const xmlChar* nsList);

	/**
	 * gets xpath from request contents (if contents are XML).
	 * @param queryparts gets filled with xpath results.
	 * @param filename xml content string for xpath.
	 * @param xpathExpr xpath expression.
	 * @param nsList list of allowed namespaces(???).
	 * @return false on error, true on success.
	 */
	bool Xpath(std::list<std::string>& queryparts, const char* filename, const xmlChar* xpathExpr, const xmlChar* nsList = 0);

	/**
	 * validates xml document against xsd.
	 * @param xsdString string containing xsd.
	 * @param doc xml document to validate.
	 * @return false on error, true on success.
	 */
	bool Validate(const std::string& xsdString, xmlDocPtr doc);

private:
	virtual void OnHandle(FCGX_Request& request)=0;
	void LogRequest();
	void DumpParameters(std::stringstream& ssIn, const std::vector<std::pair<std::string,std::string> >& params);
	bool ReadPostData(FCGX_Request& request);
	void ParseCookies(std::string cookieString);

	static void SplitArguments(char*, std::vector< std::pair<std::string,std::string> >&);
	static std::string SafeGetEnv(const char* name,FCGX_Request& request);

protected:
	/**
	 * buffer to raw post data.
	 */
	char* rawPostData;

	/**
	 * buffer to raw get data.
	 */
	char* rawQueryString;

	/**
	 * parsed post parameters.
	 */
	std::vector<std::pair<std::string,std::string> > postParameters;

	/**
	 * parsed get parameters.
	 */
	std::vector<std::pair<std::string,std::string> > getParameters;

private:
	bool completed;
	const unsigned long STDIN_MAX;
	FastCGIServerThread* serverThread;
	std::vector<network::HttpCookie> cookies;

	std::string clientIP;
	std::string clientPort;
	std::string requestUri;
	std::string userAgent;
};

}
