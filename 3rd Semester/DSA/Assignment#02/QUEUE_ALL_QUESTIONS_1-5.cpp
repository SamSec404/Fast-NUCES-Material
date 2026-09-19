//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Queue
{
	private:
	    int* arr;
	    int front;
	    int rear;
	    int capacity;
	    int count;
	
	public:
	    Queue(int size)
		{
			capacity=size;
			arr=new int[capacity];
			front=0;
			rear=-1;
			count=0;
		}
		
		~Queue()
		{
			delete[] arr;
		}
		
		void enqueue(int x)
		{
			if(isFull())
			{
				cout<<"\nQueue Overflow! Cannot enqueue "<<x<<"\n";
				return;
			}
			
			rear=(rear+1)%capacity;
			arr[rear]=x;
			count++;
			cout<<"\n"<<x<<" enqueued to queue\n";
		}
		
		void dequeue()
		{
			if(isEmpty())
			{
				cout<<"\nQueue Underflow! Queue is empty\n";
				return;
			}
			
			cout<<"\n"<<arr[front]<<" dequeued from queue\n";
			front=(front+1)%capacity;
			count--;
		}
		
		void frontElement()
 		{
			if(isEmpty())
			{
				cout<<"\nQueue is empty! No front element\n";
				return;
			}
			
			cout<<"\nFront element is: "<<arr[front]<<"\n";
		}
		
		bool isEmpty()
		{
			return count==0;
		}
		
		bool isFull()
		{
			return count==capacity;
		}
		
		void display()
		{
			if(isEmpty())
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nQueue elements (front to rear): ";
			for(int i=0; i<count; i++)
			{
				int index=(front+i)%capacity;
				cout<<arr[index]<<"\t";
			}
			cout<<"\n";
		}
};

int main()
{
    int size;
    cout<<"Enter queue size: ";
    cin>>size;
    
    Queue q(size);
    
    int choice, value;
    
    while(true)
	{
		cout<<"\n----- Queue Operations -----\n";
		
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Front\n";
		cout<<"4. Check if Empty\n";
		cout<<"5. Check if Full\n";
		cout<<"6. Display Queue\n";
		cout<<"7. Exit\n";
		
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to enqueue\t";
				cin>>value;
				q.enqueue(value);
				break;
				
			case 2:
				q.dequeue();
				break;
				
			case 3:
				q.frontElement();
				break;
				
			case 4:
				if(q.isEmpty())
				{
					cout<<"\nQueue is Empty\n";
				}
				else
				{
					cout<<"\nQueue is Not Empty\n";
				}
				break;
				
			case 5:
				if(q.isFull())
				{
					cout<<"\nQueue is Full\n";
				}
				else
				{
					cout<<"\nQueue is Not Full\n";
				}
				break;
				
			case 6:
				q.display();
				break;
				
			case 7:
				cout<<"\nExiting\n";
				return 0;
				
			default:
				cout<<"\nInvalid choice\n";
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

class Queue
{
	private:
	    Node* front;
	    Node* rear;
	
	public:
	    Queue():front(NULL),rear(NULL){}
		
		void enqueue(int x)
		{
			Node* newnode=new Node(x);
			
			if(rear==NULL)
			{
				front=rear=newnode;
				cout<<"\n"<<x<<" enqueued to queue\n";
				return;
			}
			
			rear->next=newnode;
			rear=newnode;
			cout<<"\n"<<x<<" enqueued to queue\n";
		}
		
		void dequeue()
		{
			if(front==NULL)
			{
				cout<<"\nQueue Underflow! Queue is empty\n";
				return;
			}
			
			Node* temp=front;
			cout<<"\n"<<front->data<<" dequeued from queue\n";
			front=front->next;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete temp;
		}
		
		void frontElement()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nFront element is "<<front->data<<"\n";
		}
		
		bool isEmpty()
		{
			return front==NULL;
		}
		
		void display()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nQueue elements (front to rear): ";
			Node* temp=front;
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
    Queue q;
    
    int choice, value;
    
    while(true)
	{
		cout<<"\n----- Queue Operations -----\n";
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Front\n";
		cout<<"4. Check if Empty\n";
		cout<<"5. Display Queue\n";
		cout<<"6. Exit\n";
		
		cout<<"Enter your choice\t";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to enqueue\t";
				cin>>value;
				q.enqueue(value);
				break;
				
			case 2:
				q.dequeue();
				break;
				
			case 3:
				q.frontElement();
				break;
				
			case 4:
				if(q.isEmpty())
				{
					cout<<"\nQueue is Empty\n";
				}
				else
				{
					cout<<"\nQueue is Not Empty\n";
				}
				break;
				
			case 5:
				q.display();
				break;
				
			case 6:
				cout<<"\nExiting\n";
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

class PriorityQueue
{
	private:
	    int* ary;
	    int* priority;
	    int capacity;
	    int size;
	
	public:
	    PriorityQueue(int cap)
		{
			capacity=cap;
			ary=new int[capacity];
			priority=new int[capacity];
			size=0;
		}
		
		~PriorityQueue()
		{
			delete[] ary;
			delete[] priority;
		}
		
		void enqueue(int val, int p)
		{
			if(size==capacity)
			{
				cout<<"\nQueue Overflow";
				return;
			}
			
			ary[size]=val;
			priority[size]=p;
			size++;
			
			cout<<"\n"<<value<<" with priority "<<p<<" enqueued\n";
		}
		
		void dequeue()
		{
			if(size==0)
			{
				cout<<"\nQueue Underflow! Queue is empty\n";
				return;
			}
			
			int highestpriority=0;
			
			for(int i=1; i<size; i++)
			{
				if(priority[i]>priority[highestpriority])
				{
					highestpriority=i;
				}
			}
			
			cout<<"\n"<<ary[highestpriority]<<" with priority "<<priority[highestpriority]<<" dequeued\n";
			
			for(int i=highestpriority; i<size-1; i++)
			{
				ary[i]=ary[i+1];
				priority[i]=priority[i+1];
			}
			
			size--;
		}
		
		void front()
		{
			if(size==0)
			{
				cout<<"\nQueue is empty! No front element\n";
				return;
			}
			
			int highestpriority=0;
			
			for(int i=1; i<size; i++)
			{
				if(priority[i]>priority[highestpriority])
				{
					highestpriority=i;
				}
			}
			
			cout<<"\nFront element: "<<ary[highestpriority]<<" with priority "<<priority[highestpriority]<<"\n";
		}
		
		bool isEmpty()
		{
			return size==0;
		}
		
		bool isFull()
		{
			return size==capacity;
		}
		
		void display()
		{
			if(size==0)
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nQueue elements (data, priority):\n";
			for(int i=0; i<size; i++)
			{
				cout<<"("<<ary[i]<<", "<<priority[i]<<")\t";
			}
			cout<<"\n";
		}
};

int main()
{
    int cap;
    cout<<"Enter queue capacity: ";
    cin>>cap;
    
    PriorityQueue pq(cap);
    
    int choice, value, prior;
    
    while(true)
	{
		cout<<"\n----- Priority Queue Operations -----\n";
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Front\n";
		cout<<"4. Check if Empty\n";
		cout<<"5. Check if Full\n";
		cout<<"6. Display Queue\n";
		cout<<"7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value: ";
				cin>>value;
				cout<<"Enter priority: ";
				cin>>prior;
				pq.enqueue(value, prior);
				break;
				
			case 2:
				pq.dequeue();
				break;
				
			case 3:
				pq.front();
				break;
				
			case 4:
				if(pq.isEmpty())
				{
					cout<<"\nQueue is Empty\n";
				}
				else
				{
					cout<<"\nQueue is Not Empty\n";
				}
				break;
				
			case 5:
				if(pq.isFull())
				{
					cout<<"\nQueue is Full\n";
				}
				else
				{
					cout<<"\nQueue is Not Full\n";
				}
				break;
				
			case 6:
				pq.display();
				break;
				
			case 7:
				cout<<"\nExiting...\n";
				return 0;
				
			default:
				cout<<"\nInvalid choice! Try again\n";
		}
	}
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#04***********----------------------------------------------------------------

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

class Queue
{
	private:
	    Node* front;
	    Node* rear;
	
	public:
	    Queue():front(NULL),rear(NULL){}
		
		void enqueue(int x)
		{
			Node* newnode=new Node(x);
			
			if(rear==NULL)
			{
				front=rear=newnode;
				return;
			}
			
			rear->next=newnode;
			rear=newnode;
		}
		
		int dequeue()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty\n";
				return -1;
			}
			
			Node* temp=front;
			int val=front->data;
			front=front->next;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete temp;
			return val;
		}
		
		bool isEmpty()
		{
			return front==NULL;
		}
		
		
		void display()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nQueue elements: ";
			
			Node* temp=front;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		int size()
		{
			int count=0;
			Node* temp=front;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
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
		
		bool isEmpty()
		{
			return top==NULL;
		}
};

void reverse(Queue& q, int k)
{
	if(k<=0 || k>q.size())
	{
		cout<<"\nInvalid value of k\n";
		return;
	}
	
	Stack s;
	
	for(int i=0; i<k; i++)
	{
		s.push(q.dequeue());
	}
	
	while(!s.isEmpty())
	{
		q.enqueue(s.pop());
	}
	
	int remaining=q.size()-k;
	for(int i=0; i<remaining; i++)
	{
		q.enqueue(q.dequeue());
	}
}

int main()
{
    Queue q;
    
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0; i<n; i++)
	{
		int val;
		cout<<"Element "<<i+1<<": ";
		cin>>val;
		q.enqueue(val);
	}
    
    cout<<"\nOriginal Queue:";
    q.display();
    
    int k;
    cout<<"\nEnter value of k: ";
    cin>>k;
    
    reverse(q, k);
    
    cout<<"\nAfter reversing first "<<k<<" elements:";
    q.display();
    
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

class Queue
{
	private:
	    Node* front;
	    Node* rear;
	
	public:
	    Queue():front(NULL),rear(NULL){}
		
		void enqueue(int x)
		{
			Node* newnode=new Node(x);
			
			if(rear==NULL)
			{
				front=rear=newnode;
				return;
			}
			
			rear->next=newnode;
			rear=newnode;
		}
		
		int dequeue()
		{
			if(front==NULL)
			{
				return -1;
			}
			
			Node* temp=front;
			int val=front->data;
			front=front->next;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete temp;
			return val;
		}
		
		int getFront()
		{
			if(front==NULL)
			{
				return -1;
			}
			return front->data;
		}
		
		bool isEmpty()
		{
			return front==NULL;
		}
		
		void display()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty\n";
				return;
			}
			
			cout<<"\nQueue elements: ";
			Node* temp=front;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		int size()
		{
			int count=0;
			Node* temp=front;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
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
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		bool ispalindrome(Queue& q)
		{
			if(q.isEmpty())
 			{
				return true;
			}
			
			Stack s;
			Queue tempq;
			int qsize=q.size();
			
			for(int i=0; i<qsize; i++)
			{
				int val=q.dequeue();
				s.push(val);
				tempq.enqueue(val);
				q.enqueue(val);
			}
			
			bool isPalin=true;
			
			while(!tempq.isEmpty())
			{
				if(tempq.dequeue()!=s.pop())
				{
					isPalin=false;
					break;
				}
			}
			
			return isPalin;
		}
};

int main()
{
    Queue q;
    Stack s;
    
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0; i<n; i++)
	{
		int val;
		cout<<"Element "<<i+1<<": ";
		cin>>val;
		q.enqueue(val);
	}
    
    cout<<"\nOriginal Queue:";
    q.display();
    
    if(s.ispalindrome(q))
	{
		cout<<"\nPalindrome\n";
	}
	else
	{
		cout<<"\nNot Palindrome\n";
	}
    
    cout<<"\nQueue after check:";
    q.display();
    
    return 0;
}
*/


