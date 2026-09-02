#include <stdio.h>

int main()
{
	int n;
	
	printf("Enter Number of Processes:\t");
	scanf("%d", &n);
	
	int pid[n];
	int at[n];
	int bt[n];
	
	for(int i=0; i<n; i++)
	{
		pid[i]=i+1;
		
		printf("Enter Arrival Time for P%d:\t", pid[i]);
		scanf("%d", &at[i]);
		
		printf("Enter Brust Time for P%d:\t", pid[i]);
		scanf("%d", &bt[i]);
	}
	
	int ct[n];
	int tat[n];
	int wt[n];
	
	int done[n];
	int remaining[n];
	
	for(int i=0; i<n;i++)
	{
		done[i]=0;
		remaining[i]=bt[i];
	}
	
	int completed=0;
	int currtime=0;
	
	while(completeed<n)
	{
		int shortest=-1;
		int flag=0;
		
		for(int i=0; i<n; i++)
		{
			if(!done[i] && at[i]<=currtime && remaining[i]>0)
			{
				if(shortest==-1 || remaining[i]<remaining[shortest])
				{
					shortest=i;
					flag=1;
				}
			}
		}
		
		if(!flag)
		{
			currtime++;
			continue;
		}
		
		remaining[shortest]--;
		currtime++;
		
		if(remaining[i]==0)
		{
			ct[shortest]+=currtime;
			done[shortest]=1;
			completed++;
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
