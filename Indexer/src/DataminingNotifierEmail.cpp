/*
 * DataminingNotifierEmail.cpp
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingNotifierEmail.h"
#include <StringTools.h>

namespace indexing {

DataminingNotifierEmail::DataminingNotifierEmail(const std::string& emailAddressIn, const std::string& emailSubjectIn)
: DataminingNotifier()
, emailAddress(emailAddressIn)
, emailSubject(emailSubjectIn)
{
	//TODO: validate input better before executing command
	tools::StringTools::ReplaceString("\"","",emailAddress);
	tools::StringTools::ReplaceString("!","",emailAddress);
	tools::StringTools::ReplaceString(";","",emailAddress);

	tools::StringTools::ReplaceString("!","\\!",emailSubject);
	tools::StringTools::ReplaceString("\"","",emailSubject);
	tools::StringTools::ReplaceString(";","",emailSubject);

	emailSubject = "\"" + emailSubject + "\"";
}

DataminingNotifierEmail::~DataminingNotifierEmail()
{
}

void DataminingNotifierEmail::OnNotify()
{
	const std::vector<DataminingCriteria*>& alerts = GetAlerts();
	if(alerts.size()==0)
		return;

	std::stringstream ssEmailContent;
	std::vector<DataminingCriteria*>::const_iterator iterAlerts = alerts.begin();
	for(;iterAlerts != alerts.end(); ++iterAlerts) {
		//TODO: generate email content
	}

	//send email a more elegant way than using system() or similar
	std::string output;
	std::string cmd = "mail -s \"" + emailSubject + "\" \""+emailAddress+"\" < echo \"" + ssEmailContent.str() + "\"";
	tools::StringTools::ExecuteCommand(cmd,output);

	DataminingNotifier::OnNotify();
}

}
