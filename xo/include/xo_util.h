#ifndef XO_UTIL_H
#define XO_UTIL_H

#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <list>
#include <mutex>

enum gameState
{
	STATE_GAME = 0,
	STATE_WIN,
	STATE_END
};

struct coreData
{
    std::map<int,char> *ledhash;
    std::mutex *mtx;
    std::list<int> *pinMaskList;
    gameState state;
};

//function prototypes
int init( coreData **core );
void* ledProcessing(void *arg);
void* actionProcessing(void *arg);
void uninit( coreData **core );

#endif //XO_UTIL_H
