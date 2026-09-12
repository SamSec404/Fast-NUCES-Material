//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

///*
#include <iostream>
using namespace std;


int main()
{
	int ary[]={1,1,2,2,3,3}; //i will take defautl array as in question it said a given array
	
	int n=sizeof(ary)/sizeof(ary[0]); //it will divide the total size of the array by size of 1 element of the array
	
	cout<<"Array before removing duplicate\n\n[";
	
	for(int i=0; i<n; i++)  //running loop until it reaches the last element of the unique array element
	{
		cout<<ary[i];
		if(i<n-1)
		{
			cout<<",";
		}
	}
	
	cout<<sizeof(ary);
	
	if(n==0) //if there is no element in the array
	{
		cout<<"Array is empty\n\n";
		return 0; //exit the programm
	}
	
	int j=0;  //i will set j=0 to compare index i with index j and tracking new unique element 
	
	for(int i=0; i<n; i++) //running loop until it reaches the last element
	{
		if(ary[i]!=ary[j])  //we will update the array when the index i is not equal to the index j, dry run is on the page
		{
			j++;   //increment the j when we get any unique value
			ary[j]=ary[i];  //mov the value at the jth index
		}
	}
	
	int newsize=j+1;  //as we incremented j for every unique element so we knew that all the unique elements at the number of positions as much the value of j+1,
					  //so we created a  new length/size for the array so it will skip the leftover elements 
	
	cout<<"Array after removing duplicate\n\n[";
	
	for(int i=0; i<newsize; i++)  //running loop until it reaches the last element of the unique array element
	{
		cout<<ary[i];
		if(i<newsize-1)
		{
			cout<<",";
		}
	}
	
	cout<<"]\n\n";
	
	return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int main()
{
	int ary[]={100,5,7,8,6,243,4,33,1,2,3};
	
	int n=sizeof(ary)/sizeof(ary[0]);  //calculating size
	
	if(n==0)  //if array is empty
	{
		cout<<"Array is empty\n\n";
		return 0;
	}
	
	//sorting array
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(ary[j]>ary[j+1])
			{
				int temp=ary[j];
				ary[j]=ary[j+1];
				ary[j+1]=temp;
			}
		}
	}
	
	//setting up longest and current consecutive numbers
	int longest=1;
	int current=1;
	
	//running loop until end of the array
	for(int i=0; i<n; i++)
	{
		if(ary[i]+1==ary[i+1])	// when ary[0]+1 that is 1+1=2 after sorting, is equal to ary[0+1] that is 2, we will increment current length
		{
			current++;
		}
		else if(ary[i]!=ary[i+1])  //when they are not equal set the current again to 1 to start from 1
		{
			current=1;
		}
		
		if(current>longest)  //we will assign value of current to longest when the current is greater than the longest for every iteration so that we can save the longest length
		{
			longest=current;
		}
	}
	
	cout<<"length of the consecutive sequence is\t"<<longest;
	
	return 0;
	
}
*/



//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int main()
{
	int ary[]={-1,0,1,-2,3,2,-3};
	int n=sizeof(ary)/sizeof(ary[0]);
	
	if(n==0)  //if array is empty
	{
		cout<<"Array is empty\n\n";
		return 0;
	}
	
	//sorting array
	for(int i=0; i<n; i++)
	{
    	for(int j=0; j<n-1; j++) 
		{
        	if(ary[j]>ary[j+1]) 
			{
            	int temp=ary[j];
    	        ary[j]=ary[j+1];
        	    ary[j+1]=temp;
        	}
    	}
	}
	
	cout<<"unique triplets whose sum is 0\n\n";
	
    bool found = false;
    
    for(int i=0; i<n-2; i++)
    {
    	if(i>0 && ary[i]==ary[i-1])
    	{
    		continue;
		}
		
    	for(int j=i+1; j<n-1; j++)
    	{
    		if(j>i+1 && ary[j]==ary[j-1])
    		{
    			continue;
			}
			
    		for(int k=j+1; k<n; k++)
    		{
    			if(k>j+1 && ary[k]==ary[k-1])
    			{
    				continue;
				}
				
    			if(ary[i]+ary[j]+ary[k]==0)
    			{
    				cout<<ary[i]<<" + "<<ary[j]<<" + "<<ary[k]<<" = 0\n";
    				found=true;
				}
			}
		}
	}

    if(!found)
    {
    	cout<<"No triplets found\n";
	}
	return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#04***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int main()
{
	int ary[]={0,1,0,2,3,4,0,5,4,0,9,0,0,0,9,77,7};
	int n=sizeof(ary)/sizeof(ary[0]);
	
	if(n==0)
	{
		cout<<"Array is empty\n\n";
		return 0;
	}
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(ary[j]==0)
			{
				int temp=ary[j];
				ary[j]=ary[j+1];
				ary[j+1]=temp;
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<ary[i]<<"  ";
	}
	
	
	return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#05***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int main()
{
    int ary[]={3,3,3,3,3,2,2,1,1,1,2,2,1,1,2};
    int n=sizeof(ary)/sizeof(ary[0]);

    int num=ary[0];
    int maxcount=0;

    for(int i=0; i<n; i++)
    {
        int count=0;
        
        for(int j=0; j<n; j++)
        {
            if(ary[i]==ary[j])
            {
            	count++;
			}
        }

        if(count>maxcount)
        {
            maxcount=count;
            num=ary[i];
        }
    }

    cout<<"Majority element is\t"<<num;

    return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int main()
{
	int ary[]={1,1,2,1};
	int n=sizeof(ary)/sizeof(ary[0]);
	
	int k=2;
	int count=0;
	
	for(int i=0;i<n;i++)
	{
	    int sum=0;
	    for(int j=i; j<n; j++)
	    {
	        sum+=ary[j];
	        
	        if(sum==k)
	        {
	        	count++;
			}
	    }
	}
	
	cout<<"total combinations which are equal to 4 are\t"<<count;
	
	
	return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#07***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int  main()
{
	int ary[]={1,1,2,3,2,1,3,4};
	int n=sizeof(ary)/sizeof(ary[0]);
	
	int k=7;
	
	int maxlength = 0;
	    
    for(int i=0; i<n; i++)
    {
        int sum=0;
        
        for(int j=i; j<n; j++)
        {
            sum+=ary[j];
            
            if(sum<=k)
            {
                int length=j-i+1;
                
                if(length>maxlength)
                {
                	maxlength=length;
				}
            }
        }
    }

    cout<<"Length of longest subarray with sum "<<k<<"is\t"<< maxlength;
	
	return 0;
}
*/





