/*
 * E2DISPLAY.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: itrambovetskyi
 */

#include "E2DISPLAY.h"

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "sdkconfig.h"

const string E2DISPLAY::CLASS_NAME = "E2 Display";

/**
 *
 */
E2DISPLAY::E2DISPLAY() {
	u8g2 = new U8G2(GPIO_NUM_21, GPIO_NUM_22, 0x78);
}

/**
 *
 */
virtual E2DISPLAY::~E2DISPLAY() {

}

/**
 *
 */
void E2DISPLAY::init (void) {

}

/**
 *
 */
void E2DISPLAY::powerUp (void) {

}

/**
 *
 */
void E2DISPLAY::powerDown (void) {

}

/**
 *
 */
void E2DISPLAY::clean (void) {

}

/**
 *
 */
void E2DISPLAY::fill (void) {

}

