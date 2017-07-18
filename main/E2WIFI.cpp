/*
 * E2WIFI.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: IT
 */

#include "E2WIFI.h"

#include <esp_log.h>
#include <string>
#include <WiFi.h>
#include <WiFiEventHandler.h>

#include "sdkconfig.h"


#include <Task.h>

static char TAG[] = "E2WIFI";

E2WIFI::E2WIFI() {
	// TODO Auto-generated constructor stub

}

E2WIFI::~E2WIFI() {
	// TODO Auto-generated destructor stub
}

class MyWiFiEventHandler: public WiFiEventHandler {

	esp_err_t staGotIp(system_event_sta_got_ip_t event_sta_got_ip) {
		ESP_LOGI(TAG, "MyWiFiEventHandler(Class): staGotIp");

		return ESP_OK;
	}
};

void E2WIFI::init (void) {
	WiFi wifi;
	MyWiFiEventHandler *eventHandler = new MyWiFiEventHandler();

	wifi.setWifiEventHandler(eventHandler);
	wifi.setIPInfo("192.168.0.135", "192.168.0.1", "255.255.255.0");
	wifi.connectAP("EBOLA", "qwertyui");
}
