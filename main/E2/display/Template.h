/*
 * Template.h
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_DISPLAY_TEMPLATE_H_
#define MAIN_E2_DISPLAY_TEMPLATE_H_

#include <vector>

#include "Canvas.h"
#include "Component.h"

using namespace std;

namespace display {

struct ComponentTemplate {
	uint32_t x;
	uint32_t y;
	uint32_t width;
	uint32_t height;
	string type;
};

class Template {
private:
	Canvas* canvas;
	vector<Component> components;

public:
	Template(uint32_t width, uint32_t height);
	virtual ~Template();

	void addComponent(ComponentTemplate cmpTmpl);
};

} /* namespace display */

#endif /* MAIN_E2_DISPLAY_TEMPLATE_H_ */
