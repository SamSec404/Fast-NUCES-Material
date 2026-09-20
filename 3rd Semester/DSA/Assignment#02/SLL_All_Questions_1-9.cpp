//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
			
		Node(int v):data(v),next(NULL){}
};

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
	
	    void insertionattheend(int val)
 		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
//		void reverselist()
//		{
//			if(head==NULL || head->next==NULL)
//			{
//				return;
//			}
//			
//			Node* temphead=head;
//			Node* temptail=tail;
//			
//			while(head->data!=tail->data || tail->next->data!=head->data)
//			{
//				Node* swap=head;
//				head=tail;
//				tail=swap;
//			}
//		}
		
		
	    void reverseList()
		{
		    if(head==NULL || head->next==NULL)
		    {
		    	return;
			}
			
		    Node* prev=NULL;
		    Node* current=head;
		    Node* nextnode=NULL;
			
		    tail=head;
			
		    while(current!=NULL) 
		    {
		        nextnode=current->next;
		        current->next=prev;
		        prev=current;
		        current=nextnode;
		    }
			
		    head=prev;
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
};

int main()
{
    SSL s;
    
    cout<<"Enter values\n";
    
    s.insertionattheend(3);
    s.insertionattheend(4);
    s.insertionattheend(2);
    s.insertionattheend(5);
    s.insertionattheend(6);
    
    cout<<"\n\nLinked list before\n";
    s.display();
    
    s.reverseList();
    
    cout<<"\nAfter\n";
    s.display();
    
    
    
    return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#02***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
			
		Node(int v):data(v),next(NULL){}
};

class SSL
{
	private:
		Node* head;
		Node* tail;
		
	public:
		SSL():head(NULL),tail(NULL){}
		
		void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			//int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
	    void merge(SSL &L2)
		{
		    Node* h1=head;
		    Node* h2=L2.head; 
		    
		    if(h1==NULL)
		    {
		        head=h2;
		        tail=L2.tail;
		        return;
		    }
		    
		    if(h2==NULL)
		    {
		        return;
		    }
		
		    Node* newhead=NULL;
		    Node* newtail=NULL;
		    
		    if(h1->data<=h2->data)
		    {
		        newhead=newtail=h1;
		        h1=h1->next;
		    }
		    else
		    {
		        newhead=newtail=h2;
		        h2=h2->next;
		    }
		    
		    while(h1!=NULL && h2!=NULL)
		    {
		        if(h1->data<=h2->data)
		        {
		            newtail->next=h1;
		            newtail=h1;
		            h1=h1->next;
		        }
		        else
		        {
		            newtail->next=h2;
		            newtail=h2;
		            h2=h2->next;
		        }
		    }
		    
		    if(h1!=NULL)
			{
				newtail->next=h1;
			}
			
		    if(h2!=NULL)
			{
				newtail->next=h2;
			}
			
		    while(newtail->next!=NULL)
		    {
		        newtail=newtail->next;
		    }
		
		    head=newhead;
		    tail=newtail;
		}

};

int main()
{
    SSL l1;
	SSL l2;
	
    cout<<"Insert values write sorted only\n";
    l1.insertionattheend(1);
    l1.insertionattheend(3);
    l1.insertionattheend(5);
    
    cout<<"Insert values for 2nd list sorted only\n";
    l2.insertionattheend(2);
    l2.insertionattheend(4);
    l2.insertionattheend(6);
    
    cout<<"\nList1:\t";
    l1.display();
    
    cout<<"List2:\t";
    l2.display();
    
    l1.merge(l2);
    
    cout<<"List after merging\n";
    l1.display();
    
    
    return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

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

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
	    void findmiddle()
	    {
	        if(head==NULL)
	        {
	            cout<<"No node\n";
	            return;
	        }
	
	        Node* slow=head;
	        Node* fast=head;
	
	        while(fast!=NULL && fast->next!=NULL)
	        {
	            slow=slow->next;
	            fast=fast->next->next;
	        }
			
	        cout<<"\nMiddle node is\t"<<slow->data;
	    }
};

int main()
{
    SSL list;
    
    cout<<"Insert values\n";
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
	list.insertionattheend(6);
	
    cout<<"Inserrted list\n";
    list.display();

    list.findmiddle();

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

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
	    void deleteatend()
	    {
	        Node* fast=head;
	        Node* slow=head;
	        
	        int n;
	        cout<<"Enter which last node you want to delete\t";
    		cin>>n;

	        for(int i=0; i<n; i++)
	        {
	            if(fast==NULL) 
				{
					return;
				}
	            fast=fast->next;
	        }
	        
	        if(fast==NULL)
	        {
	            Node* del=head;
	            head=head->next;
	            delete del;
	            return;
	        }
	        
	        while(fast->next!=NULL)
	        {
	            fast=fast->next;
	            slow=slow->next;
	        }
	        
	        Node* del=slow->next;
	        slow->next=slow->next->next;
			
	        if(slow->next==NULL)
	        {
	        	tail=slow;
			}
	
	        delete del;
	    }
};

int main()
{
    SSL list;
    
    cout<<"Insert values\n";
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);

    cout<<"this is the list before any deletion\n";
    list.display();

    list.deleteatend();
    
    cout<<"Inserrted list after deletion\n";
    list.display();
    
    return 0;
}
*/



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
class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
	    void createcycle(int pos) 
	    {
	        if(pos<0)
			{
				return;
			}
	
	        Node* temp=head;
	        Node* cyclenode=NULL;
	        int count=0;
	
	        while(temp!=NULL)
	        {
	            if(count==pos)
				{
					cyclenode=temp;
				}
				
	            if(temp->next==NULL)
				{
					break;
				}
	            temp=temp->next;
	            count++;
	        }
	
	        if(cyclenode!=NULL && temp!=NULL)
	        {
	            temp->next=cyclenode;
	            cout<<"Cycle created at node index\t"<<pos<<"\n";
	        }
	    }
	    
	    bool hascycle()
	    {
	        Node *slow=head;
	        Node *fast=head;
	
	        while(fast!=NULL && fast->next!=NULL)
	        {
	            slow=slow->next;
	            fast=fast->next->next;
	
	            if(slow==fast)
	            {
	                return true;
	            }
	        }
	
	        return false;
	    }
};
int main()
{
    SSL list;
    
    cout<<"Insert 4 values\n";
    
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
    list.insertionattheend(6);
    
    list.display();
    
    cout<<"For creating cyclle press 1\t";
    int choice;
    cin>>choice;
    
    if(choice==1)
    {
        cout<<"Enter at which position you want to connect tail\t";
        int pos;
        cin>>pos;
        
        list.createcycle(pos);
    }
    if(list.hascycle())
    {
    	cout<<"Cycle detected\n";
	}
    else
    {
    	cout<<"Cycle not detected\n";
	}
	
	
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

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

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend()
		{
			cout<<"Enter value for insertion\t";
			int val;
			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
		void insertionattheend(int val)//for result
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		Node* gethead()
		{
			return head;
		}
		
		SSL addition(SSL& L1, SSL& L2)
		{
			SSL result;
			
			Node* h1=L1.gethead();
			Node* h2=L2.gethead();
			
			int carry=0;
			
			while(h1!=NULL || h2!=NULL || carry!=0)
			{
				int sum=carry;
				
				if(h1!=NULL)
				{
					sum+=h1->data;
					h1=h1->next;
				}
				
				if(h2!=NULL)
				{
					sum+=h2->data;
					h2=h2->next;
				}
				
				carry=sum/10;
				
				int digit=sum%10;
				
				result.insertionattheend(digit);
			}
			
			return result;
		}
};
int main()
{
    SSL L1, L2;
    
    cout<<"Enter 3 values for list 1\n\n";
    
    L1.insertionattheend(1);
    L1.insertionattheend(2);
    L1.insertionattheend(3);
    
    cout<<"\nL1\n";
    L1.display();
    
    cout<<"Enter 3 values for List 2\n\n";
    
    L2.insertionattheend(4);
    L2.insertionattheend(5);
    L2.insertionattheend(6);
    
    cout<<"\nL2\n";
    L2.display();
    
    SSL result;
    
    result=result.addition(L1, L2);
    
    cout<<"Result\n\n";
    result.display();
    
    
    return 0;
}
*/



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
class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		Node* findmiddle()
		{
			Node* slow=head;
			Node* fast=head;
			
			while(fast!=NULL && fast->next!=NULL)
			{
				slow=slow->next;
				fast=fast->next->next;
			}
			
			return slow;
		}
		
		
		Node* reverse(Node* head)
		{
			Node* prev=NULL;
			Node* curr=head;
			Node* next=NULL;
			
			while(curr!=NULL)
			{
				next=curr->next;
				curr->next=prev;
				prev=curr;
				curr=next;
			}
			
			return prev;
		}
		
		void reorderlist()
		{
			if(head==NULL || head->next==NULL)
			{
				return;
			}
			
			Node* mid=findmiddle();
			
			Node* secondhalf=reverse(mid);
			
			Node* firsthalf=head;
			
			while(secondhalf->next!=NULL)
			{
				Node* temp1=firsthalf->next;
				Node* temp2=secondhalf->next;
				
				firsthalf->next=secondhalf;
				secondhalf->next=temp1;
				
				firsthalf=temp1;
				secondhalf=temp2;
			}
		}
};
int main()
{
    SSL list;
    
    cout<<"Enter 5 values:\n";
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
    
    cout<<"\n\nOriginal List: ";
    list.display();
    
    list.reorderlist();
    
    cout<<"Reordered List: ";
    list.display();
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#08***********----------------------------------------------------------------

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

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		void removeduplicates()
		{
			if(head==NULL)
			{
				return;
			}
			
			Node* current=head;
			
			while(current!=NULL && current->next!=NULL)
			{
				if(current->data==current->next->data)
				{
					Node* duplicate=current->next;
					current->next=current->next->next;
					delete duplicate;
				}
				else
				{
					current=current->next;
				}
			}
		}
};
int main()
{
    SSL list;
    
    cout<<"Enter values in sorted order only\n";
    list.insertionattheend(1);
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(3);
    
    cout<<"Original List: ";
    list.display();
    
    list.removeduplicates();
    
    cout<<"After Removing Duplicates: ";
    list.display();
    
    return 0;
}
*/



//-------------------------------------------------------------**********QUESTION#09***********----------------------------------------------------------------

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

class SSL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    SSL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
//			cout<<"\nEnter value for insertion\t";
//			int val;
//			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
		
	    void display()
		{
			if(head==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		Node* reversehelper(Node* curr, int k)
		{
			if(curr==NULL || k<=1)
			{
				return curr;
			}
			
			Node* temp=curr;
			int count=0;
			
			while(temp!=NULL && count<k)
			{
				temp=temp->next;
				count++;
			}
			
			if(count<k)
			{
				return curr;
			}
			
			
			Node* prev=NULL;
			Node* current=curr;
			Node* next=NULL;
			count=0;
			
			while(current!=NULL && count<k)
			{
				next=current->next;
				current->next=prev;
				prev=current;
				current=next;
				count++;
			}
			
			if(next!=NULL)
			{
				curr->next=reversehelper(next, k);
			}
			
			return prev;
		}
		
		void reverse()
		{
			cout<<"\nEnter the value of k\t";
			int k;
			cin>>k;
			
			if(k<=1)
			{
				cout<<"\nEnter value >1 next time\n";
				return;
			}
			
			head=reversehelper(head, k);
			
			tail=head;
			
			if(tail!=NULL)
			{
				while(tail->next!=NULL)
				{
					tail=tail->next;
				}
			}
		}
};

int main()
{
    SSL list;
    
    cout<<"Enter 5 values:\n";
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
    list.insertionattheend(9);
    list.insertionattheend(8);
    
    cout<<"\nOriginal List: ";
    list.display();
    
    list.reverse();
    
    cout<<"\nList after reversing in k groups: ";
    list.display();
    
    return 0;
}
//*/