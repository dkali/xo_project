#include <stdio.h>
#include "pin.h"
#include "xo_util.h"
#include <pthread.h>

int main()
{
	int result = 0;
	pthread_t thBlinker;

	result = pin_init();
	if (result != 0)
		printf("ERROR: initialization failed\n");

	result = pthread_create( &thBlinker, NULL, &ledProcessing, NULL );
	if (result != 0)
                printf("ERROR: blinker thread was not started\n");

	pthread_join(thBlinker, NULL);

	return 0;
}
