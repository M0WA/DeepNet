/**
 * @file XmlTools.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include "Pointer.h"
#include "XmlDocument.h"

namespace tools {

class XmlTools {
public:
	XmlTools();
	virtual ~XmlTools();

	static bool CreateDocument(const char* docTxt,size_t len,Pointer<XmlDocument>& pDoc);
};

}
