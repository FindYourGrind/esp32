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
	pixels = new Pixel[w * h];

	for (uint32_t pixelCount = 0; pixelCount < (w * h); pixelCount++) {
		pixels[pixelCount].setX(pixelCount % w);
		pixels[pixelCount].setY(pixelCount / w);
		pixels[pixelCount].setValue(false);
	}
}

PixelContainer::~PixelContainer() {
	delete[] pixels;
}

Pixel* PixelContainer::getPixelPointer(uint32_t x, uint32_t y) {
	Pixel* result = nullptr;

	if (x < width && y < height) {
		result = &pixels[(y * width) + x];
	}

	return result;
}

bool PixelContainer::getPixel(uint32_t x, uint32_t y) {
	bool result = false;

	if (x < width && y < height) {
		result = pixels[(y * width) + x].isValue();
	}

	return result;
}

bool PixelContainer::setPixel(uint32_t x, uint32_t y, bool value) {
	bool result = false;

	if (x < width && y < height) {
		pixels[(y * width) + x].setValue(value);
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

//void PixelContainer::forEach(function<void(Pixel*)> cb) {
//	for (uint32_t vCounter = 0; vCounter < getHeight(); vCounter++) {
//		for (uint32_t hCounter = 0; hCounter < getWidth(); hCounter++) {
//			cb(getPixelPointer(hCounter, vCounter));
//		}
//	}
//}

} /* namespace display */
