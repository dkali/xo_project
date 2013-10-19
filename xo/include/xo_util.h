#ifndef XO_UTIL_H
#define XO_UTIL_H

#include <cfuhash.h>
#include <stdio.h>
#include "pin.h"
#include <pthread.h>

RPiGPIOPin pinLight[9];

//function prototypes
int init();
void* ledProcessing(void *arg);
void uninit();

#endif //XO_UTIL_H
