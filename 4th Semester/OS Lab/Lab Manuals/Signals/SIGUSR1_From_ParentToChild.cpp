#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void childHandler(int s)
{
	printf("child is waiting for SIGUSR1 from parrent\n\n");
}

int main(void)
{
	pid_t pid=fork();
	
	if(pid==0)
	{
		signal(SIGUSR1, childHandler);
		printf("Child waiting for SIGUSR1");
		while(1) pause();
	}
	else
	{
		printf("Parrent Id is %d", pid);
		sleep(2);
		
		printf("Parent sending SIGUSR1 to child");
		kill(pid, SIGUSR1);
		sleep(2);
		
		printf("Done");
	}
	
	return 0;
}
