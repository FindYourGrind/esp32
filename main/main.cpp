#include "E2WIFI.h"


#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "Canvas.h"
#include "Component.h"
#include "Template.h"
#include "sdkconfig.h"

//#include "E2DISPLAY.h"

using namespace display;

#include "Adafruit_SSD1306.h"

extern "C" {
	void app_main(void);
}

void SampleNotify(void);

static char tag[] = "simple_tests_SSD1306";

Adafruit_SSD1306 ssd1306display = Adafruit_SSD1306(
	13, // MOSI
	14, // SCLK
	27, // DC
	26, // RST
	15  // CS
);

void app_main(void) {
	ESP_LOGD(tag, ">> task_simple_tests_ssd1306");
	ssd1306display.begin();

	ssd1306display.setTextWrap(0);
	ssd1306display.setTextColor(WHITE);
	ssd1306display.clearDisplay();
	ssd1306display.setCursor(2, 10);
	ssd1306display.drawRect(0, 8, 9*6 + 2, 11, WHITE);

	//display.fillCircle(128-24, 23, 8, WHITE);
	ssd1306display.drawLine(72, 23, 92, 23, WHITE);
	ssd1306display.drawLine(82, 17, 82, 29, WHITE);

	Canvas canvas(30, 30);
	Component component1(0,0,20,20, canvas);
	component1.setPixel(1,0);
	component1.setPixel(0,2);
	component1.setPixel(3,0);
	component1.setPixel(0,4);
	component1.setPixel(5,0);
	component1.setPixel(0,6);
	component1.setPixel(7,0);
	component1.show();

	uint8_t array[1024];

//	canvas.toByteArray(array);
//
//	ssd1306display.drawBitmap(0, 0, array, 128, 8, 0);
	ssd1306display.display();
  ESP_LOGD(tag, "<< task_simple_tests_ssd1306");
	SampleNotify();

	E2WIFI e2WiFi;

	e2WiFi.init();


//	E2DISPLAY e2display;
//
//	e2display.init();


}
