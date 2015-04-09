/**
 * @file XmlTools.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "XmlTools.h"

#include <libxml/parser.h>

#include <Logging.h>

namespace tools {

XmlTools::XmlTools() {
}

XmlTools::~XmlTools() {
}

bool XmlTools::CreateDocument(const char* docTxt,size_t len,Pointer<XmlDocument>& pDoc) {

    xmlDocPtr doc(xmlParseMemory(docTxt,len));
    if (doc == NULL) {
    	log::Logging::LogWarn("unable to parse incoming query xml request");
    	log::Logging::LogTraceUnlimited("%s",docTxt);
		return false; }

    pDoc.Set(new XmlDocument(doc),true);
	return true;
}

}
