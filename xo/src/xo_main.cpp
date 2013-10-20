#include "../include/xo_util.h"

using namespace std;

int main()
{
    int result = 0;

    pthread_t thBlinker;
    pthread_t thAction;

    result = init();
    if (result != 0)
        printf("ERROR: initialization failed\n");

    cout << "game started" << endl;
    result = pthread_create( &thAction, NULL, &actionProcessing, NULL );
    if (result != 0)
        printf("ERROR: player actions thread was not started\n");
    result = pthread_create( &thBlinker, NULL, &ledProcessing, NULL );
    if (result != 0)
        printf("ERROR: blinker thread was not started\n");

    pthread_join(thBlinker, NULL);
    pthread_join(thAction, NULL);

    uninit();
    return 0;
}
