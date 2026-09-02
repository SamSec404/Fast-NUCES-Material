#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;   // 0 = keep running, 1 = stop

void myHandler(int s) 
{
    printf("Time is up! Setting flag to stop the loop.\n");
    stop = 1;                      // loop will exit on next check
}

int main(void) 
{
    signal(SIGALRM, myHandler);

    alarm(5);

    printf("Looping... will exit cleanly after 5 seconds.\n");

    while (stop == 0);             // keep looping until flag becomes 1

    printf("Exited cleanly!\n");
    return 0;
}
