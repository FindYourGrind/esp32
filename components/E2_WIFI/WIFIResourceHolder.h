/*
 * WIFIResourceHolder.h
 *
 *  Created on: Jul 20, 2017
 *      Author: itrambovetskyi
 */

#ifndef COMPONENTS_E2_WIFI_WIFIRESOURCEHOLDER_H_
#define COMPONENTS_E2_WIFI_WIFIRESOURCEHOLDER_H_

#include <WiFi.h>
#include <WiFiEventHandler.h>

namespace e2 {

	class WIFIResourceHolder {

	public:
		static WIFIResourceHolder& Instance() {
			static WIFIResourceHolder myInstance;
			return myInstance;
		}

		WIFIResourceHolder(WIFIResourceHolder const&) = delete;             // Copy construct
		WIFIResourceHolder(WIFIResourceHolder&&) = delete;                  // Move construct
		WIFIResourceHolder& operator=(WIFIResourceHolder const&) = delete;  // Copy assign
		WIFIResourceHolder& operator=(WIFIResourceHolder &&) = delete;      // Move assign

		WiFi* wifi;

		void connectToAp(void);

	protected:
		WIFIResourceHolder();
		virtual ~WIFIResourceHolder();

	};

} /* namespace e2 */

#endif /* COMPONENTS_E2_WIFI_WIFIRESOURCEHOLDER_H_ */
