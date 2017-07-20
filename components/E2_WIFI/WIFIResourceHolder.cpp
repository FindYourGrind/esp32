/*
 * WIFIResourceHolder.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: itrambovetskyi
 */

#include "WIFIResourceHolder.h"
#include "E2GlobalResourceHolder.h"

namespace e2 {

using E2GLOBAL = E2GlobalResourceHolder;


WIFIResourceHolder::WIFIResourceHolder() {
	wifi = new WiFi();
}

WIFIResourceHolder::~WIFIResourceHolder() {
	delete wifi;
}

void WIFIResourceHolder::connectToAp(void) {
	wifi->connectAP(E2GLOBAL::SSID, E2GLOBAL::PASS);
}

} /* namespace e2 */
