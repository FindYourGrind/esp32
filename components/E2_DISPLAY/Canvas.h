/*
 * Canvas.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_DISPLAY_CANVAS_H_
#define MAIN_E2_DISPLAY_CANVAS_H_

#include <stdint.h>

#include "PixelContainer.h"

namespace display {

class Canvas: public PixelContainer {

private:

public:
	Canvas(uint32_t w, uint32_t h);
	virtual ~Canvas();

	void toByteArray(uint8_t* array);
};

} /* namespace display */

#endif /* MAIN_E2_DISPLAY_CANVAS_H_ */
