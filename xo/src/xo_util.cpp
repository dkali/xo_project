#include "../include/xo_util.h"
#include "../include/protocol_v1.h"
#include "../include/pin.h"

using namespace std;

int init( coreData **core )
{
    coreData *pData = NULL;

    if (!bcm2835_init())
        return 1;

    pin_init();

    pData = new coreData;
    pData->ledhash = new map<int,char>;
    pData->mtx = new mutex;
    pData->pinMaskList = new list<int>;
    pData->state = STATE_GAME;

    *core = pData;
    return 0;
}

//function will blink with leds, indicating gamers move.
void* ledProcessing(void *arg)
{
    printf("[led]: thread started\n");
    coreData *core = ( coreData *) arg;

    while (true)
    {
        switch (core->state)
        {
            case STATE_GAME:
            {
                core->mtx->lock();
                for (list<int>::iterator mask = core->pinMaskList->begin(); mask != core->pinMaskList->end(); ++mask)
                {
                    bcm2835_gpio_set_multi( *mask );
                    bcm2835_delay(1);
                    bcm2835_gpio_clr_multi( *mask );
                }
                core->mtx->unlock();
            }
            break;

            case STATE_WIN:
            {

            }
            break;

            case STATE_END:
            {
                printf("[led]: thread exit\n");
                pthread_exit(NULL);
            }
            break;
        }
    }

    printf("[led]: thread exit 2\n");
    return NULL;
}

//function will parse the gamers move.
void* actionProcessing(void *arg)
{    
    coreData *core = ( coreData *) arg;

    printf("[act]: thread started\n");

    while (core->ledhash->size() < 9 )
    {
        string move;
        char cell, color;
        int cellnum = 0;

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

        map<int,char>::iterator ret;
        ret = core->ledhash->find(cellnum);
        if ( ret == core->ledhash->end() )
        {
            pair<map<int,char>::iterator,bool> ret;
            ret = core->ledhash->insert( pair<int,char>(cellnum, color) );

            if ( ret.second == true ) //new move
                update_pinMask( core, cellnum, color );
        }
        else
        {
            printf("take another cell\n");
        }

        // TODO: check for win condition

    }

    if ( core->state == STATE_WIN )
    {
        printf("we have a winner!!\n");
        // TODO: blink winner line
    }

    core->state = STATE_END;
    printf("[act]: thread exit\n");
    return NULL;
}

// free all allocated resources
void uninit( coreData **core  )
{
    coreData *pData = *core;
    int index = 0;
    int mask = 0;

    for (index = 0; index < 9; index ++){
        mask |= ( 1 << pins[index] );
    }
    bcm2835_gpio_clr_multi( mask );

    delete pData->ledhash;
    delete pData->pinMaskList;
    delete pData->mtx;
    delete pData;
    bcm2835_close();
}