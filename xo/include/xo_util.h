#ifndef XO_UTIL_H
#define XO_UTIL_H

// #include <cfuhash.h>
#include <stdio.h>
#include "pin.h"
#include "protocol_v1.h"
#include <pthread.h>
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <list>
#include <mutex>

extern std::map<int,char> ledhash;
extern std::mutex mtx;

//function prototypes
int init();
void* ledProcessing(void *arg);
void* actionProcessing(void *arg);
void uninit();

#endif //XO_UTIL_H
