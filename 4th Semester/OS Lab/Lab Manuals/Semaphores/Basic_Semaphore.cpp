#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

int counter=0;

sem_t sem;

void* thread1(void *arg)
{
	sem_wait(&sem);
	counter++;
	printf("thread1=%d",counter);
	sem_post(&sem);
	return NULL;
}

void* thread2(void *arg)
{
	sem_post(&sem);
	counter++;
	printf("thread2=%d\n\n",counter);
	sem_post(&sem);
	return NULL;
}

int main()
{
	sem_init(&sem, 0, 0);
	
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}





