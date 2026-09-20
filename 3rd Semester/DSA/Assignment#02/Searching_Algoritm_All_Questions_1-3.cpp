//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int linearsearch(int arr[], int size, int target)
{
	for(int i=0; i<size; i++)
	{
		if(arr[i]==target)
		{
			return i;
		}
	}
	
	return -1;
}

int main()
{
	int arr[]={10, 25, 30, 45, 50, 65, 70, 85, 90};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Array\n";
	
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	int target=45;
	
	cout<<"\n\nSearching for "<<target;
	
	int result=linearsearch(arr, size, target);
	
	if(result!=-1)
	{
		cout<<"\nFound at index "<<result;
	}
	else
	{
		cout<<"\nTarget not found\n";
	}
	
	
	return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int binarysearchiterative(int arr[], int size, int target)
{
	int left=0;
	int right=size-1;
	
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		
		if(arr[mid]==target)
		{
			return mid;
		}
		
		if(arr[mid]<target)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	
	return -1;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Sorted Array\n";
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	int target=4;
	cout<<"\n\nSearching for "<<target;
	int result=binarysearchiterative(arr, size, target);
	
	if(result!=-1)
	{
		cout<<"\nFound at index "<<result<<"\n\n";
	}
	else
	{
		cout<<"Not Found\n\n";
	}
	
	
	
	return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int binarysearchrecursive(int arr[], int left, int right, int target)
{
	//base case 1, element not found
	if(left>right)
	{
		return -1;
	}
	
	//finding middle index
	int mid=left+(right-left)/2;
	
	//base case 2, element found at middle
	if(arr[mid]==target)
	{
		return mid;
	}
	
	//recursive case 1, element is at right half
	if(arr[mid]<target)
	{
		return binarysearchrecursive(arr, mid+1, right, target);
	}
	
	//recursive case 2, element is at left half
	return binarysearchrecursive(arr, left, mid-1, target);
}

int main()
{
	int arr[]={1, 2, 3, 4, 5, 6, 7};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Sorted Array\n";
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	int target=4;
	cout<<"\n\nSearching for "<<target;
	int result=binarysearchrecursive(arr, 0, size-1, target);
	
	if(result!=-1)
	{
		cout<<"\nFound at index "<<result;
	}
	else
	{
		cout<<"Not Found\n\n";
	}
	
	
	return 0;
}
//*/


