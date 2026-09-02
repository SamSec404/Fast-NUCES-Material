#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t stop=0;

void myHandler(int s)
{
	printf("Time is up\n");
	stop=1;
}

int main()
{
	signal(SIGALRM, myHandler);
	alarm(5);
	
	while(stop==0)
	
	printf("Exited Cleanly");
	
	
	return 0;
}




