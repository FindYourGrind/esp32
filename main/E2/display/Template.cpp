/*
 * Template.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: itrambovetskyi
 */

#include "Template.h"

namespace display {

    Template::Template(uint32_t width, uint32_t height) {
        canvas = new Canvas(width, height);
    }

    Template::~Template() {
        delete canvas;
    }

    void Template::addComponent(ComponentTemplate cmpTmpl) {
        
    }

} /* namespace display */
