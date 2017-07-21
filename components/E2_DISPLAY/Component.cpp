/*
 * Component.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "Component.h"

namespace display {

Component::Component(Canvas& c):
		ComponentPlaceholder(), canvas{c} {
}

Component::Component(uint32_t w, uint32_t h, Canvas& c):
		ComponentPlaceholder(w, h), canvas{c} {
}

Component::Component(uint32_t x, uint32_t y, uint32_t w, uint32_t h, Canvas& c):
		ComponentPlaceholder(x, y, w, h), canvas{c} {
}

Component::~Component() {

}

bool Component::setCanvasPixel(uint32_t x, uint32_t y, bool value) {
	bool result = false;

    if (x < canvas.getWidth() && y < canvas.getHeight()) {
        value ?
            canvas.setPixel(x, y) :
            canvas.resetPixel(x, y);
        result = true;
    }

	return result;
}

bool Component::setCanvasPixel(uint32_t x, uint32_t y) {
	return setCanvasPixel(x, y, true);
}

bool Component::resetCanvasPixel(uint32_t x, uint32_t y) {
	return setCanvasPixel(x, y, false);
}

bool Component::show(void) {
	bool result = false;

    forEach([&] (Pixel* p) {
        p->isValue() ?
            canvas.setPixel(getX() + p->getX(), getY() + p->getY()) :
            canvas.resetPixel(getX() + p->getX(), getY() + p->getY());
    });

    result = true;

	return result;
}

bool Component::hide(void) {
    forEach([&] (Pixel* p) {
        canvas.resetPixel(getX() + p->getX(), getY() + p->getY());
    });

	return true;
}

} /* namespace display */
