#include "E2WIFI.h"

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

extern "C" {
	void app_main(void);
}

void SampleNotify(void);

void app_main(void) {
	SampleNotify();

	E2WIFI e2WiFi;

	e2WiFi.init();
}
