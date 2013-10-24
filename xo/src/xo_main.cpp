#include "../include/xo_util.h"

using namespace std;

int main()
{
    int result = 0;
    coreData *core = NULL;

    pthread_t thBlinker;
    pthread_t thAction;

    result = init( &core );
    if (result != 0)
        printf("ERROR: initialization failed\n");

    cout << "game started" << endl;
    result = pthread_create( &thAction, NULL, &actionProcessing, core );
    if (result != 0)
        printf("ERROR: player actions thread was not started\n");
    result = pthread_create( &thBlinker, NULL, &ledProcessing, core );
    if (result != 0)
        printf("ERROR: blinker thread was not started\n");

    pthread_join(thBlinker, NULL);
    pthread_join(thAction, NULL);

    uninit( &core );
    return 0;
}
