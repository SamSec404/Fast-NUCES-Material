/*
CT = Time when the process completes execution
TAT = CT - Arival time
WT = TAT - BT 

p  AT B
1 0   4
2 1   3
3 2    2

0 -> p1
4 - P2
7 -> P3
9
ct = 4 , 7 , 9

tat = 4- 0= 4  ; 7 -1 = 6 ;  9 -2 = 7

wt = 4 - 4 = 0; 6-3 = 3 ; 5
*/ 

#include <stdio.h>

int main() {
    int n = 3;
    int pid[] = {1, 2, 3};          // Process IDs: P1, P2, P3
    int at[]  = {0, 1, 2};          // Arrival Times
    int bt[]  = {4, 3, 2};          // Burst Times

    int ct[3], tat[3], wt[3];
    int i;
    int current_time = 0;

    // FCFS scheduling (Assuming already sorted by arrival time)
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];   // CPU idle until the process arrives
        }

        current_time += bt[i];
        ct[i] = current_time;       // Completion time
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];     // Turnaround Time
        wt[i]  = tat[i] - bt[i];    // Waiting Time
    }

    // Display results
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

   /*
    TASK -1:
 
 for n numbers of processes using FCFS do the above caclualtions and also  
 Calculate averages using the formulas:

        1) Average Turnaround Time (Avg TAT)
           Avg TAT = (TAT1 + TAT2 + TAT3 + ... ) / n

        2) Average Waiting Time (Avg WT)
           Avg WT = (WT1 + WT2 + WT3 + ... ) / n
           
           
You must do the comments manually like the given comments above this code 
	    take an assumption on n at and bt show that your manual calculation and code
	    output shows same wt[i] , tat[i] , ct[i] , Avg TAT and Avg WT
    
    */

    return 0;
}

