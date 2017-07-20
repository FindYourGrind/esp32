#include "WIFIResourceHolder.h"
#include <esp_log.h>
#include <string>
#include <sys/time.h>
#include <sstream>
#include "Task.h"

#include "sdkconfig.h"

#include <bitset>

using E2WIFI = e2::WIFIResourceHolder;

class E2WiFiEventHandler: public WiFiEventHandler {

	esp_err_t staGotIp(system_event_sta_got_ip_t event_sta_got_ip) {
		return ESP_OK;
	}
};

static void start() {
	E2WIFI::Instance().wifi->setWifiEventHandler(new E2WiFiEventHandler());
	E2WIFI::Instance().connectToAp();
}

void WiFi(void)
{
	start();
}
