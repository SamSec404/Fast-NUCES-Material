#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myHandler(int s)
{
	printf("\n\nCtrl+C caught, not dying");
}

int main()
{
	void (*oldHandler)(int);
	
	oldHandler=signal(SIGINT, myHandler);
	
	printf("First 5 seconds, ctrl+c will get caught");
	sleep(5);
	
	signal(SIGINT, oldHandler);
	
	printf("\n\nnext 5 secs,ctrl+c will kill again");
	sleep(5);
	
	printf("\n\ndone");
	
	return 0;
}
