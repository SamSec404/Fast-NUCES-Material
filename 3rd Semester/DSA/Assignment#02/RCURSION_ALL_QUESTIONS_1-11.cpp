//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void printsubsets(int arr[], int n, int index, int subset[], int subsetsize)
{
	if(index==n)
	{
		for(int i=0; i<subsetsize; i++)
		{
			cout<<subset[i];
			if(i<subsetsize-1)
			{
				cout<<",";
			}
		}
		cout<<"\n";
		return;
	}
	
	subset[subsetsize]=arr[index];
	
	printsubsets(arr,n,index+1,subset,subsetsize+1);
	
	printsubsets(arr,n,index+1,subset,subsetsize);
}

int main()
{
    int n;
    cout<<"Enter number of elements for array\t";
    cin>>n;
    
    int ary[n];
    cout<<"Enter "<<n<<" elements\n\n";
    
    for(int i=0; i<n; i++)
	{
		cin>>ary[i];
	}
    
    int subset[n];
    
    cout<<"\nAll Subsets\n\n";
    
    printsubsets(ary,n,0,subset,0);
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
#include<string>
using namespace std;

void permutating(string s, int left, int right)
{
	if(left==right)
	{
		cout<<s<<"\n";
		return;
	}
	
	for(int i=left; i<=right; i++)
	{
		char temp=s[left];
		s[left]=s[i];
		s[i]=temp;
		
		permutating(s,left+1,right);
		
		temp=s[left];
		s[left]=s[i];
		s[i]=temp;
	}
}

int main()
{
    string str;
    cout<<"Enter a string\t";
    cin>>str;
    
//    cout<<str.length();
    
    cout<<"\nAll Permutations\n\n";
    permutating(str, 0, str.length()-1);
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

bool subsetsum(int arr[], int n, int sum)
{
	if(sum==0)
	{
		return true;
	}
	
	if(n==0)
	{
		return false;
	}
	
	if(arr[n-1]>sum)
	{
		return subsetsum(arr, n-1, sum);
	}
	
	return subsetsum(arr, n-1, sum) || subsetsum(arr, n-1, sum-arr[n-1]);
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
    
    int sum;
    cout<<"Enter target sum\t";
    cin>>sum;
    
    if(subsetsum(arr, n, sum))
	{
		cout<<"\nTrue (subset with sum "<<sum<<" exists)\n";
	}
	else
	{
		cout<<"\nFalse (no subset with sum "<<sum<<")\n";
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#04***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if(n==0)
	{
		return 0;
	}
	
	if(n==1)
	{
		return 1;
	}
	
	return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    cout<<"Enter n\t";
    cin>>n;
    
    cout<<"\nFirst "<<n<<" Fibonacci numbers\n\n";
    
    for(int i=0; i<n; i++)
	{
		cout<<fibonacci(i)<<"\t";
	}
	cout<<"\n";
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#05***********----------------------------------------------------------------

/*
#include<iostream>
#include<string>
using namespace std;

void reversestring(string& str, int start, int end)
{
	if(start>=end)
	{
		return;
	}
	
	char temp=str[start];
	str[start]=str[end];
	str[end]=temp;
	
	reversestring(str, start+1, end-1);
}

int main()
{
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    
    cout<<"\nOriginal String: "<<str<<"\n";
    
    reversestring(str, 0, str.length()-1);
    
    cout<<"Reversed String: "<<str<<"\n";
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int power(int x, int n)
{
	if(n==0)
	{
		return 1;
	}
	
	if(n%2==0)
	{
		int half=power(x, n/2);
		return half*half;
	}
	else
	{
		return x*power(x, n-1);
	}
}

int main()
{
    int x,n;
    
    cout<<"Enter base\t";
    cin>>x;
    
    cout<<"Enter exponent\t";
    cin>>n;
    
    int result=power(x, n);
    
    cout<<"\n"<<x<<"^"<<n<<" = "<<result<<"\n";
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#07***********----------------------------------------------------------------

///*
#include<iostream>
using namespace std;

int countdigits(int num)
{
	if(num==0)
	{
		return 0;
	}
	
	return 1+countdigits(num/10);
}

int main()
{
    int num;
    cout<<"Enter a number\t";
    cin>>num;
    
    if(num==0)
	{
		cout<<"\nNumber of digit 1\n";
	}
	else
	{
		int digits=countdigits(num);
		cout<<"\nNumber of digits are\t"<<digits;
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#08***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int target)
{
	if(left>right)
	{
		return -1;
	}
	
	int mid=left+(right-left)/2;
	
	if(arr[mid]==target)
	{
		return mid;
	}
	
	if(arr[mid]>target)
	{
		return binarysearch(arr, left, mid-1, target);
	}
	
	return binarysearch(arr, mid+1, right, target);
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" sorted elements:\n";
    for(int i=0; i<n; i++)
	{
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}
    
    int target;
    cout<<"Enter element to search: ";
    cin>>target;
    
    int result=binarysearch(arr, 0, n-1, target);
    
    if(result!=-1)
	{
		cout<<"\nFound at index "<<result<<"\n";
	}
	else
	{
		cout<<"\nNot Found\n";
	}
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#09***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int findmax(int arr[], int n)
{
	if(n==1)
	{
		return arr[0];
	}
	
	int maxrest=findmax(arr, n-1);
	
	if(arr[n-1]>maxrest)
	{
		return arr[n-1];
	}
	else
	{
		return maxrest;
	}
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0; i<n; i++)
	{
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}
    
    int maximum=findmax(arr, n);
    
    cout<<"\nMaximum element: "<<maximum<<"\n";
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#10***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

int countoccurrences(int arr[], int n, int target)
{
	if(n==0)
	{
		return 0;
	}
	
	int count=countoccurrences(arr, n-1, target);
	
	if(arr[n-1]==target)
	{
		return count+1;
	}
	
	return count;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0; i<n; i++)
	{
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}
    
    int target;
    cout<<"Enter target number: ";
    cin>>target;
    
    int count=countoccurrences(arr, n, target);
    
    cout<<"\nOccurrences of "<<target<<": "<<count<<"\n";
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#11***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

void reversearray(int arr[], int start, int end)
{
	if(start>=end)
	{
		return;
	}
	
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	
	reversearray(arr, start+1, end-1);
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0; i<n; i++)
	{
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}
    
    cout<<"\nOriginal Array: ";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
    
    reversearray(arr, 0, n-1);
    
    cout<<"Reversed Array: ";
    for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
    
    return 0;
}
*/




