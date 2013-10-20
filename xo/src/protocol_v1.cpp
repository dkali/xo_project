#include "../include/protocol_v1.h"
#include "../include/xo_util.h"

using namespace std;

//initialize all GPIO pins as output with 0 v
void pin_init()
{
    for (int index = 0; index <9; index++){
        bcm2835_gpio_fsel(pins[index], BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(pins[index], LOW);
    }
}

void update_pinMask( pair<map<int,char>::iterator,bool> pr )
{

}
