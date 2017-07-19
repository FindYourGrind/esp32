/*
 * PixelContainer.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_DISPLAY_PIXELCONTAINER_H_
#define MAIN_E2_DISPLAY_PIXELCONTAINER_H_

#include <stdint.h>
#include <functional>

#include "Pixel.h"

using namespace std;

namespace display {

class PixelContainer {

private:
	uint32_t width;
	uint32_t height;
	Pixel* pixels;

	bool setPixel(uint32_t x, uint32_t y, bool value);

protected:
	Pixel* getPixelPointer(uint32_t x, uint32_t y);

	void forEach(function<void(Pixel*)> cb);


public:
	PixelContainer(uint32_t w, uint32_t h);

	virtual ~PixelContainer();

	bool getPixel(uint32_t x, uint32_t y);
	bool setPixel(uint32_t x, uint32_t y);
	bool resetPixel(uint32_t x, uint32_t y);
	uint32_t getHeight() const { return height; }
	void setHeight(uint32_t height) { this->height = height; }
	uint32_t getWidth() const { return width; }
	void setWidth(uint32_t width) { this->width = width; }
};

} /* namespace display */

#endif /* MAIN_E2_DISPLAY_PIXELCONTAINER_H_ */
