/*
 * PixelContainer.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "PixelContainer.h"


namespace display {

PixelContainer::PixelContainer(uint32_t w, uint32_t h) {
	width = w;
	height = h;

	uint32_t dH = h / 8;
	uint8_t additionalByte = 0;

	if ((dH * 8) < h) {
		additionalByte = 1;
	}

	buffer = new uint8_t[(w * (h / 8)) + (w * additionalByte)]{0};
}

PixelContainer::~PixelContainer() {
	delete buffer;
}

uint32_t PixelContainer::calculateBytePosition(uint32_t x, uint32_t y) {
	return ((y / 8) * width) + x;
}

bool PixelContainer::getPixel(uint32_t x, uint32_t y) {
	bool result = false;

	if (x < width && y < height) {
		result = buffer[calculateBytePosition(x, y)] && (1 << (y % 8));
	}

	return result;
}

bool PixelContainer::setPixel(uint32_t x, uint32_t y, bool value) {
	bool result = false;

	if (x < width && y < height) {
		uint32_t index = calculateBytePosition(x, y);
		value ?
			buffer[index] |= (1 << (y % 8)) :
			buffer[index] &= ~(1 << (y % 8));
		result = true;
	}

	return result;
}

bool PixelContainer::setPixel(uint32_t x, uint32_t y) {
	return setPixel(x, y, true);
}

bool PixelContainer::resetPixel(uint32_t x, uint32_t y) {
	return setPixel(x, y, false);
}

void PixelContainer::forEach(function<void(uint32_t x, uint32_t y, bool value)> cb) {
	for (uint32_t yCounter = 0; yCounter < height / 8; yCounter++) {
		for (uint32_t bitCounter = 0; bitCounter < 8; bitCounter++) {
			for (uint32_t xCounter = 0; xCounter < width; xCounter++) {
				if (xCounter < width && ((yCounter * 8) + bitCounter) < height) {
					cb(xCounter, (yCounter * 8) + bitCounter, buffer[xCounter + (yCounter * width)] & (1 << bitCounter));
				} else {
					continue;
				}
			}
		}
	}
}

} /* namespace display */
