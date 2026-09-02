#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void childHandler(int s) 
{
    printf("[Child] Received SIGUSR1 from parent!\n");
}

int main(void) 
{
    pid_t pid = fork();          // create child process

    if (pid == 0) 
    {
        // --- CHILD ---
        signal(SIGUSR1, childHandler);   // install handler for SIGUSR1

        printf("[Child] Waiting for SIGUSR1...\n");

        while (1) pause();               // sleep until any signal arrives
    }
    else
    {
        // --- PARENT ---
        printf("[Parent] Child PID = %d\n", pid);

        sleep(1);                        // give child time to install handler

        printf("[Parent] Sending SIGUSR1 to child...\n");
        kill(pid, SIGUSR1);              // send signal to child

        sleep(1);                        // let child print before parent exits
        printf("[Parent] Done.\n");
    }

    return 0;
}
