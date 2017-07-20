#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

extern "C" {
	void app_main(void);
}

void Bluetooth(void);
void WiFi(void);

void app_main(void) {
	Bluetooth();
	WiFi();
}
