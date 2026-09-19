//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		bool swapped=false;
		
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=true;
			}
		}
		
		if(!swapped)
		{
			break;
		}
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements\n";
    
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	
    bubblesort(arr, n);
    
    cout<<"\nSorted Array\n";
    
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void selectionsort(int arr[], int n)
{	
	for(int i=0; i<n-1; i++)
	{
		int minindex=i;
		
		for(int j=i+1; j<n; j++)
		{
			if(arr[j]<arr[minindex])
			{
				minindex=j;
			}
		}
		
		if(minindex!=i)
		{
			int temp=arr[i];
			arr[i]=arr[minindex];
			arr[minindex]=temp;
		}
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"\nEnter "<<n<<" elements\n";
    
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	
    selectionsort(arr, n);
    
    cout<<"\n\nSorted Array\n";
    
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int key=arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements\n";
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    insertionsort(arr, n);
    
    cout<<"\nSorted Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#04***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
	int n1=mid-left+1;
	int n2=right-mid;
	
	int leftarr[n1];
	int rightarr[n2];
	
	for(int i=0; i<n1; i++)
	{
		leftarr[i]=arr[left+i];
	}
	
	for(int i=0; i<n2; i++)
	{
		rightarr[i]=arr[mid+1+i];
	}
	
	int i=0;
	int j=0;
	int k=left;
	
	while(i<n1 && j<n2)
	{
		if(leftarr[i]<=rightarr[j])
		{
			arr[k]=leftarr[i];
			i++;
		}
		else
		{
			arr[k]=rightarr[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		arr[k]=leftarr[i];
		i++;
		k++;
	}
	
	while(j<n2)
	{
		arr[k]=rightarr[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int left, int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements\n\n";
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    mergesort(arr,0,n-1);
    
    cout<<"\nSorted Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#05***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low-1;
	
	for(int j=low; j<high; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	
	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	
	return i+1;
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi=partition(arr, low, high);
		
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements\n";
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    quicksort(arr, 0, n-1);
    
    cout<<"\nSorted Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && arr[left]>arr[largest])
	{
		largest=left;
	}
	
	if(right<n && arr[right]>arr[largest])
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(arr,n,i);
	}
	
	cout<<"Max Heap\n";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	
	cout<<"\n\nExtracting elements\n";
	for(int i=n-1; i>0; i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		
		cout<<"\nExtracted "<<arr[i]<<", Array\n";
		for(int j=0; j<n; j++)
		{
			cout<<arr[j]<<"\t";
		}
		
		heapify(arr, i, 0);
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements\n";
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
    
    heapsort(arr, n);
    
    cout<<"\nSorted Array";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#07***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void countingsort(int arr[], int n)
{
	int max=arr[0];
	
	for(int i=1; i<n; i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	cout<<"\nMaximum element\t"<<max<<"\n";
	
	int count[max+1]={0};
	
	for(int i=0; i<n; i++)
	{
		count[arr[i]]++;
	}
	
	cout<<"Frequency Array\n";
	
	for(int i=0; i<=max; i++)
	{
		if(count[i]>0)
		{
			cout<<"Element "<<i<<" appears "<<count[i]<<" times\n";
		}
	}
	
	cout<<"\nModifying count array\n";
	
	for(int i=1; i<=max; i++)
	{
		count[i]+=count[i-1];
	}
	
	int output[n];
	
	cout<<"\nPlacing elements in sorted order\n";
	
	for(int i=n-1; i>=0; i--)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	
	for(int i=0; i<n; i++)
	{
		arr[i]=output[i];
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements\t";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" non-negative integers\n";
    
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    countingsort(arr,n);
    
    cout<<"\nSorted Array\n";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
    
    return 0;
}
*/




