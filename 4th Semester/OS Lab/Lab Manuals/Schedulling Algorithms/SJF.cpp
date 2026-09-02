/*
CT = Time when the process completes execution
TAT = CT - Arival time
WT = TAT - BT

P  AT   BT
1  0    6
2  2    4
3  3    2
4  5    1

ct = 6 , 13 , 9 , 7

tat = 6 - 0 = 6 ; 13 - 2 =11 ; 9 - 3 = 6 ; 2

WAT = 6-6 = 0 ;  11-4 = 7 ; 6 - 2 = 4 ; 2 -1 = 1
*/
#include <stdio.h>

int main() {
    int n = 4;   // number of processes

    int pid[] = {1, 2, 3, 4};        // Process IDs
    int at[]  = {0, 2, 3, 5};        // Arrival Times
    int bt[]  = {6, 4, 2, 1};        // Burst Times

    int ct[n], tat[n], wt[n];
    int done[n];   // to track completion

    int i;
    int completed = 0, current_time = 0;
    int smallest, flag;

    // initialize done[] = 0
    for (i = 0; i < n; i++) {
        done[i] = 0;
    }

    // Scheduling loop
    while (completed < n) {

        smallest = -1;
        flag = 0;

        // Find available shortest process
        for (i = 0; i < n; i++) {
        	//
            if (!done[i] && at[i] <= current_time) {
                if (smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                    flag = 1;
                }
            }
        }

        // If no process arrived ? CPU idle
        if (!flag) {
            current_time++;
            continue;
        }

        // Execute selected process
        current_time += bt[smallest];
        ct[smallest] = current_time;
        done[smallest] = 1;
        completed++;
    }

    // Calculate TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }

    // Print result
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    /*
    TASK -2:
 
 for n numbers of processes using SJF do the above caclualtions and also  
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
	
	TASK -3:
	
	Repaast the above task for (Shortest Remaining Time First - SRTF) 
	*/

    return 0;
}

