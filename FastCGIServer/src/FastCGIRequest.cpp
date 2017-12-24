/**
 * @file FastCGIRequest.cpp
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#include "FastCGIRequest.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

#include <Logging.h>
#include <StringTools.h>

#include "FastCGIServerThread.h"

namespace fastcgiserver {

static const unsigned long FCGI_MAX_POST_DATA_SIZE(4096);

FastCGIRequest::FastCGIRequest(FastCGIServerThread* serverThread)
: serverThread(serverThread)
, completed(false) {
}

FastCGIRequest::~FastCGIRequest() {
}

void FastCGIRequest::Handle(FCGX_Request& request) {

    //save client infos
    clientIP = FastCGIRequest::SafeGetEnv("REMOTE_ADDR",request);
    clientPort = FastCGIRequest::SafeGetEnv("REMOTE_PORT",request);
    requestUri = FastCGIRequest::SafeGetEnv("REQUEST_URI",request);

	rawQueryString = FCGX_GetParam("QUERY_STRING", request.envp);
	SplitArguments(rawQueryString, getParameters);
	GetParam(request, "user-agent", userAgent);

	ReadPostData(request);

	LogRequest();

	completed = true;

	OnHandle(request);

	getParameters.clear();
	rawPostData.Release();
}

void FastCGIRequest::LogRequest() {

	if(log::Logging::GetLogLevel() >= log::Logging::LOGLEVEL_INFO) {

		std::stringstream ssIn;
		ssIn << "handling request from client: " << GetClientAddress() << std::endl
			 << "\trequest-uri: " << requestUri << std::endl
			 << "\tuser-agent: " << userAgent << std::endl;

		ssIn << "\tGET parameters: " << std::endl;
		DumpParameters(ssIn,getParameters);

		ssIn << "\tPOST data: " << std::endl
			 << "\t" << rawPostData << std::endl;

		ssIn << "\tCOOKIES: " << std::endl;
		std::vector<network::HttpCookie>::const_iterator iterCookies = cookies.begin();
		for(;iterCookies != cookies.end();++iterCookies) {
			ssIn << "\t" << iterCookies->ToString() << std::endl; }

		log::Logging::LogInfo(ssIn.str());
	}
}

void FastCGIRequest::DumpParameters(std::stringstream& ssIn, const std::vector<std::pair<std::string,std::string> >& params) {

	std::vector<std::pair<std::string,std::string> >::const_iterator iterParam = params.begin();
	for(;iterParam != params.end();++iterParam) {
		ssIn << "\t" << iterParam->first << "=" << iterParam->second << std::endl; }
}

bool FastCGIRequest::ReadPostData(FCGX_Request& request) {

    // Note that the default bufsize (0) will cause the use of iostream
    // methods that require positioning (such as peek(), seek(),
    // unget() and putback()) to fail (in favour of more efficient IO).

    fcgi_streambuf cin_fcgi_I(request.in);
    fcgi_streambuf cout_fcgi_I(request.out);
    fcgi_streambuf cerr_fcgi_I(request.err);

#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
        std::istream cin_fcgi = &cin_fcgi_I;
        std::ostream cout_fcgi = &cout_fcgi_I;
        std::ostream cerr_fcgi = &cerr_fcgi_I;
#else
        std::istream cin_fcgi(&cin_fcgi_I);
        std::ostream cout_fcgi(&cout_fcgi_I);
        std::ostream cerr_fcgi(&cerr_fcgi_I);
/*
        cin_fcgi.rdbuf(&cin_fcgi_I);
        cout_fcgi.rdbuf(&cout_fcgi_I);
        cerr_fcgi.rdbuf(&cerr_fcgi_I);
 */
#endif

    //parse cookies
    ParseCookies(FastCGIRequest::SafeGetEnv("HTTP_COOKIE",request));

    std::string requestMethod(FastCGIRequest::SafeGetEnv("REQUEST_METHOD",request));
    tools::StringTools::ToLowerIP(requestMethod);

	unsigned long clen(FCGI_MAX_POST_DATA_SIZE);
    if(requestMethod.compare("post") == 0)
    {
		// Although FastCGI supports writing before reading,
		// many http clients (browsers) don't support it (so
		// the connection deadlocks until a timeout expires!).
		std::string clenstr = FastCGIRequest::SafeGetEnv("CONTENT_LENGTH", request);

		log::Logging::LogTrace("POST content-length: %s",clenstr.c_str());

		if (!clenstr.empty())
		{
			clen = strtoul(clenstr.c_str(), NULL, 10);
			if (clen<=0) {
				log::Logging::LogWarn("empty post request received, dropping");
				return false;
			}
			if(clen>FCGI_MAX_POST_DATA_SIZE) {
				log::Logging::LogWarn("request is too big, dropping");
				return false;
			}

			rawPostData.EnsureSize(clen,false);
			cin_fcgi.read(rawPostData.GetElements(), clen);
			clen = cin_fcgi.gcount();
			rawPostData.Resize(clen);

			log::Logging::LogTrace("POST data: read %lu bytes",clen);
		}
		else {
			log::Logging::LogWarn("post request did not specify content length, dropping");
			return false;
		}
    }
    else if (requestMethod.compare("get") == 0) {

	}
    else {
    	//unsupported HTTP request method
    	log::Logging::LogWarn("unsupported http method received: " + requestMethod + ", dropping");
    	return false;
    }

    bool isString(true);
    if(isString) {
		for (size_t i(0); i < rawPostData.GetCount(); ++i) {
			if(std::isprint(*rawPostData.GetConstElementAt(i))==0 || std::iscntrl(*rawPostData.GetConstElementAt(i))==1) {
				log::Logging::LogTrace("POST data: found non printable char at position %zu",i);
				isString = false;
				break; }
		}
    }

    if(!isString) {
    	rawPostData.Release();
    	log::Logging::LogWarn("post data is not a string, ignoring it");
    }

	char zero(0);
	rawPostData.Append(&zero,1);

	// Chew up any remaining stdin - this shouldn't be necessary
	// but is because mod_fastcgi doesn't handle it correctly.
	// ignore() doesn't set the eof bit in some versions of glibc++
	// so use gcount() instead of eof()...

    //TODO: check if beyond is neccessary (whatever it does, see above ;) )
	//do cin_fcgi.ignore(1024); while (cin_fcgi.gcount() == 1024);

	return true;
}

void FastCGIRequest::SplitArguments(const char* pszArguments, std::vector< std::pair<std::string,std::string> >& arguments)
{
	if(pszArguments == 0){
		return;	}

	if(pszArguments[0] != '?') {
		return;	}

	char* beginParam(const_cast<char*>(pszArguments));
	char* endParam(const_cast<char*>(pszArguments));
	if ((endParam = strstr(beginParam,"&")) != NULL)
	{
		while ((endParam = strstr(beginParam,"&")) != NULL)
		{
			char tmp(*endParam);
			endParam = 0;

			++beginParam;

			char* keyEnd(0);
			std::pair<std::string, std::string> paramPair;
			if( (keyEnd = strstr(beginParam,"=")) != NULL) {

				//is key-value parameter
				char keyEndTmp(*keyEnd);
				keyEnd = 0;

				paramPair.first  = tools::StringTools::ToLowerNP(std::string( beginParam ));
				paramPair.second = std::string( (keyEnd+1) );

				*keyEnd = keyEndTmp;
			}
			else {
				//is key only parameter
				paramPair.first = tools::StringTools::ToLowerNP(std::string( beginParam ));
			}

			arguments.push_back(paramPair);

			*endParam = tmp;
			beginParam = endParam+1;
		}
	}
}

std::string FastCGIRequest::SafeGetEnv(const char* name,FCGX_Request& request)
{
    const char* ptr(FCGX_GetParam(name, request.envp));
    if(ptr == NULL){
        return "";
    }else{
        return std::string(ptr);
    }
}

std::string FastCGIRequest::DumpEnv(FCGX_Request& request)
{
	std::ostringstream ss;
	if(request.envp) {
		for(size_t i = 0; request.envp[i] != NULL ; i++) {
			ss << request.envp[i] << std::endl;
		}
	}
	return ss.str();
}

void FastCGIRequest::ParseCookies(std::string cookieString)
{
	if(cookieString.empty())
		return;

	//make sure cookie ends with semicolon
	cookieString += ";";

	std::vector<std::string> vecRawCookie;
	tools::StringTools::SplitBy(cookieString,";",vecRawCookie);

	std::vector<std::string>::const_iterator iterCookie(vecRawCookie.begin());
	for(;iterCookie != vecRawCookie.end(); ++iterCookie) {
		network::HttpCookie cookie;
		if(!cookie.FromString(*iterCookie)){
			log::Logging::LogWarn("could not parse cookie parameter: " + *iterCookie);
			continue; }
		cookies.push_back(cookie);
	}
}

bool FastCGIRequest::Validate(const std::string& xsdString, xmlDocPtr doc)
{
	return true;

	//TODO: write a valid xsd ;)

	//validate against XSD
	xmlDocPtr schema_doc(xmlReadMemory(xsdString.c_str(), xsdString.size(),NULL, NULL, XML_PARSE_NONET));
    if (schema_doc == NULL) {
        // the schema cannot be loaded or is not well-formed
        return false;
    }
    xmlSchemaParserCtxtPtr parser_ctxt(xmlSchemaNewDocParserCtxt(schema_doc));
    if (parser_ctxt == NULL) {
        // unable to create a parser context for the schema
        xmlFreeDoc(schema_doc);
        return false;
    }
    xmlSchemaPtr schema(xmlSchemaParse(parser_ctxt));
    if (schema == NULL) {
        // the schema itself is not valid
        xmlSchemaFreeParserCtxt(parser_ctxt);
        xmlFreeDoc(schema_doc);
        return false;
    }
    xmlSchemaValidCtxtPtr valid_ctxt = xmlSchemaNewValidCtxt(schema);
    if (valid_ctxt == NULL) {
        // unable to create a validation context for the schema
        xmlSchemaFree(schema);
        xmlSchemaFreeParserCtxt(parser_ctxt);
        xmlFreeDoc(schema_doc);
        return false;
    }
    int is_valid(xmlSchemaValidateDoc(valid_ctxt, doc) == 0);
    xmlSchemaFreeValidCtxt(valid_ctxt);
    xmlSchemaFree(schema);
    xmlSchemaFreeParserCtxt(parser_ctxt);
    xmlFreeDoc(schema_doc);
    // force the return value to be non-negative on success
    return is_valid ? 1 : 0;
}

int FastCGIRequest::register_namespaces(xmlXPathContextPtr xpathCtx, const xmlChar* nsList) {
    xmlChar* nsListDup;
    xmlChar* prefix;
    xmlChar* href;
    xmlChar* next;

    nsListDup = xmlStrdup(nsList);
    if(nsListDup == NULL) {
		fprintf(stderr, "Error: unable to strdup namespaces list\n");
		return(-1);
    }

    next = nsListDup;
    while(next != NULL) {
	/* skip spaces */
	while((*next) == ' ') next++;
	if((*next) == '\0') break;

	/* find prefix */
	prefix = next;
	next = (xmlChar*)xmlStrchr(next, '=');
	if(next == NULL) {
	    fprintf(stderr,"Error: invalid namespaces list format\n");
	    xmlFree(nsListDup);
	    return(-1);
	}
	*(next++) = '\0';

	/* find href */
	href = next;
	next = (xmlChar*)xmlStrchr(next, ' ');
	if(next != NULL) {
	    *(next++) = '\0';
	}

	/* do register namespace */
	if(xmlXPathRegisterNs(xpathCtx, prefix, href) != 0) {
	    fprintf(stderr,"Error: unable to register NS with prefix=\"%s\" and href=\"%s\"\n", prefix, href);
	    xmlFree(nsListDup);
	    return(-1);
	}
    }

    xmlFree(nsListDup);
    return(0);
}

bool FastCGIRequest::Xpath(std::list<std::string>& queryparts, const char* xmlDocument, const xmlChar* xpathExpr, const xmlChar* nsList)
{
    xmlDocPtr doc(0);
    xmlXPathContextPtr xpathCtx(0);
    xmlXPathObjectPtr xpathObj(0);

    /* Load XML document */
    doc = xmlParseMemory(xmlDocument,strlen(xmlDocument));
    if (doc == NULL) {
    	log::Logging::LogTrace("unable to parse incoming xml:\n" + std::string(xmlDocument));
		return false;
    }

    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
    	log::Logging::LogTrace("unable to create new XPath context");
        xmlFreeDoc(doc);
        return false;
    }

    /* Register namespaces from list (if any) */
    if((nsList != NULL) && (register_namespaces(xpathCtx, nsList) < 0)) {
    	log::Logging::LogTrace("failed to register namespaces list");
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false;
    }

    /* Evaluate xpath expression */
    xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if(xpathObj == NULL) {
    	log::Logging::LogTrace("unable to evaluate xpath expression");
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false;
    }

    xmlNodeSetPtr nodes(xpathObj->nodesetval);
    int size( (nodes) ? nodes->nodeNr : 0 );

    for(int i = 0; i < size; ++i) {
    	if(nodes->nodeTab[i]->type == XML_TEXT_NODE) {
			if(nodes->nodeTab[i]->content) {
				queryparts.push_back((char*)nodes->nodeTab[i]->content);
			}
    	}
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);

    return true;
}

const std::string& FastCGIRequest::GetCookieValueByName(const std::string& name) const {

	std::vector<network::HttpCookie>::const_iterator i(cookies.begin());
	for(;i != cookies.end(); ++i) {
		if(i->GetKey().compare(name) == 0) {
			return i->GetValue(); }
	}

	throw std::out_of_range("no value for " + name);
}

}
