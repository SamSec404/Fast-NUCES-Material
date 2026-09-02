#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myHandler(int s) 
{
    printf("Time is up! SIGALRM caught.\n");
    printf("Back to loop now - press Ctrl+C to exit.\n");
}

int main(void) 
{
    signal(SIGALRM, myHandler);  // install handler before starting timer

    alarm(5);                    // send SIGALRM after 5 seconds

    printf("Looping... SIGALRM will be caught after 5 seconds.\n");

    while (1);                   // handler runs once, then hangs here

    return 0;
}
