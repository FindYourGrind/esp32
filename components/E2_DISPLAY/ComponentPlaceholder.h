/*
 * Component.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_COMPONENT_H_
#define MAIN_E2_COMPONENT_H_

#include <stdint.h>

#include "PixelContainer.h"

namespace display {

class ComponentPlaceholder: public PixelContainer {

private:
	uint32_t x;
	uint32_t y;

public:
	ComponentPlaceholder();
	ComponentPlaceholder(uint32_t w, uint32_t h);
	ComponentPlaceholder(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
	virtual ~ComponentPlaceholder();

	uint32_t getX() const { return x; }
	void setX(uint32_t x) { this->x = x; }
	uint32_t getY() const { return y; }
	void setY(uint32_t y) { this->y = y; }
};

} /* namespace display */

#endif /* MAIN_E2_COMPONENT_H_ */
