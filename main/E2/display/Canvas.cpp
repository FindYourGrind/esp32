/*
 * Canvas.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "Canvas.h"

namespace display {

Canvas::Canvas(uint32_t w, uint32_t h):
		PixelContainer(w, h) {
}

Canvas::~Canvas() {}

void Canvas::toByteArray(uint8_t* array) {
	forEach([&] (Pixel* p) {
		uint32_t index = p->getX() + ((p->getY() / 8) * getWidth());

		if (p->isValue()) {
			array[index] |= (1 << (p->getY() % 8));
		} else {
			array[index] &= ~(1 << (p->getY() % 8));
		}
	});
}

} /* namespace display */
