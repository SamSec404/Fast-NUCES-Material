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
	
	int currtime=0;
	int completed=0;
	
	int smallest;
	int flag;
	
	for(int i=0; i<n; i++)
	{
		done[i]=0;
	}
	
	while(completed<n)
	{
		smallest=-1;
		flag=0;
		
		for(int i=0; i<n; i++)
		{
			if(!done[i] && at[i]<currtime)
			{
				if(smallest==i || bt[i]<bt[smallest])
				{
					smallest=i;
					flag=1;
				}
			}
		}
		
		if(!flag)
		{
			currtime++;
			continue;
		}
		
		currtime=bt[smallest];
		ct[smallest]=currtime;
		done[smallest]=1;
		completed++;
	}
	
	for(int i=0; i<n; i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	
	return 0;
}
