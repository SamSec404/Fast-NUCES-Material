#include <stdio.h>
#include <unistd.h>

int main(void)
{
	alarm(5);
	
	printf("Looping forever\n\n");
	printf("Watch after 5 secs\n");
	
	while(1);
	
	return 0;
}
