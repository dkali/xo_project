#include "pin.h"
#include "xo_util.h"
#include <stdio.h>

//initialize all GPIO pins as output with 0 v
int pin_init()
{
	int index = 0;

	if (!bcm2835_init())
		return 1;

	for (index = 0; index <9; index++){
		bcm2835_gpio_fsel(pins[index], BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_write(pins[index], LOW);
	}

	return 0;
}

//function will blink with leds, indicating gamers move.
void* ledProcessing(void *arg)
{
	printf("blinker thread started\n");

	return NULL;
}
