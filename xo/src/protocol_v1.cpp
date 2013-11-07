#include "../include/xo_util.h"
#include "../include/protocol_v1.h"
#include "../include/pin.h"

using namespace std;

//initialize all GPIO pins as output with 0 v
void pin_init()
{
    for (int index = 0; index <9; index++){
        bcm2835_gpio_fsel(pins[index], BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(pins[index], LOW);
    }
}

void update_pinMask( coreData *core, int cell, char color )
{
    
    int mask = 0;

    if ( core == NULL )
    {
        createException("update_pinMask has null coreData");
    }

    switch ( cell )
    {
        case 1:
            if ( color == 'r' )
                mask = (1 << V1R) | (1 << H2) | (1 << H3);
            else
                mask = (1 << V1B) | (1 << H2) | (1 << H3);
            break;
        case 2:
            if ( color == 'r' )
                mask = (1 << V2R) | (1 << H2) | (1 << H3);
            else
                mask = (1 << V2B) | (1 << H2) | (1 << H3);
            break;
        case 3:
            if ( color == 'r' )
                mask = (1 << V3R) | (1 << H2) | (1 << H3);
            else
                mask = (1 << V3B) | (1 << H2) | (1 << H3);
            break;
        case 4:
            if ( color == 'r' )
                mask = (1 << V1R) | (1 << H1) | (1 << H3);
            else
                mask = (1 << V1B) | (1 << H1) | (1 << H3);
            break;
        case 5:
            if ( color == 'r' )
                mask = (1 << V2R) | (1 << H1) | (1 << H3);
            else
                mask = (1 << V2B) | (1 << H1) | (1 << H3);
            break;
        case 6:
            if ( color == 'r' )
                mask = (1 << V3R) | (1 << H1) | (1 << H3);
            else
                mask = (1 << V3B) | (1 << H1) | (1 << H3);
            break;
        case 7:
            if ( color == 'r' )
                mask = (1 << V1R) | (1 << H1) | (1 << H2);
            else
                mask = (1 << V1B) | (1 << H1) | (1 << H2);
            break;
        case 8:
            if ( color == 'r' )
                mask = (1 << V2R) | (1 << H1) | (1 << H2);
            else
                mask = (1 << V2B) | (1 << H1) | (1 << H2);
            break;
        case 9:
            if ( color == 'r' )
                mask = (1 << V3R) | (1 << H1) | (1 << H2);
            else
                mask = (1 << V3B) | (1 << H1) | (1 << H2);
            break;
        default:
            printf("Error in update_pinMask\n");
    }

    core->mtx->lock();
    core->pinMaskList->push_back( mask );
    core->mtx->unlock();
}
