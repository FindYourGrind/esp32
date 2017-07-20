/*
 * Pixel.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "Pixel.h"

namespace display {

    Pixel::Pixel() {
        x = 0;
        y = 0;
        value = false;
    }

    Pixel::Pixel(uint32_t x, uint32_t y, bool v) {
        this->x = x;
        this->y = y;
        value = v;
    }

    Pixel::~Pixel() {
        // TODO Auto-generated destructor stub
    }

} /* namespace display */
