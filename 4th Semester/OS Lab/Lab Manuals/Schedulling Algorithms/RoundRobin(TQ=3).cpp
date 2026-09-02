#include <stdio.h>

int main()
{
	int n=3;
	
	int pid[]={1,2,3};
	int at[]={0,2,4};
	int bt[]={5,1,3};
	
	int ct[n];
	int tat[n];
	int wt[n];
	
	int tq=3;
	
	int remaining[3];
	
	int completed=0;
	int currtime=0;
	
	for(int i=0; i<n; i++)
	{
		remaining[i]=bt[i];
	}
	
	while(completed<n)
	{
		int executed=0;
		
		for(int i=0; i<n; i++)
		{
			if(at[i]<=currtime && remaining[i]>0)
			{
				executed=1;
				
				if(remaining[i]>tq)
				{
					currtime+=tq;
					remaining[i]-=tq;
				}
				else
				{
					currtime+=remaining[i];
					ct[i]=currtime;
					remaining[i]=0;
					completed++;
				}
			}
		}
		
		if(!executed)
		{
			currtime++;
			continue;
		}
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
