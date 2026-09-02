#include <stdio.h>

int main()
{
	int n=4;
	
	int pid[]={1,2,3,4};
	int at[]={0,2,3,5};
	int bt[]={6,4,2,1};
	
	int ct[n];
	int tat[n];
	int wt[n];
	
	int done[n];
	
	int completed=0;
	int currtime=0;
	
	int smallestbt;
	int flag;
	
	for(int i=0; i<n; i++)
	{
		done[i]=0;
	}
	
	while(completed<n)
	{
		smallestbt=-1;
		flag=0;
		
		for(int i=0; i<n; i++)
		{
			if(!done[i] && at[i] <= currtime)
			{
				if(smallestbt==-1 || bt[i]<bt[smallestbt])
				{
					smallestbt=i;
					flag=1;
				}
			}
		}
		
		if(!flag)
		{
			currtime++;
			continue;
		}
		
		currtime+=bt[smallestbt];
		ct[smallestbt]=currtime;
		done[smallestbt]=1;
		completed++;
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
