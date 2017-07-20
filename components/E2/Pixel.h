/*
 * Pixel.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_PIXEL_H_
#define MAIN_E2_PIXEL_H_

#include <stdint.h>

namespace display {

class Pixel {

private:
	uint32_t x;
	uint32_t y;
	bool value;

public:
	Pixel();
	Pixel(uint32_t x, uint32_t y, bool v = false);
	virtual ~Pixel();

	bool isValue() const {
		return value;
	}

	void setValue(bool value) {
		this->value = value;
	}

	uint32_t getX() const {
		return x;
	}

	void setX(uint32_t x) {
		this->x = x;
	}

	uint32_t getY() const {
		return y;
	}

	void setY(uint32_t y) {
		this->y = y;
	}
};

} /* namespace display */

#endif /* MAIN_E2_PIXEL_H_ */
