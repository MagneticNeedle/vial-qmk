#include "rgb_matrix.h"
uint8_t red = 191;
uint8_t green = 130;
uint8_t blue = 15;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t index = led_min; index < led_max; index++) {
        if (index >= 40 && index < 44) rgb_matrix_set_color(index, red, green, blue);
        if (index == 4) rgb_matrix_set_color(index, 0, 0, 0);
    }
    return true;
}
