/*
 * DataminingNotifier.cpp
 *
 *  Created on: 29.07.2012
 *      Author: Moritz Wagner
 */

#include "DataminingNotifier.h"

#include <Logging.h>

namespace indexing {

DataminingNotifier::DataminingNotifier() {
}

DataminingNotifier::~DataminingNotifier() {
}

void DataminingNotifier::OnNotify() {

	vecAlert.clear();
}

}
