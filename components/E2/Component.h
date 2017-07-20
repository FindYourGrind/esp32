/*
 * Component.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_DISPLAY_COMPONENT_H_
#define MAIN_E2_DISPLAY_COMPONENT_H_

#include "Canvas.h"
#include "ComponentPlaceholder.h"

namespace display {

class Component: public ComponentPlaceholder {

private:
	Canvas& canvas;

	bool setCanvasPixel(uint32_t x, uint32_t y, bool value);
	bool setCanvasPixel(uint32_t x, uint32_t y);
	bool resetCanvasPixel(uint32_t x, uint32_t y);

public:

	Component(Canvas& c);
	Component(uint32_t w, uint32_t h, Canvas& c);
	Component(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Canvas& c);
	virtual ~Component();

	bool show(void);
	bool hide(void);
};

} /* namespace display */

#endif /* MAIN_E2_DISPLAY_COMPONENT_H_ */
