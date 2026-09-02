#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myHandler(int s)
{
	printf("Ctrl+C caught");
}

int main()
{
	signal(SIGINT, myHandler);
	
	printf("Press Ctrl+C, Program will not die");
	
	while(1);
	
	return 0;
}
