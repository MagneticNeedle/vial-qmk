#include "rgb_matrix.h"
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t index = led_min; index < led_max; index++) {
        switch (index){
        case 1:
            rgb_matrix_set_color(1, 255, 0, 0);
            break;
        default:
            break;
        }
    }
    return true;
}
