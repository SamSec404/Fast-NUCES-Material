#include <stdio.h>
#include <unistd.h>

int main(void) {
    alarm(5);          // send SIGALRM to this process after 5 seconds

    printf("Looping forever...\n");
    printf("Watch what happens after 5 seconds!\n");

    while (1);         // infinite loop - alarm will interrupt this

    return 0;
}
