#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) 
{
    void (*oldHandler)(int);

    printf("First 5 seconds: Ctrl+C works normally...\n");
    sleep(5);

    oldHandler = signal(SIGINT, SIG_IGN);  // ignore SIGINT completely

    printf("Next 5 seconds: Ctrl+C is ignored - try it...\n");
    sleep(5);                              // kernel discards every Ctrl+C

    signal(SIGINT, oldHandler);            // restore old handler

    printf("Next 5 seconds: Ctrl+C will kill again...\n");
    sleep(5);

    printf("Done.\n");
    return 0;
}
