#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

const int INSERT=1;
const int DELETE=2;
const int SEARCH=3;
const int MINIMUM=4;
const int MAXIMUM=5;
const int INORDER=6;
const int PREORDER=7;
const int POSTORDER=8;
const int DISPLAY=9;
const int TREE_HEIGHT=10;
const int COUNT_NODES=11; 
const int NODE_HEIGHT=12; 
const int NODE_DEPTH=13; 
const int COUNT_NODES_AT_LEVEL=14;
const int FIND_PARENT=15; 
const int FIND_LEFT_CHILD=16;
const int FIND_RIGHT_CHILD=17;
const int BREADTH_FIRST_SEARCH=18;
const int EXIT=19;

class Node 
{
    public:
	    int data;
	    Node* left;
	    Node* right;
	    
	    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST 
{
	private:
	    Node* root;
	    
	    Node* insert(Node* root, int value)
	    {
	    	if(root==NULL)
	    	{
	    		return new Node(value);
			}
			
			if(value<root->data)
			{
				root->left=insert(root->left,value);
			}
			else if(value>root->data)
			{
				root->right=insert(root->right,value);
			}
			return root;
		}
	    
	    Node* deletenode(Node* root, int key)
	    {
	    	if(root==NULL)
	    	{
	    		return root;
			}
			
			if(key<root->data)
			{
				root->left=deletenode(root->left,key);
			}
			else if(key>root->data)
			{
				root->right=deletenode(root->right,key);
			}
			else if(key==root->data)
			{
				if(root->left==NULL)
				{
					Node* temp=root->right;
					delete root;
					return temp;
				}
				else if(root->right==NULL)
				{
					Node* temp=root->left;
					delete root;
					return temp;
				}
				else
				{
					Node* temp=findmin(root->right);
					root->data=temp->data;
					root->right=deletenode(root->right,temp->data);
				}
			}
			return root;
		}
	    
		Node* findmin(Node* root)
		{
			if(root==NULL)
			{
				return NULL;
			}
			
			while(root->left!=NULL)
			{
				root=root->left;
			}
			return root;
		}
		
		Node* findmax(Node* root)
		{
			if(root==NULL)
			{
				return NULL;
			}
			
			while(root->right!=NULL)
			{
				root=root->right;
			}
			return root;
		}
		
		bool search(Node* root, int key)
		{
			if(root==NULL)
			{
				return false;
			}
			
			if(key==root->data)
			{
				return true;
			}
			else if(key<root->data)
			{
				return search(root->left,key);
			}
			else
		    {
		        return search(root->right,key);
		    }
		}
		
		void preorder(Node* root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				cout<<root->data<<"\t";
				preorder(root->left);
				preorder(root->right);
			}
		}
		
		void inorder(Node* root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				inorder(root->left);
				cout<<root->data<<"\t";
				inorder(root->right);
			}
		}
		
		void postorder(Node* root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				postorder(root->left);
				postorder(root->right);
				cout<<root->data<<"\t";
			}
		}
		
	    void destroytree(Node* root)
	    {
	    	if(root==NULL)
	    	{
	    		return;
			}
			else
			{
				destroytree(root->left);
				destroytree(root->right);
				delete root;
			}
		}
		
		void display(Node* root, int spc)
		{
			const int plus=6;
			
			if(root==NULL)
			{
				return;
			}
			else
			{
				display(root->right,spc+plus);
				cout<<setw(spc)<<"\t"<<root->data<<"\n\n";
				display(root->left,spc+plus);
			}
		}
	    
	    int findheight(Node* root)
	    {
	    	if(root==NULL)
	    	{
	    		return 0;
			}
			else
			{
				int lh=findheight(root->left);
				int rh=findheight(root->right);
				return 1+((lh>rh)?lh:rh);
			}
		}
	    
	    int countnodes(Node* root)
	    {
	    	if(root==NULL)
	    	{
	    		return 0;
			}
			else
			{
				return 1+countnodes(root->left)+countnodes(root->right);
			}
		}
		
		Node* findnode(Node* root,int key)
		{
			if(root==NULL || root->data==key)
			{
				return root;
			}
			else if(key<root->data)
			{
				return findnode(root->left,key);
			}
			else
			{
				return findnode(root->right,key);
			}
		}
		
		int nodeheight(Node* node)
		{
			if(node==NULL)
			{
				return -1;
			}
			
			int lh=findheight(node->left);
			int rh=findheight(node->right);
			return 1+((lh>rh) ? lh:rh);
		}
		
		int nodedepth(Node* root,int key,int depth=0)
		{
			if(root==NULL)
			{
				return -1;
			}
			else if(root->data==key)
			{
				return depth;
			}
			else if(key<root->data)
			{
				return nodedepth(root->left,key,depth+1);
			}
			else
			{
				return nodedepth(root->right,key,depth+1);
			}
		}
	    
		int countnodesatlevel(Node* node,int level)
		{
			if(node==NULL)
			{
				return 0;
			}
			if(level==0)
			{
				return 1;
			}
			
			return countnodesatlevel(node->left,level-1)+countnodesatlevel(node->right,level-1);
		}
		
		Node* findparrent(Node* node,int val)
		{
			if(node==NULL || node->data==val)
			{
				return NULL;
			}
			
			if((node->left && node->left->data==val) || (node->right && node->right->data==val))
			{
				return node;
			}
			
			if(val<node->data)
			{
				return findparrent(node->left,val);
			}
			else
			{
				return findparrent(node->right,val);
			}
		}
	    
	public:
		BST():root(NULL){}
		
		~BST()
		{
			destroytree(root);
		}
		
		void insert(int val)
		{
			root=insert(root,val);
		}
		
		void deletevalue(int key)
		{
			root=deletenode(root,key);
		}
		
		bool search(int key)
		{
			return search(root,key);
		}
		
		int findmin()
		{
			Node* temp=findmin(root);
			return temp?temp->data:-1;
		}
		
		int findmax()
		{
			Node* temp=findmax(root);
			return temp?temp->data:-1;
		}
		
		void inordertraversal()
		{
			cout<<"Inorder\t";
			inorder(root);
			cout<<endl;
		}
		
		void preordertraversal()
		{
			cout<<"Preorder\t";
			preorder(root);
			cout<<endl;
		}
		
		void postordertraversal()
		{
			cout<<"Postorder\t";
			postorder(root);
			cout<<endl;
		}
		
		void display()
		{
			cout<<"\n\nTree structure is: root at most left, right at top, left at bottom\n\n";
			display(root,0);
		}
		
		int findheight()
		{
			return findheight(root);
		}
		
		int countnodes()
		{
			return countnodes(root);
		}
		
		int nodeheight(int val)
		{
			Node* node=findnode(root,val);
			
			if(node==NULL)
			{
				cout<<"\nno node in the tree\n\n";
				return -1;
			}
			else
			{
				return nodeheight(node);
			}
		}
		
		int nodedepth(int key)
		{
			return nodedepth(root,key);
		}
		
		int countnodesatlevel(int level)
		{
			return countnodesatlevel(root,level);
		}
		
		Node* findparrent(int val)
		{
			return findparrent(root,val);
		}
		
		int getleftchild(int val)
		{
			Node* node=findnode(root,val);
			
			if(node && node->left)
			{
				return node->left->data;
			}
			else
			{
				cout<<"\nLeft child not found\n\n";
				return -1;
			}
		}
		
		int getrightchild(int val)
		{
			Node* node=findnode(root,val);
			
			if(node && node->right)
			{
				return node->right->data;
			}
			else
			{
				cout<<"\nLeft child not found\n\n";
				return -1;
			}
		}
		
	    void breadthfirsttraversal()
	    {
	    	if(root==NULL)
	    	{
	    		cout<<"\ntree is empty\n\n";
			}
			
			queue<Node*> q;
	    	q.push(root);
	    	
		    cout << "BFS (Level Order): ";
		    
	    	while (!q.empty()) 
			{
	        	Node* current = q.front();
		        q.pop();
		        cout << current->data << " ";
		        
	    	    if (current->left) 
				{
					q.push(current->left);
				}
	        	if (current->right) 
				{
					q.push(current->right);
				}
	    	}
	    	cout<<endl;
		}		
};


int main() {
    BST tree;
    int choice, value, left_child, right_child;
    do {
        cout << "\n====== BST Operations Menu ======\n\n";
        cout<<"1    Insert\n";
        cout<<"2.   Delete\n";
        cout<<"3.   Search\n";
        cout<<"4.   Find Minimum\n";
        cout<<"5.   Find Maximum\n";
        cout<<"6.   Inorder Traversal\n";
        cout<<"7.   Preorder Traversal\n";
        cout<<"8.   Postorder Traversal\n";
        cout<<"9.   Display Tree Structure\n";
        cout<<"10.  Height Of Tree Structure\n";
        cout<<"11.  Count Nodes in  Tree Structure\n";
        cout<<"12.  Find Height of a Node\n";
        cout<<"13.  Find Depth of a Node\n";
        cout<<"14.  Count Nodes at a Given Level\n";
        cout<<"15.  Find Parent of a Node\n";
        cout<<"16.  Find Left Child of a Node\n";
        cout<<"17.  Find Right Child of a Node\n";
        cout<<"18.  Breadth First Search (Traversal) \n";
        cout<<"19.  Exit\n";
        
        cout<<"\nEnter your choice\t";
        cin>>choice;
        
        switch(choice)
		{
            case INSERT:
                cout<<"Enter value to insert:\t";
                cin>>value;
                tree.insert(value);
                break;
                
            case DELETE:
                cout<<"Enter value to delete\t";
                cin>>value;
                tree.deletevalue(value);
                break;
                
            case SEARCH:
                cout<<"Enter value to search\t";
                cin>>value;
                if(tree.search(value))
                {
                	cout<<"Value found\n";
				}
                    
                else
                {
                	cout<<"Value not found\n";
				} 
                break;
                
            case MINIMUM:
                value=tree.findmin();
                if(value!=-1)
                {
                	cout<<"\nMinimum value\t"<<value;
				}
                else
                {
                	cout << "Tree is empty.\n";
				}
                break;
                
            case MAXIMUM:
                value=tree.findmax();
                if(value!=-1)
                {
                	cout<<"\nMaximum value\t"<<value;
				}
                else
                {
                	cout<<"Tree is empty\n";
				} 
                break;
                
            case INORDER:
                tree.inordertraversal();
                break;
                
            case PREORDER:
                tree.preordertraversal();
                break;
                
            case POSTORDER:
                tree.postordertraversal();
                break;
                
            case DISPLAY:
                tree.display();
                break;
                
            case TREE_HEIGHT:
                cout<<"\nheight of the tree is\t"<<tree.findheight();
                break;
                
            case EXIT:
                cout<<"Exiting program\n";
                break;
                
            case COUNT_NODES:
                cout<<"\ntotal number of nodes in the tree\t"<<tree.countnodes();
                break;
                
            case NODE_HEIGHT:
                cout<<"Enter node value to find its height\t";
				cin>>value;
                cout<<"Height of node\t"<<value<<" is\t"<<tree.nodeheight(value);
                break;
                
            case NODE_DEPTH:
                cout<<"Enter node value to find depth\t";
				cin>>value;
                {
                    int depth=tree.nodedepth(value);
                    if(depth!=-1)
                    {
                    	cout<<"Depth of node\t"<<value<<"\t"<<depth;
					}
                    else
                    {
                    	cout<<"Node not found\n";
					}
                }
                break;
                
            case COUNT_NODES_AT_LEVEL:
                cout<<"Enter level to count nodes at\t";
				cin>>value;
                cout<<"Number of nodes at level\t"<<value<<"\t"<<tree.countnodesatlevel(value);
                break;
                
            case FIND_PARENT:
                cout<<"Enter value to find its parent\t";
				cin>>value;
                {
                    Node* parent=tree.findparrent(value);
	                if(parent)
	                {
	                	cout<<"Parent of\t"<<value<<" is\t"<<parent->data;
					}
	                else
	                {
	                	cout<<"No parent found (node may be root or not exist)\n";
					}
	                    
                }
                break;
                
            case FIND_LEFT_CHILD:
                cout<<"Enter node value to find its left child\t";
				cin>>value;
                left_child=tree.getleftchild(value);
                if(left_child!=-1) 
				{
					cout<<"\n left child = "<<left_child;
				}
            break;
            
            case FIND_RIGHT_CHILD:
                cout<<"Enter node value to find its right child:\t";    
				cin>>value;
                right_child=tree.getrightchild(value);
                if(right_child!=-1) 
				{
					cout<<"\n right child = "<<right_child;
				}
                break;
                
//            case BREADTH_FIRST_SEARCH:
//                tree.breadthfirsttraversal();
//                break;
                
            default:
                cout<<"Invalid choice\n\n";
        }
        if (choice != EXIT)
		{
			cout<<"\n press any key to continue"; 
			_getch(); 
			system("cls");
		}
    } while (choice != EXIT);

    return 0;
}
