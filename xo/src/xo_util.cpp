#include "../include/xo_util.h"

using namespace std;

map<int,char> ledhash;

int init()
{
    int index = 0;

    if (!bcm2835_init())
        return 1;

    //initialize all GPIO pins as output with 0 v
    for (index = 0; index <9; index++){
        bcm2835_gpio_fsel(pins[index], BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(pins[index], LOW);
    }

    // ledhash = new Hashtable();
    return 0;
}

//function will blink with leds, indicating gamers move.
void* ledProcessing(void *arg)
{
    printf("blinker thread started\n");

    bcm2835_gpio_write(V1B, HIGH);
    bcm2835_gpio_write(H2, HIGH);

    bcm2835_delay(5000);

    return NULL;
}

// free all allocated resources
void uninit()
{
    int index = 0;
    int mask = 0;

    for (index = 0; index < 9; index ++){
        mask |= ( 1 << pins[index] );
    }
    bcm2835_gpio_clr_multi( mask );

    // delete ledhash;
    bcm2835_close();
}