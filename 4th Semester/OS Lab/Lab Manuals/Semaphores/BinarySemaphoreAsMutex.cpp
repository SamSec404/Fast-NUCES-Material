#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define NUM_INC 20

sem_t sem;
int counter=0;

void *increment(void *arg)
{
	sem_wait(&sem);
	
	for(int i=0; i<NUM_INC; ++i)
	{
		counter++;
		printf("\n\nThread%d = %d", arg, counter);
	}
	
	sem_post(&sem);
	return NULL;
}

int main()
{
	pthread_t threads[NUM_THREADS];
	
	sem_init(&sem, 0, 1);
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, increment, (void *)i);
	}
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	sem_destroy(&sem);
	
	
	return 0;
}












