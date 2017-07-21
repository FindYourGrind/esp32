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

using namespace std;

namespace display {

class PixelContainer {

private:
	uint32_t width;
	uint32_t height;
	uint8_t* buffer;

	uint32_t calculateBytePosition(uint32_t x, uint32_t y);

protected:

public:
	PixelContainer(uint32_t w, uint32_t h);
	virtual ~PixelContainer();

	bool setPixel(uint32_t x, uint32_t y, bool value);
	bool setPixel(uint32_t x, uint32_t y);
	bool getPixel(uint32_t x, uint32_t y);
	bool resetPixel(uint32_t x, uint32_t y);

	void forEach(function<void(uint32_t x, uint32_t y, bool value)> cb);
};

} /* namespace display */

#endif /* MAIN_E2_DISPLAY_PIXELCONTAINER_H_ */
