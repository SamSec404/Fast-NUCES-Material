//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Stack
{
	private:
	    int* ary;
	    int top;
	    int capacity;
	
	public:
	    Stack(int size)
		{
			capacity=size;
			ary=new int[capacity];
			top=-1;
		}
		
		~Stack()
		{
			delete[] ary;
		}
		
		void push(int x)
		{
			if(top==capacity-1)
			{
				cout<<"\nStack Overflow";
				return;
			}
			
			top++;
			ary[top]=x;
		}
		
		void pop()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			top--;
		}
		
		void peek()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nTop element is "<<ary[top]<<"\n";
		}
		
		bool isEmpty()
		{
			return top==-1;
		}
		
		void display()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack elements\n";
			
			for(int i=top; i>=0; i--)
			{
				cout<<ary[i]<<"\t";
			}
		}
};

int main()
{
    int size;
    cout<<"Enter stack size\t";
    cin>>size;
    
    Stack s(size);
    
    int choice, value;
    
    while(true)
	{
		cout<<"\n------Stack Operations-----\n";
		
		cout<<"1.	Push\n";
		cout<<"2.	Pop\n";
		cout<<"3.	Peek\n";
		cout<<"4.	Check if Empty\n";
		cout<<"5.	Display Stack\n";
		cout<<"6.	Exit\n";
		
		cout<<"Enter your choice\t";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to push\t";
				cin>>value;
				s.push(value);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
				s.peek();
				break;
				
			case 4:
				if(s.isEmpty())
				{
					cout<<"\nStack is Empty\n";
				}
				else
				{
					cout<<"\nStack is Not Empty\n";
				}
				break;
				
			case 5:
				s.display();
				break;
				
			case 6:
				cout<<"\nExiting\n";
				return 0;
				
			default:
				cout<<"\nInvalid choice\n\n";
		}
	}
    
    return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	
	    Node(int d):data(d),next(NULL){}
};

class Stack
{
	private:
	    Node* top;
	
	public:
	    Stack():top(NULL){}
		
		void push(int x)
		{
			Node* newnode=new Node(x);
			newnode->next=top;
			top=newnode;
		}
		
		void pop()
		{
			if(top==NULL)
			{
				cout<<"\nStack Underflow\n";
				return;
			}
			
			Node* temp=top;
			top=top->next;
			delete temp;
		}
		
		void peek()
		{
			if(top==NULL)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nTop element is\t"<<top->data<<"\n";
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		void display()
		{
			if(top==NULL)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack elements\n";
			Node* temp=top;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n";
		}
};

int main()
{
    Stack s;
    
    int choice, value;
    
    while(true)
	{
		cout<<"\n-------Stack Operations------\n";
		
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Peek\n";
		cout<<"4. Check if Empty\n";
		cout<<"5. Display Stack\n";
		cout<<"6. Exit\n";
		
		cout<<"Enter your choice\t";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to push\t";
				cin>>value;
				s.push(value);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
				s.peek();
				break;
				
			case 4:
				if(s.isEmpty())
				{
					cout<<"\nStack is Empty\n";
				}
				else
				{
					cout<<"\nStack is Not Empty\n";
				}
				break;
				
			case 5:
				s.display();
				break;
				
			case 6:
				cout<<"\nExiting...\n";
				return 0;
				
			default:
				cout<<"\nInvalid choice\n";
		}
	}
    
    return 0;
}
*/




//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Stack
{
	private:
	    int* arr;
	    int top;
	    int capacity;
	
	public:
	    Stack(int size)
		{
			capacity=size;
			arr=new int[capacity];
			top=-1;
		}
		
		~Stack()
		{
			delete[] arr;
		}
		
		void push(int x)
		{
			if(top==capacity-1)
			{
				cout<<"\nStack Overflow\n";
				return;
			}
			top++;
			arr[top]=x;
		}
		
		int pop()
		{
			if(top==-1)
			{
				cout<<"\nStack Underflow\n";
				return -1;
			}
			return arr[top--];
		}
		
		bool isEmpty()
		{
			return top==-1;
		}
		
		void display()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack\n";
			for(int i=top; i>=0; i--)
			{
				cout<<arr[i]<<"\t";
			}
		}
		
		void insertatbottom(int x)
		{
			if(isEmpty())
			{
				push(x);
				return;
			}
			
			int temp=pop();
			insertatbottom(x);
			push(temp);
		}
		
		void reverse()
		{
			if(isEmpty())
			{
				return;
			}
			
			int temp=pop();
			reverse();
			insertatbottom(temp);
		}
};

int main()
{
    Stack s(10);
    
    cout<<"Enter 4 values to push\n";
    int val;
    
    for(int i=0; i<4; i++)
	{
		cin>>val;
		s.push(val);
	}
    
    cout<<"\nOriginal Stack\n";
    s.display();
    
    s.reverse();
    
    cout<<"\nReversed Stack\n";
    s.display();
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#04***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Stack
{
	private:
	    int* arr;
	    int top;
	    int capacity;
	
	public:
	    Stack(int size)
		{
			capacity=size;
			arr=new int[capacity];
			top=-1;
		}
		
		~Stack()
		{
			delete[] arr;
		}
		
		void push(int x)
		{
			if(top==capacity-1)
			{
				cout<<"\nStack Overflow\n";
				return;
			}
			top++;
			arr[top]=x;
		}
		
		int pop()
		{
			if(top==-1)
			{
				cout<<"\nStack Underflow\n";
				return -1;
			}
			return arr[top--];
		}
		
		int peek()
		{
			if(top==-1)
			{
				return -1;
			}
			return arr[top];
		}
		
		bool isEmpty()
		{
			return top==-1;
		}
		
		void display()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack\n";
			for(int i=top; i>=0; i--)
			{
				cout<<arr[i]<<"\t";
			}
			cout<<"\n";
		}
		
		void sortedinsert(int x)
		{
			if(isEmpty() || peek()>x)
			{
				push(x);
				return;
			}
			
			int temp=pop();
			sortedinsert(x);
			push(temp);
		}
		
		void sortstack()
		{
			if(isEmpty())
			{
				return;
			}
			
			int temp=pop();
			sortstack();
			sortedinsert(temp);
		}
};

int main()
{
    Stack s(10);
    
    cout<<"Enter 5 values to push\n";
    int val;
    
    for(int i=0; i<5; i++)
	{
		cin>>val;
		s.push(val);
	}
    
    cout<<"\nOriginal Stack\n";
    s.display();
    
    s.sortstack();
    
    cout<<"\nSorted Stack\n";
    s.display();
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#05***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	
	    Node(int d):data(d),next(NULL){}
};

class Stack
{
	private:
	    Node* top;
	
	public:
	    Stack():top(NULL){}
		
		void push(int x)
		{
			Node* newnode=new Node(x);
			newnode->next=top;
			top=newnode;
		}
		
		int pop()
		{
			if(top==NULL)
			{
				cout<<"\nStack Underflow\n";
				return -1;
			}
			
			Node* temp=top;
			int val=top->data;
			top=top->next;
			delete temp;
			return val;
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		int size()
		{
			int count=0;
			Node* temp=top;
			
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
		
		void display()
		{
			if(top==NULL)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack\n";
			Node* temp=top;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		void deletemiddlehelper(int current, int mid)
		{
			if(current==mid)
			{
				pop();
				return;
			}
			
			int temp=pop();
			deletemiddlehelper(current+1, mid);
			push(temp);
		}
		
		void deletemiddle()
		{
			if(isEmpty())
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			int mid=size()/2;
			deletemiddlehelper(0, mid);
		}
};

int main()
{
    Stack s;
    
    cout<<"Enter 5 values to push\n";
    int val;
    for(int i=0; i<5; i++)
	{
		cin>>val;
		s.push(val);
	}
    
    cout<<"\nOriginal Stack\n";
    s.display();
    
    s.deletemiddle();
    
    cout<<"\nAfter Deleting Middle Element\n";
    s.display();
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
#include<string>
using namespace std;

class Node
{
	public:
	    char data;
	    Node* next;
	
	    Node(char d):data(d),next(NULL){}
};

class Stack
{
	private:
	    Node* top;
	
	public:
	    Stack():top(NULL){}
		
		void push(char x)
		{
			Node* newnode=new Node(x);
			newnode->next=top;
			top=newnode;
		}
		
		char pop()
		{
			if(top==NULL)
			{
				return '\0';
			}
			
			Node* temp=top;
			char val=top->data;
			top=top->next;
			delete temp;
			return val;
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		bool isbalanced(string str)
		{
			Stack s;
			
			for(int i=0; i<str.length(); i++)
			{
				char ch=str[i];
				
				if(ch=='(' || ch=='{' || ch=='[')
				{
					s.push(ch);
				}
				else if(ch==')' || ch=='}' || ch==']')
				{
					if(s.isEmpty())
					{
						return false;
					}
					
					char topch=s.pop();
					
					if((ch==')' && topch!='(') || (ch=='}' && topch!='{') || (ch==']' && topch!='['))
					{
						return false;
					}
				}
			}
			
			return s.isEmpty();
		}
};

int main()
{
    string expression;
    
    cout<<"Enter expression with parentheses\t";
    cin>>expression;
    
    Stack st;
    
    if(st.isbalanced(expression))
	{
		cout<<"\nBalanced\n";
	}
	else
	{
		cout<<"\nNot Balanced\n";
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#07***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	
	    Node(int d):data(d),next(NULL){}
};

class Stack
{
	private:
	    Node* top;
	
	public:
	    Stack():top(NULL){}
		
		void push(int x)
		{
			Node* newnode=new Node(x);
			newnode->next=top;
			top=newnode;
		}
		
		int pop()
		{
			if(top==NULL)
			{
				return -1;
			}
			
			Node* temp=top;
			int val=top->data;
			top=top->next;
			delete temp;
			return val;
		}
		
		int peek()
		{
			if(top==NULL)
			{
				return -1;
			}
			return top->data;
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		void nextgreaterelement(int arr[], int n)
		{
			Stack s;
			int result[n];
			
			for(int i=n-1; i>=0; i--)
			{
				while(!s.isEmpty() && s.peek()<=arr[i])
				{
					s.pop();
				}
				
				if(s.isEmpty())
				{
					result[i]=-1;
				}
				else
				{
					result[i]=s.peek();
				}
				
				s.push(arr[i]);
			}
			
			cout<<"\nNext Greater Elements:\n";
			cout<<"Input:  [";
			for(int i=0; i<n; i++)
			{
				cout<<arr[i];
				if(i<n-1) cout<<", ";
			}
			cout<<"]\n";
			
			cout<<"Output: [";
			for(int i=0; i<n; i++)
			{
				cout<<result[i];
				if(i<n-1) cout<<", ";
			}
			cout<<"]\n";
		}
};

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
    
    Stack st;
    st.nextgreaterelement(arr, n);
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#08***********----------------------------------------------------------------

///*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	
	    Node(int d):data(d),next(NULL){}
};

class Stack
{
	private:
	    Node* top;
	
	public:
	    Stack():top(NULL){}
		
		void push(int x)
		{
			Node* newnode=new Node(x);
			newnode->next=top;
			top=newnode;
		}
		
		int pop()
		{
			if(top==NULL)
			{
				cout<<"\nStack Underflow\n";
				return -1;
			}
			
			Node* temp=top;
			int val=top->data;
			top=top->next;
			delete temp;
			return val;
		}
		
		int peek()
		{
			if(top==NULL)
			{
				return -1;
			}
			return top->data;
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		int size()
		{
			int count=0;
			Node* temp=top;
			
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
		
		void display()
		{
			if(top==NULL)
			{
				cout<<"\nStack is empty\n";
				return;
			}
			
			cout<<"\nStack";
			Node* temp=top;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		bool checkpalindromehelper(Node* curr, Node*& front)
		{
			if(curr==NULL)
			{
				return true;
			}
			
			bool result=checkpalindromehelper(curr->next, front);
			
			if(result==false)
			{
				return false;
			}
			
			bool check=(curr->data==front->data);
			
			front=front->next;
			
			return check;
		}
		
		bool ispalindrome()
		{
			if(top==NULL)
			{
				return true;
			}
			
			Node* front=top;
			return checkpalindromehelper(top,front);
		}
};

int main()
{
    Stack s;
    
    int n;
    cout<<"Enter number of elements";
    cin>>n;
    
    cout<<"Enter "<<n<<" values to push\n";
    int val;
    for(int i=0; i<n; i++)
	{
		cin>>val;
		s.push(val);
	}
    
    cout<<"\nOriginal Stack\n";
    s.display();
    
    if(s.ispalindrome())
	{
		cout<<"\nPalindrome\n";
	}
	else
	{
		cout<<"\nNot a palindrome\n";
	}
    
    return 0;
}
*/





