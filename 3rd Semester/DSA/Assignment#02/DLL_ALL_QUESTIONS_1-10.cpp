//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
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
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		void sortedinsertion()
		{
			cout<<"\nEnter value to insert in sorted position\t";
			int val;
			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
				return;
			}
			
			if(val<=head->data)
			{
				newnode->next=head;
				head->prev=newnode;
				head=newnode;
				return;
			}
			
			if(val>=tail->data)
			{
				tail->next=newnode;
				newnode->prev=tail;
				tail=newnode;
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL && temp->data<val)
			{
				temp=temp->next;
			}
			
			newnode->next=temp;
			newnode->prev=temp->prev;
			temp->prev->next=newnode;
			temp->prev=newnode;
		}
};

int main()
{
    DLL list;
    
    cout<<"Create a sorted doubly linked list\n";
//    cout<<"Enter values in sorted order\n";
    
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    
    cout<<"\nOriginal Sorted List\n";
    list.display();
    
    list.sortedinsertion();
    
    cout<<"\nList after insertion\n";
    list.display();
    
    
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
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		void deleteoccurences()
		{
			cout<<"\nEnter val to delete all occurences: ";
			int val;
			cin>>val;
			
			if(head==NULL)
			{
				cout<<"\nList is empty!\n";
				return;
			}
			
			Node* temp=head;
			int count=0;
			
			while(temp!=NULL)
			{
				if(temp->data==val)
				{
					Node* todel=temp;
					
					if(temp==head)
					{
						head=head->next;
						
						if(head!=NULL)
						{
							head->prev=NULL;
						}
						else
						{
							tail=NULL;
						}
						
						temp=head;
					}
					else if(temp==tail)
					{
						tail=tail->prev;
						tail->next=NULL;
						temp=NULL;
					}
					else
					{
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
						temp=temp->next;
					}
					
					delete todel;
					count++;
				}
				else
				{
					temp=temp->next;
				}
			}
			
			if(count==0)
			{
				cout<<"\nval not found\n";
			}
			else
			{
				cout<<"\nAll "<<count<<" occurences deleted\n";
			}
		}
};

int main()
{
    DLL list;
    
    cout<<"Our list is\n";
    
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(3);
    
    cout<<"\noriginal list is\n";
    list.display();
    
    list.deleteoccurences();
    
    cout<<"\nList after deleting\n";
    list.display();
    
    
    return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#03***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		void sum()
		{
			cout<<"\nEnter the val for sum\t";
			int sum;
			cin>>sum;
			
			if(head==NULL || head->next==NULL)
			{
				cout<<"\nlist empty or only 1 node\n";
				return;
			}
			
			Node* left=head;
			Node* right=tail;
			
			int count=0;
			
			cout<<"\nPairs of a given number are\n";
			
			while(left!=right && left->prev!=right)
			{
				int currsum=left->data+right->data;
				
				if(currsum==sum)
				{
					cout<<"("<<left->data<<", "<<right->data<<")"<<endl;
					count++;
					
					left=left->next;
					right=right->prev;
				}
				else if(currsum<sum)
				{
					left=left->next;
				}
				else
				{
					right=right->prev;
				}
			}
			
			if(count==0)
			{
				cout<<"No pairs found with sum "<<sum<<"\n";
			}
			else
			{
				cout<<"\nTotal pairs found: "<<count<<"\n";
			}
		}
};

int main()
{
    DLL list;
    
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
    list.insertionattheend(6);
    list.insertionattheend(7);
    list.insertionattheend(8);
    list.insertionattheend(9);
    
    cout<<"Sorted Doubly Linked List: ";
    list.display();
    
    list.sum();
    
    
    
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
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		
		int getlength()
 		{
			int count=0;
			Node* temp=head;
			
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			
			return count;
		}
		
		void rotate()
		{
			cout<<"\nEnter how many nodes to be shifted/rotated\t";
			int n;
			cin>>n;
			
			if(head==NULL || head->next==NULL)
			{
				cout<<"\nList is empty or only 1 node\n";
				return;
			}
			
			int length=getlength();
			
			n=n%length;
			
			if(n==0)
			{
				cout<<"\nn%length becomes zero\n";
				return;
			}
			
			if(n<0)
			{
				n=length+n;
			}
			
			Node* temp=head;
			int count=1;
			
			while(count<n && temp!=NULL)
			{
				temp=temp->next;
				count++;
			}
			
			if(temp==NULL || temp->next==NULL)
			{
				return;
			}
			
			Node* newhead=temp->next;
			
			tail->next=head;
			head->prev=tail;
			
			temp->next=NULL;
			newhead->prev=NULL;
			
			head=newhead;
			tail=temp;
		}
};

int main()
{
    DLL list;
    
    list.insertionattheend(1);
    list.insertionattheend(2);
    list.insertionattheend(3);
    list.insertionattheend(4);
    list.insertionattheend(5);
    
    cout<<"Original List\n";
    list.display();
    
    list.rotate();
    
    cout<<"\nList after rotation\n";
    list.display();
    
    
    
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
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		
		Node* gethead()
		{
			return head;
		}
		
		void sethead(Node* newhead)
		{
			head=newhead;
		}
		
		void updatetail()
		{
			if(head==NULL)
			{
				tail=NULL;
				return;
			}
			
			tail=head;
			
			while(tail->next!=NULL)
			{
				tail=tail->next;
			}
		}
		
		void merging(DLL &L2)
		{
			Node* h1=head;
			Node* h2=L2.gethead();
			
			if(h1==NULL)
			{
				head=h2;
				updatetail();
				
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
				newhead=h1;
				h1=h1->next;
			}
			else
			{
				newhead=h2;
				h2=h2->next;
			}
			
			newtail=newhead;
			newhead->prev=NULL;
			
			while(h1!=NULL && h2!=NULL)
			{
				if(h1->data<=h2->data)
				{
					newtail->next=h1;
					h1->prev=newtail;
					newtail=h1;
					h1=h1->next;
				}
				else
				{
					newtail->next=h2;
					h2->prev=newtail;
					newtail=h2;
					h2=h2->next;
				}
			}
			
			if(h1!=NULL)
			{
				newtail->next=h1;
				h1->prev=newtail;
			}
			
			if(h2!=NULL)
			{
				newtail->next=h2;
				h2->prev=newtail;
			}
			
			head=newhead;
			updatetail();
		}
};

int main()
{
    DLL list1;
    DLL list2;
    
    list1.insertionattheend(2);
    list1.insertionattheend(4);
    list1.insertionattheend(8);
    
    cout<<"List 1\n";
    list1.display();
    
    
    list2.insertionattheend(1);
    list2.insertionattheend(3);
    list2.insertionattheend(5);
    
    cout<<"\nList 2\n";
    list2.display();
    
    list1.merging(list2);
    
    cout<<"\nMerged List is\n";
    list1.display();
    
    
    
    return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class TreeNode
{
	public:
	    int data;
	    TreeNode* left;
	    TreeNode* right;
	
	    TreeNode(int d):data(d),left(NULL),right(NULL){}
};

class Node
{
	public:
	    int data;
	    Node* next;
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n\n";
		}
		
		void inorderhelper(TreeNode* root)
		{
			if(root==NULL)
			{
				return;
			}
			
			inorderhelper(root->left);
			insertionattheend(root->data);
			inorderhelper(root->right);
		}
		
		void convert(TreeNode* root)
		{
			if(root==NULL)
			{
				cout<<"\ntree is empty\n";
				return;
			}
			
			inorderhelper(root);
		}
		
		void displaytree(TreeNode* root, int space=0, int indent=4)
		{
			if(root==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(root->right, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<root->data<<"\n";
			
			displaytree(root->left, space);
		}
};


int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(20);
    
    DLL l1;
    cout<<"This is tree\n";
    l1.displaytree(root);
    
    l1.convert(root);
    
    cout<<"\nAfter converting to DLL\n";
    l1.display();
    
    
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
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    DLL():head(NULL),tail(NULL){}
		
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n";
		}
		
		void findtriplets()
		{
			int n;
			cout<<"enter sum to find its triplets\t";
			cin>>n;
			
			if(head==NULL || head->next==NULL || head->next->next==NULL)
			{
				cout<<"\n0,1, or 2 nodes\n";
				return;
			}
			
			bool found=false;
			
			Node* first=head;
			
			while(first!=NULL)
			{
				Node* second=first->next;
				Node* third=tail;
				
				while(second!=NULL && third!=NULL && second!=third && third->next!=second)
				{
					int sum=first->data + second->data + third->data;
					
					if(sum==n)
					{
						cout<<"("<<first->data<<", "<<second->data<<", "<<third->data<<")\n";
						found=true;
						second=second->next;
						third=third->prev;
					}
					else if(sum<n)
					{
						second=second->next;
					}
					else
					{
						third=third->prev;
					}
				}
				first=first->next;
			}
			
			if(found==false)
			{
				cout<<"\nNo triplets found\n";
			}
		}
};

int main()
{
	DLL list;
	
	list.insertionattheend(1);
	list.insertionattheend(2);
	list.insertionattheend(3);
	list.insertionattheend(4);
	list.insertionattheend(5);
	list.insertionattheend(6);
	list.insertionattheend(7);
	list.insertionattheend(8);
	list.insertionattheend(9);
	list.insertionattheend(10);
	
	cout<<"\nList is\n";
	list.display();
	
	cout<<"\nTriplets of the sum are\n\n";
	list.findtriplets();
	
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
        Node* prev;
        
        Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
		Node* head;
        Node* tail;
        
    public:
        DLL():head(NULL),tail(NULL){}
        
        void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n";
		}
        
        
        DLL merging(DLL lists[], int K)
        {
            DLL result;
            
            Node* heap[50];
            int size=0;
            
            for(int i=0;i<K;i++)
            {
                if(lists[i].head!=NULL)
                {
                	heap[size++]=lists[i].head;
				}
                    
            }

            while(size>0)
            {
                int minIndex=0;
                
                for(int i=1; i<size; i++)
                {
                    if(heap[i]->data<heap[minIndex]->data)
                    {
                    	minIndex=i;
					}   
                }
                
                result.insertionattheend(heap[minIndex]->data);
                
                heap[minIndex]=heap[minIndex]->next;
                
                if(heap[minIndex]==NULL)
                {
                    for(int i=minIndex;i<size-1;i++)
                    {
                    	heap[i]=heap[i+1];
					}
                    size--;
                }
            }
            
            return result;
        }
};


int main()
{
    DLL L1, L2, L3;
    
    L1.insertionattheend(1);
    L1.insertionattheend(2);
    L1.insertionattheend(3);
    
    cout<<"list 1\n";
    L1.display();
    
    L2.insertionattheend(4);
    L2.insertionattheend(5);
    L2.insertionattheend(6);
    
    cout<<"\nList 2\n";
    L2.display();
    
    L3.insertionattheend(7);
    L3.insertionattheend(8);
    L3.insertionattheend(9);
    
    cout<<"\nList 3\n";
    L2.display();
    
    DLL lists[3]={L1,L2,L3};
    
    DLL finalList;
    finalList=finalList.merging(lists,3);
    
    
    cout<<"\nAfter merging lists\n\n";
    finalList.display();
	
	
	
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#09***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
 {
	public:
	    int data;
	    Node* next;
	    Node* prev;
	    
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class DLL
{
	private:
	    Node* head;
	    Node* tail;
	    
	public:
	    DLL():head(NULL),tail(NULL){}
	
	    void insertionattheend(int val)
		{
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
				tail=newnode;
			}
		}
	
	    Node* reversehelper(Node* head,int k)
	    {
	    	Node* prevnode=NULL;
	        Node* current=head;
	        Node* nextnode=NULL;
	        
	        int count = 0;
	
	        while(current!=NULL && count<k)
	        {
	            nextnode=current->next;
	            current->next=prevnode;
	            
	            if(prevnode!=NULL)
	            {
	            	prevnode->prev=current;
				}
	                
	            prevnode=current;
	            current=nextnode;
	            count++;
	        }
	
	        if(nextnode!=NULL)
	        {
	            head->next=reversehelper(nextnode,k);
	            
	            if(head->next!=NULL)
	            {
	            	head->next->prev=head;
				}
	        }
	
	        prevnode->prev=NULL;
	        
	        return prevnode;
	    }
	
	    void reverse()
	    {
	    	int k;
		    cout<<"Enter how many rotations you want\t";
		    cin>>k;
		    
	        head=reversehelper(head,k);
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
				cout<<temp->data;
				if(temp->next!=NULL)
				{
					cout<<" <--> ";
				}
				temp=temp->next;
			}
			cout<<"\n";
		}
};

int main()
{
    DLL list;
    
    list.insertionattheend(1);
	list.insertionattheend(2);
	list.insertionattheend(3);
	list.insertionattheend(4);
	list.insertionattheend(5);
	list.insertionattheend(6);
	list.insertionattheend(7);
	list.insertionattheend(8);
	list.insertionattheend(9);
	list.insertionattheend(10);
	
    cout<<"Original List\n";
    list.display();
    
    list.reverse();
    
    cout<<"List after reversing\n";
    list.display();
    
    return 0;
}
//*/




//-------------------------------------------------------------**********QUESTION#10***********----------------------------------------------------------------

/*
#include <iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* next;
	    Node* prev;
	
	    Node(int d):data(d),next(NULL),prev(NULL){}
};

class CDLL
{
	private:
	    Node* head;
	    Node* tail;
	
	public:
	    CDLL():head(NULL),tail(NULL){}
	
	    void insertionattheend(int val)
	    {
	        Node* newnode=new Node(val);
	        
	        if(head==NULL)
	        {
	            head=newnode;
	            head->next=head;
	            head->prev=head;
	            
	            return;
	        }
	        
	        tail=head->prev;
	        tail->next=newnode;
	        newnode->prev=tail;
	        newnode->next=head;
	        head->prev=newnode;
	    }
	
	    void display()
	    {
	        if(head==NULL)
	        {
	            cout<<"List is empty\n";
	            return;
	        }
	        
	        Node* temp=head;
	        
	        do
	        {
	            cout<<temp->data<<" <--> ";
	            temp=temp->next;
	            
	        }while(temp!=head);
	        
	        cout<<"\n";
	    }
	
	    void split(CDLL &fh,CDLL &sh)
	    {
	        if(head==NULL)
	        {
	            return;
	        }
	
	        Node* slow=head;
	        Node* fast=head;
	        
	        while(fast->next!=head && fast->next->next!=head)
	        {
	            slow=slow->next;
	            fast=fast->next->next;
	        }
	
	        Node* h1=head;
	        Node* h2=slow->next;
	        tail=head->prev;
	        
	        slow->next=h1;
	        h1->prev=slow;
	
	        tail->next=h2;
	        h2->prev=tail;
	
	        fh.head=h1;
	        sh.head=h2;
	    }
};

int main()
{
	CDLL list;
	
    list.insertionattheend(1);
	list.insertionattheend(2);
	list.insertionattheend(3);
	list.insertionattheend(4);
	list.insertionattheend(5);
	list.insertionattheend(6);
	list.insertionattheend(7);
	list.insertionattheend(8);
	list.insertionattheend(9);
	list.insertionattheend(10);

    cout<<"Original List:\n";
    list.display();

    CDLL fh;
    CDLL sh;

    list.split(fh,sh);

    cout<<"First half\n";
    fh.display();

    cout<<"Second half\n";
    sh.display();

    return 0;
}
//*/

