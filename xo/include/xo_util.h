#ifndef XO_UTIL_H
#define XO_UTIL_H

// #include <cfuhash.h>
#include <stdio.h>
#include "pin.h"
#include <pthread.h>
#include <iostream>
#include <map>

// cfuhash_table_t *ledhash = NULL;
// #define HASH __gnu_cxx
extern std::map<int,char> ledhash;

//function prototypes
int init();
void* ledProcessing(void *arg);
void uninit();

#endif //XO_UTIL_H
