#ifndef PIN_H
#define PIN_H

#include <bcm2835.h>

#define V1R RPI_V2_GPIO_P1_03
#define V1B RPI_V2_GPIO_P1_05
#define V2R RPI_V2_GPIO_P1_07
#define V2B RPI_V2_GPIO_P1_11
#define V3R RPI_V2_GPIO_P1_13
#define V3B RPI_V2_GPIO_P1_15
#define H1 RPI_V2_GPIO_P1_08
#define H2 RPI_V2_GPIO_P1_10
#define H3 RPI_V2_GPIO_P1_12

//pins to controll GPIO
static RPiGPIOPin pins[9] = {V1B, V1R, V2B, V2R, V3B, V3R, H1, H2, H3};
 
#endif //PIN_H
