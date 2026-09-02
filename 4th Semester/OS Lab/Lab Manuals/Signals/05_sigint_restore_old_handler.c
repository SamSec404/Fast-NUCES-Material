#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myHandler(int s) 
{
    printf("Ctrl+C caught - not dying yet!\n");
}

int main(void) 
{
    void (*oldHandler)(int);             // variable to save the old handler

    oldHandler = signal(SIGINT, myHandler);  // install new, save old

    printf("First 5 seconds: Ctrl+C is caught...\n");
    sleep(5);

    signal(SIGINT, oldHandler);          // restore old handler (default = kill)

    printf("Next 5 seconds: Ctrl+C will kill again...\n");
    sleep(5);

    printf("Done.\n");
    return 0;
}
