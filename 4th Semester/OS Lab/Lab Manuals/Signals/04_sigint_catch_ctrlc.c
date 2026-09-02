#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myHandler(int s) 
{
    printf("Ctrl+C caught! Program did not die.\n");
}

int main(void) 
{
    signal(SIGINT, myHandler);   // catch Ctrl+C instead of dying

    printf("Press Ctrl+C - program will not die!\n");

    while (1);                   // handler catches every Ctrl+C

    return 0;
}
