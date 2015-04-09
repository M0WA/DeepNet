/**
 * @file XmlDocument.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "XmlDocument.h"

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <Logging.h>

namespace tools {

XmlDocument::XmlDocument(xmlDocPtr doc)
: doc(doc){
}

XmlDocument::~XmlDocument() {
	if(doc) {
		xmlFreeDoc(doc); }
}

size_t XmlDocument::XPathSingle(const char* xPath, std::string& value, size_t idx) {
    xmlXPathContextPtr xpathCtx(xmlXPathNewContext(doc));
    if(xpathCtx == NULL) {
    	log::Logging::LogWarn("unable to create new xpath context for incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",xPath);
        xmlFreeDoc(doc);
        return false; }

    xmlXPathObjectPtr xpathObj(xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xPath), xpathCtx));
    if(xpathObj == NULL) {
    	log::Logging::LogWarn("unable to evaluate xpath expression for incoming query xml request: %s",xPath);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false; }

    xmlNodeSetPtr nodes(xpathObj->nodesetval);
    int size( (nodes) ? nodes->nodeNr : 0 );
    if(!size || size <= ((ssize_t)idx) ) {
    	return 0; }

	if(nodes->nodeTab[idx]->type == XML_TEXT_NODE) {
		if(nodes->nodeTab[idx]->content) {
			std::string content = reinterpret_cast<const char*>(nodes->nodeTab[idx]->content);
			value = content;
			return size; }
	}
	return 0;
}

size_t XmlDocument::XPath(const char* xPath, std::vector<std::string>& values) {

    xmlXPathContextPtr xpathCtx(xmlXPathNewContext(doc));
    if(xpathCtx == NULL) {
    	log::Logging::LogWarn("unable to create new xpath context for incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",xPath);
        xmlFreeDoc(doc);
        return false; }

    xmlXPathObjectPtr xpathObj(xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xPath), xpathCtx));
    if(xpathObj == NULL) {
    	log::Logging::LogWarn("unable to evaluate xpath expression for incoming query xml request: %s",xPath);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return false; }

    xmlNodeSetPtr nodes(xpathObj->nodesetval);
    int size( (nodes) ? nodes->nodeNr : 0 );

    for(int i(0); i < size; ++i) {
    	if(nodes->nodeTab[i]->type == XML_TEXT_NODE) {
			if(nodes->nodeTab[i]->content) {
				std::string content = reinterpret_cast<const char*>(nodes->nodeTab[i]->content);
				values.push_back(content);
			}
    	}
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
	return values.size();
}

}
