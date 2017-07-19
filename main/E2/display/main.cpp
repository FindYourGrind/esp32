#include <iostream>

#include "Canvas.h"
#include "Component.h"

using namespace display;

int main() {
    Canvas canvas(100, 64);

    Component wifi(0, 0, 20, 20, canvas);
    Component leftArrow(0, 26, 10, 10, canvas);
    Component icon(20, 0, 68, 64, canvas);
    Component rightArrow(97, 26, 10, 10, canvas);
    Component battery(87, 0, 20, 20, canvas);

    wifi.setPixel(0,0);
    leftArrow.setPixel(0,0);
    icon.setPixel(0,0);
    rightArrow.setPixel(0,0);
    battery.setPixel(0,0);

    wifi.show();
    leftArrow.show();
    icon.show();
    rightArrow.show();
    battery.show();

    uint8_t array[128 * 8] = {0};
    canvas.toByteArray(array);

    for (uint32_t y = 0; y < 64; y++) {
        for (uint32_t x = 0; x < 100; x++) {
            std::cout << (canvas.getPixel(x, y) ? "." : "");
        }
        std::cout << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}