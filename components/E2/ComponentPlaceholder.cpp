/*
 * Component.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "ComponentPlaceholder.h"

namespace display {

ComponentPlaceholder::ComponentPlaceholder():
		PixelContainer(0, 0) {
	x = 0;
	y = 0;
}

ComponentPlaceholder::ComponentPlaceholder(uint32_t w, uint32_t h):
		PixelContainer(w, h) {
	x = 0;
	y = 0;
}

ComponentPlaceholder::ComponentPlaceholder(uint32_t x, uint32_t y, uint32_t w, uint32_t h):
		PixelContainer(w, h) {
	this->x = x;
	this->y = y;
}

ComponentPlaceholder::~ComponentPlaceholder() {}

} /* namespace display */
