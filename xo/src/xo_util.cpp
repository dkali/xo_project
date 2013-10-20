#include "../include/xo_util.h"

using namespace std;

map<int,char> ledhash;
mutex mtx;
list<int> pinMask;

int init()
{
    if (!bcm2835_init())
        return 1;

    pin_init();

    return 0;
}

//function will blink with leds, indicating gamers move.
void* ledProcessing(void *arg)
{
    // printf("blinker thread started\n");

    bcm2835_gpio_write(V1B, HIGH);
    bcm2835_gpio_write(H2, HIGH);

    bcm2835_delay(5000);

    return NULL;
}

//function will parse the gamers move.
void* actionProcessing(void *arg)
{    
    while (ledhash.size() < 9 )
    {
        string move;
        char cell, color;
        int cellnum = 0;

        cout << "size is" << ledhash.size() << endl;
        getline(cin, move);
        
        if ( move.size() != 2)
        {
            printf("invalid input\n");
            continue;
        }

        cell = move.at(0);
        color = move.at(1);
        cellnum = atoi(&cell);

        if ( cellnum == 0 || !(color == 'r' || color == 'b') )
        {
            printf("invalid move\n");
            continue;
        }

        pair<map<int,char>::iterator,bool> ret;
        ret = ledhash.insert( pair<int,char>(cellnum, color) );
        // cout << color << " light into " << cell << " cell" << endl;

        // TODO: parse ledhash to mask_array

        // TODO: check for win condition
        update_pinMask( ret );

    }

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

    ledhash.clear();
    pinMask.clear();
    bcm2835_close();
}