#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* left;
	    Node* right;
	
	    Node(int d):data(d),left(NULL),right(NULL){}
};

class BST
{
	private:
	    Node* root;
	
	    Node *insertion(Node* root, int val)
		{
			if(root==NULL)
			{
				return new Node(val);
			}
			
			if(val<root->data)
			{
				root->left=insertion(root->left,val);
			}
			else
			{
				root->right=insertion(root->right,val);
			}
			return root;
		}
		
		bool searchnode(Node* root, int key)
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
				return searchnode(root->left,key);
			}
			else
			{
				return searchnode(root->right,key);
			}
		}
	
	    Node* findmin(Node* root)
	    {
	    	if(root==NULL)
	    	{
	    		cout<<"Not exist\n";
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
				cout<<"Not found\n";
			}
			
			while(root->right!=NULL)
			{
				root=root->right;
			}
			return root;
		}
	
	    Node* deletenode(Node* root,int key)
	    {
	    	if(root==NULL)
	    	{
	    		cout<<"Tree is empty\n";
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
		
		Node* findnode(Node* node,int key)
		{
			if(node==NULL)
			{
				cout<<"not found\n";
				return NULL;
			}
			else if(node->data==key)
			{
				return node;
			}
			else if(key<node->data)
			{
				return findnode(node->left,key);
			}
			else if(key>node->data)
			{
				return findnode(node->right,key);
			}
			
		}
		
		Node* findparrent(Node* par,int val)
		{
			if(par==NULL)
			{
				cout<<"Not found";
				return par;
			}
			else if(par->data==val)
			{
				cout<<"Node is at root";
				return NULL;
			}
			else if((par->left!=NULL && par->left->data==val) || (par->right!=NULL && par->right->data==val))
			{
				return par;
			}
			else if(val<par->data)
			{
				return findparrent(par->left,val);
			}
			else if(val>par->data)
			{
				return findparrent(par->right,val);
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
		
		void updatevalue(int oldval, int newval)
		{
			if(searchnode(root,oldval))
			{
				root=deletenode(root,oldval);
				root=insertion(root,newval);
				cout<<"Updated\t"<<oldval<<"\t";
			}
			else
			{
				cout<<"Val not found\n";
			}
		}
		
		int height(Node* root)
		{
		    if(root==NULL)
		    {
		        return -1;
		    }
		    int l=height(root->left);
		    int r=height(root->right);
		    if(l>r)
		    {
		        return l+1;
		    }
		    else
		    {
		        return r+1;
		    }
		}
		
		void displaytree(Node* node, int space=0, int indent=5)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->right, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->left, space);
		}
	
	public:
	    BST():root(NULL)
		{
		}
	
	    void insert(int v)
		{
			root=insertion(root,v);
		}
		
	    void remove(int v)
		{
			root=deletenode(root,v);
		}
		
	    void update(int oldV,int newV)
		{
			updatevalue(oldV,newV);
		}
	
	    void search(int key)
		{
	        if(searchnode(root,key))
			{
				cout<<"\nFound "<<key<<endl;
			}
	        else 
			{
				cout<<"\nNot Found "<<key<<endl;
			}
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
				return height(node);
			}
		}
		
	    void printInorder()
		{
			cout<<"\nInorder   : ";
			inorder(root);
		}
		
	    void printPreorder()
		{
			cout<<"\nPreorder  : ";
			preorder(root);
		}
		
	    void printPostorder()
		{
			cout<<"\nPostorder : ";
			postorder(root);
		}
		
		void display()
		{
			displaytree( root, 0, 5);
		}

};

// ---------- MAIN ----------
int main(){
    BST tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();

    tree.search(40);
    tree.search(90);

    tree.update(40,45);
    tree.printInorder();

    tree.remove(20);
    cout<<"\n\n20 removed\n";
    tree.remove(70);
    cout<<"70 removed\n";
    tree.printInorder();
    
    tree.display();

    return 0;
}
