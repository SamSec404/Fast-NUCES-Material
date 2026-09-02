#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 3

int ary[]={10,20,30};
int sum=0;
volatile sig_atomic_t alarm_fired=0;

sem_t sem;

void alarmHandler(int s)
{
	alarm_fired=1;
}

void *thread(void *arg)
{
	int index=(int)(long)arg;
	sem_wait(&sem);
	
	printf("Thread entered critical section, waitig via alarm\n\n");
	alarm_fired=0;
	signal(SIGALRM, alarmHandler);
	alarm(5);
	
	while(!alarm_fired);
	
	sum+=ary[index];
	
	printf("\nthread%d added ary[%d]=%d to sum, sum=%d", index, index, ary[index], sum);
	
	sem_post(&sem);
	
	return NULL;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	
	sem_init(&sem, 0, 1);
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, thread, (void *)(long)i);
	}
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	sem_destroy(&sem);
	
	printf("\n\nFinal sum=%d", sum);
	
	return 0;
}

