#include<stdio.h>

int main()
{
	int n;
	
	printf("Enter total no of processes\t");
	scanf("%d",n);
	
	int pid[n];
	int ct[n];
	int at[n];
	int tat[n];
	int bt[n];
	int wt[n];
	
	int currtime=0;
	
	for(int i=0; i<n; i++)
	{
		pid[i]=i+1;
		
		printf("Enter Arrival time and brust time for process id %d",pid[i]);
		
		scanf("%d%d",at[i],bt[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		if(currtime<at[i])
		{
			currtime=at[i];
		}
		currtime+=bt[i];
		ct[i]=currtime;
	}
	
	return 0;
}













