#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
			
		Node(int v):data(v),next(NULL),prev(NULL){}
};

class DLL
{
	private:
		Node* head;
		Node* tail;
		
	public:
		DLL():head(NULL),tail(NULL){}
		
		void insertionattheend()
		{
			cout<<"\nEnter value for insertion\t";
			int val;
			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				newnode->prev=tail;
				tail->next=newnode;
				tail=newnode;
			}
		}
		
		void insertionatthebeginning()
		{
			cout<<"\nEnter value for insertion\t";
			int val;
			cin>>val;
			
			Node* newnode=new Node(val);
			
			if(head==NULL)
			{
				head=tail=newnode;
			}
			else
			{
				newnode->next=head;
				head->prev=newnode;
				head=newnode;
			}
		}
		
		void insertaftervalue()
	    {
	        if(head==NULL)
	        {
	            cout<<"List is empty\n";
	            return;
	        }
	
	        Node* temp=head;
	        
	        cout<<"\nEnter value after which you want to insert\t";
	        int target;
	        cin>>target;
	        
	        while(temp!=NULL && temp->data!=target)
	        {
	            temp=temp->next;
	        }
	
	        if(temp==NULL)
	        {
	            cout<<"Value not found\n";
	            return;
	        }
	        
	        cout<<"\nEnter new value to insert\t";
	        int val;
	        cin>>val;
	        
	        Node* newnode=new Node(val);
	        newnode->next=temp->next;
	        newnode->prev=temp;
	        
	        if(temp->next!=NULL)
	        {
	        	temp->next->prev=newnode;
			}
	        
	        temp->next=newnode;
	
	        if(temp==tail)
			{
				tail=newnode;
			}
	        
	        cout<<"Value inserted\n\n";
	    }
		
		void deletebyvalue()
		{
			if(head==NULL)
			{
				cout<<"List is empty\n\n";
				return;
			}
			
			cout<<"Enter value to delete\t";
			int val;
			cin>>val;
			
			if(head->data==val)
			{
				Node* temp=head;
				head=head->next;
				
				if(head!=NULL)
					head->prev=NULL;
				else
					tail=NULL;
				
				delete temp;
				return;
			}
			
			Node* temp=head;
			
			while(temp!=NULL && temp->data!=val)
			{
				temp=temp->next;
			}
			
			if(temp==NULL)
			{
				cout<<"Value not found\n\n";
				return;
			}
			
			if(temp->prev!=NULL)
			{
				temp->prev->next=temp->next;
			}
			
			if(temp->next!=NULL)
			{
				temp->next->prev=temp->prev;
			} 
			
			if(temp==tail)
			{
				tail=temp->prev;
			}
			
			delete temp;
		}
	    
	    bool searchbyvalue()
	    {
	    	if(head==NULL)
	    	{
	    		cout<<"List is empty\n\n";
	    		return false;
			}
			
			cout<<"Enter value to search\t";
			int val;
			cin>>val;
			
			Node* temp=head;
			
			while(temp!=NULL)
			{
				if(temp->data==val)
				{
					cout<<"\nValue found\n";
					cout<<temp->data;
					
					return true;
				}
				temp=temp->next;
			}
			
			cout<<"Value not found\n";
			return false;
		}
		
		void update()
		{
			cout<<"\nEnter value you want to update\t";
			int val;
			cin>>val;
			
			cout<<"\nEnter new value\t";
			int newval;
			cin>>newval;
			
			Node* temp=head;
			while(temp!=NULL)
			{
				if(temp->data==val)
				{
					temp->data=newval;
					cout<<"\nValue updated\n";
					return;
				}
				
				temp=temp->next;
			}
			cout<<"\nValue not found\n\n";
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
		
		void displayReverse()
		{
			if(tail==NULL)
			{
				cout<<"\nList is empty\n";
				return;
			}
			
			Node* temp=tail;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->prev;
			}
			cout<<"\n\n";
		}
};

int main()
{
	DLL s;
	int choice;
	
	do
	{
		cout<<"\n\nCHOOSE THE FOLLOWING OPERATIONS FOR THE DOUBLY LINKED LIST\n\n";
		
		cout<<"1.	Insertion at the end\n";
		cout<<"2.	Insertion at the beginning\n";
		cout<<"3.	Insertion after value\n";
		cout<<"4.	Delete by value\n";
		cout<<"5.	Search by value\n";
		cout<<"6.	Update value\n";
		cout<<"7. 	Display list (Forward)\n";
		cout<<"8. 	Display list (Backward)\n";
		cout<<"9. 	exit\n\n";
		
		cout<<"Enter your choice\t";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				s.insertionattheend();
				break;
			}
			case 2:
			{
				s.insertionatthebeginning();
				break;
			}
			case 3:
			{
				s.insertaftervalue();
				break;
			}
			case 4:
			{
				s.deletebyvalue();
				break;
			}
			case 5:
			{
				s.searchbyvalue();
				break;
			}
			case 6:
			{
				s.update();
				break;
			}
			case 7:
			{
				s.display();
				break;
			}
			case 8:
			{
				s.displayReverse();
				break;
			}
			case 9:
				cout<<"\nExiting program...\n";
				break;
				
			default:
				cout<<"\nInvalid choice, try again!\n\n";
		}
		
	}while(choice!=9);
	
	return 0;
}