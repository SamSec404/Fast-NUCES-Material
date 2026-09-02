#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5

sem_t sem;

void *thread(void *arg)
{
	int tid=(long)arg;
	
	sem_wait(&sem);
	printf("Thread %d is accessing", tid);
	sleep(2);
	printf("Thread %d is leaving", tid);
	sem_post(&sem);
	return NULL;
}

int main()
{
	sem_init(&sem, 0, 3);
	pthread_t threads[NUM_THREADS];
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, thread, (void *)(long)i);
	}
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	sem_destroy(&sem);
	
	return 0;
}



