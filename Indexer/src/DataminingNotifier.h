/*
 * DataminingNotifier.h
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>

namespace indexing {

class DataminingCriteria;
class DataminingNotifier {
public:
	enum DataminingNotifierType {
		NOTIFY_TYPE_UNKNOWN = 0,
		NOTIFY_TYPE_EMAIL   = 1,
	};

public:
	DataminingNotifier();
	virtual ~DataminingNotifier();

public:
	void AddAlert(DataminingCriteria* alert) { vecAlert.push_back(alert); }

public:
	virtual void OnNotify();

protected:
	inline const std::vector<DataminingCriteria*>& GetAlerts() const { return vecAlert; }

private:
	std::vector<DataminingCriteria*> vecAlert;
};

}
