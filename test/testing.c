#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void*	routine()
{
	printf("Start of the thread \n");
	sleep(3);
	printf("End of the thread \n");
	// sleep(3);
}

int main(int ac, char **av)
{
	// ! STEP 1 : creation
	pthread_t t1, t2;
	/*
	to hold a thread during an program execution, we first need to
	create a variable type which is gonna be of type pthread.
	It kind of storing the thread
	
	*/

	// ! STEP 2 : init the thread
	/*
	Then, we need to create the thread itself with a few arguments :
	&t1, NULL, &routine, NULL
	Adress of the variable |the attributes, regarding customizations | the actual function | the arguments to the function)

	*/

	// ! STEP 2.1 : error checking
	/*
	for whatever reason, the thread creation could fail, the execution itself could fail
	that's why we need to check if the thread execution went okay
	*/

	/*
	SO instead of just calling the threads rwa like this :
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);

	We could call them in a if statement like :
	*/

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	{
		// If pthread_create return something that is not 0, it means that it failed
		return 1;
	}
	
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		// If pthread_create return something that is not 0, it means that it failed
		return 1;
	}



	// ! STEP 3 : WAIT
	/*
	Because we don't want the main function to finish during the thread running
	*/

	/*
	same as the pthread_create function, we need to make sure the pthread_join functions
	Execute themselves as they are supposed to
	*/

	if (pthread_join(t1, NULL) != 0)
	{
		return 1;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 1;
	}

	return 0;
}