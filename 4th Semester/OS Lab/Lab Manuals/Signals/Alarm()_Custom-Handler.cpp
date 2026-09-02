#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myHandler(int s)
{
	printf("Time is up! SIGALRM caught.\n");
	printf("Back to loop now- press Ctrl+C to exit.\n");
}

int main(void)
{
	signal(SIGALRM, myHandler);
	alarm(5);
	
	printf("Looping forever\n\n");
	printf("Watch after 5 secs\n");
	
	while(1);
	
	return 0;
}
