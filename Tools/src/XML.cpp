/*
 * @file XML.cpp
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#include "XML.h"

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <Logging.h>

namespace tools {

XML::XML(const std::string& xmlDoc) {

    doc = xmlParseMemory(xmlDoc.c_str(),xmlDoc.length());
    if (doc == NULL) {
    	log::Logging::LogWarn("unable to parse incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",xmlDoc.c_str()); }
}

XML::~XML() {
	if(doc) {
		xmlFreeDoc(doc);
		doc = NULL;
	}
}

bool XML::XPath(const std::string& xpath,std::vector<std::string>& entries) {

    xmlXPathContextPtr xpathCtx(xmlXPathNewContext(doc));
    if(xpathCtx == NULL) {
    	log::Logging::LogWarn("unable to create new xpath context for incoming query xml request");
        xmlFreeDoc(doc);
        return false; }

    xmlXPathObjectPtr xpathObj(xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xpath.c_str()), xpathCtx));
    if(xpathObj == NULL) {
    	log::Logging::LogWarn("unable to evaluate xpath expression for incoming query xml request: %s",xpath.c_str());
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false; }

    xmlNodeSetPtr nodes(xpathObj->nodesetval);
    int size( (nodes) ? nodes->nodeNr : 0 );

    for(int i(0); i < size; ++i) {
    	if(nodes->nodeTab[i]->type == XML_TEXT_NODE) {
			if(nodes->nodeTab[i]->content) {
				entries.push_back(std::string(reinterpret_cast<const char*>(nodes->nodeTab[i]->content)));
			}
    	}
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    return true;
}

}
