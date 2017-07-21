#include "freertos/FreeRTOS.h"
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include <driver/spi_master.h>
#include <esp_log.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "sdkconfig.h"


extern "C" {
	void app_main(void);
}

void Bluetooth(void);
void WiFi(void);


static char tag[] = "simple_tests_SSD1306";

Adafruit_SSD1306 display = Adafruit_SSD1306(
	13, // MOSI
	14, // SCLK
	27, // DC
	26, // RST
	15  // CS
);


static void print(char *text) {
	while(*text != 0) {
		display.write(*text);
		text++;
	}
} // print


void task_simple_tests_ssd1306(void *ignore) {
	ESP_LOGI(tag, ">> task_simple_tests_ssd1306");
    display.begin();

	display.setTextWrap(0);
	display.setTextColor(WHITE);
	display.clearDisplay();
	print((char *)"Hello from ESP32!");
	display.setCursor(2, 10);
	print((char *)"It works!");
	display.drawRect(0, 8, 9*6 + 2, 11, WHITE);

	display.fillCircle(128-24, 23, 8, WHITE);
	display.drawLine(72, 23, 92, 23, WHITE);
	display.drawLine(82, 17, 82, 29, WHITE);

	display.display();
    ESP_LOGI(tag, "<< task_simple_tests_ssd1306");
    vTaskDelete(NULL);
} // task_simple_tests_ssd1306


void app_main(void) {
	xTaskCreatePinnedToCore(&task_simple_tests_ssd1306, "task_simple_tests_ssd1306", 8048, NULL, 5, NULL, 0);

	Bluetooth();
	WiFi();
}
