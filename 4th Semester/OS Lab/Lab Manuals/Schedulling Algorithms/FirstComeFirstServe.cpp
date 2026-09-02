#include <stdio.h>

int main()
{
	int n=3;
	
	int pid[]={1,2,3};
	int at[]={0,1,2};
	int bt[]={4,3,2};
	
	int ct[3];
	int tat[3];
	int wt[3];
	
	int currtime=0;
	
	for(int i=0; i<n; i++)
	{
		if(currtime<at[i])
		{
			currtime=at[i];
		}
		
		currtime+=bt[i];
		ct[i]=currtime;
	}
	
	for(int i=0; i<n; i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	
	printf("P\tAT\tBT\tCT\tTAT\tWT\n");
	
	for(int i=0; i<n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}
	
	return 0;
}
