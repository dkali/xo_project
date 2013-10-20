#include "../include/xo_util.h"

using namespace std;

int main()
{
    int result = 0;

    pthread_t thBlinker;

    result = init();
    if (result != 0)
        printf("ERROR: initialization failed\n");

    result = pthread_create( &thBlinker, NULL, &ledProcessing, NULL );
    if (result != 0)
        printf("ERROR: blinker thread was not started\n");

    pthread_join(thBlinker, NULL);

    uninit();
    return 0;
}
