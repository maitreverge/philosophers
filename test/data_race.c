#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int global = 0;
// ! STEP 1 : creation
// for avoiding data races, we need to set a type of variable which is pthread_mutex_t
pthread_mutex_t mutex;

void*	routine()
{
	// ! STEP 4 : using the mutex
	printf("Start of the thread \n");
	sleep(3);
	for (int i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mutex);
		global++;
		pthread_mutex_unlock(&mutex);
	}
	
	printf("End of the thread \n");
	// sleep(3);
}

int main(int ac, char **av)
{
	pthread_t t1, t2;

	// ! STEP 2 : init
	// Then in the main function, we need to initialize it
	pthread_mutex_init(&mutex, NULL);
	

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 1;

	if (pthread_join(t1, NULL) != 0)
		return 1;
	if (pthread_join(t2, NULL) != 0)
		return 1;
	
	printf("Value of global = %i\n\n", global);

	// ! STEP 3 : destroy the mutex

	pthread_mutex_destroy(&mutex);
	

	return 0;
}