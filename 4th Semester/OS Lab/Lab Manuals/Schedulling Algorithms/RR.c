#include <stdio.h>

/*

P   A   BT
1   0   5
2   2   1
3   4   3

 
ct = 5 , 4 , 7

tat = 9-0 = 9 ; 4-2 = 2 ; 7-4 = 3

wt = 9-5 = 4 ; 2-1 = 1; 3- 3 = 0

*/

int main() {
    
    int n = 3; // number of processes
    int pid[] = {1, 2, 3};
    int at[]  = {0, 2, 4}; 
    int bt[]  = {5, 1, 3};

    int tq = 3; // Time Quantum

    int remaining[3];
    int ct[3], tat[3], wt[3];

    int completed = 0;
    int current_time = 0;
    int i;

    // initialize remaining burst time = burst time
    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            
            // process must have arrived and must have remaining time
            if (remaining[i] > 0 && at[i] <= current_time) {

                executed = 1;

                if (remaining[i] > tq) { 
                    current_time += tq;
                    remaining[i] -= tq;
                } 
                else {
                    current_time += remaining[i];
                    ct[i] = current_time;
                    remaining[i] = 0;
                    completed++;
                }
            }
        }

        // CPU idle handling
        if (!executed) {
            current_time++;
        }
    }

    // calculate TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // print table
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
/*
    TASK -4:
 
 for n numbers of processes using RR with Tq = 4 do the above caclualtions and also  
 Calculate averages using the formulas:

        1) Average Turnaround Time (Avg TAT)
           Avg TAT = (TAT1 + TAT2 + TAT3 + ... ) / n

        2) Average Waiting Time (Avg WT)
           Avg WT = (WT1 + WT2 + WT3 + ... ) / n
           
           
You must do the comments manually like the given comments above this code 
	    take an assumption on n at and bt show that your manual calculation and code
	    output shows same wt[i] , tat[i] , ct[i] , Avg TAT and Avg WT
    
    */
  /*  
     TASK -05:

    ---> In this first version of the Round Robin implementation:
       
       - We are **NOT maintaining a Ready Queue**.
       - Instead, we are using a simple loop that repeatedly checks 
         which process has arrived (AT <= current_time) and still has 
         remaining burst time.

       Because of this approach, the CPU scheduling is technically Round Robin,
       but without using the **actual queue mechanism** used in operating systems.

   --> Your next task:

       Make **Version-2 of this program** where:

       - A proper **Ready Queue is maintained**
       - When a process executes for time quantum and is not completed, 
         it should go back to the end of the queue
       - Newly arrived processes should be added into the queue correctly
       - CPU idle condition should also be handled inside the queue logic

       (This means you will implement REAL RR scheduling using queue operations.)
*/
    return 0;
}

