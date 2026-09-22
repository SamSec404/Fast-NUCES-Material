//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* leftchild;
		Node* rightchild;
		
		Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
		Node* root;
		
		int maxres(int l, int r)
		{
			if(l>=r)
			{
				return l;
			}
			if(r>l)
			{
				return r;
			}
		}
		
		int findheight(Node* root)
		{
			if(root==NULL)
			{
				return 0;
			}
			
			int lh=findheight(root->leftchild);
			int rh=findheight(root->rightchild);
			
			return 1+maxres(lh,rh);
		}
		
		void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
		
		public:
			BST():root(NULL){}
			
			void setroot(Node* r)
			{
				root=r;
			}
			
			void displaytree()
			{
				displaytree(root);
			}
			
			int findheight()
			{
				return findheight(root);
			}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	
	tree.setroot(root);
	
	cout<<"\nBinary Tree 1\n";
	tree.displaytree();
	
	cout<<"\nHeight\t"<<tree.findheight()<<"\n";
	
	
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
	    Node* left;
	    Node* right;
	
	    Node(int d):data(d),left(NULL),right(NULL){}
};

class BinaryTree
{
	private:
	    Node* root;
	
	public:
	    BinaryTree():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		void displaytree(Node* node, int space=0, int indent=4)
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
		
		void display()
		{
			displaytree(root);
		}
		
		int countleafhelper(Node* node)
		{
			if(node==NULL)
			{
				return 0;
			}
			
			if(node->left==NULL && node->right==NULL)
			{
				return 1;
			}
			
			return countleafhelper(node->left)+countleafhelper(node->right);
		}
		
		int countleafnodes()
		{
			return countleafhelper(root);
		}
		
		int countnonleafhelper(Node* node)
		{
			if(node==NULL)
			{
				return 0;
			}
			
			if(node->left!=NULL || node->right!=NULL)
			{
				return 1+countnonleafhelper(node->left)+countnonleafhelper(node->right);
			}
			
			return 0;
		}
		
		int countnonleafnodes()
		{
			return countnonleafhelper(root);
		}
		
		int counttotalhelper(Node* node)
		{
			if(node==NULL)
			{
				return 0;
			}
			
			return 1+counttotalhelper(node->left)+counttotalhelper(node->right);
		}
		
		int counttotalnodes()
		{
			return counttotalhelper(root);
		}
};

int main()
{
	BinaryTree tree1;
	
	Node* root1=new Node(1);
	root1->left=new Node(2);
	root1->right=new Node(3);
	root1->left->left=new Node(4);
	root1->left->right=new Node(5);
	
	tree1.setroot(root1);
	
	cout<<"\nBinary Tree\t";
	tree1.display();
	
	cout<<"\nTotal Nodes\t"<<tree1.counttotalnodes()<<"\n";
	cout<<"Leaf Nodes\t"<<tree1.countleafnodes()<<"\n";
	cout<<"Non-Leaf Nodes\t"<<tree1.countnonleafnodes()<<"\n";
	
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
        Node* leftchild;
        Node* rightchild;

        Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class Queue
{
	private:
		Node* ary[100];
		int front;
		int rear;
		
	public:
		Queue():front(0),rear(0){}
		
		bool isempty()
		{
			return rear==front;
		}
		
		void enqueue(Node* n)
		{
			ary[rear++]=n;
		}
		
		Node* dequeue()
		{
			if(isempty())
			{
				return NULL;
			}
			return ary[front++];
		}
};

class BST
{
    private:
        Node* root;
        
        void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}

    public:
        BST()
        {
            root = NULL;
        }

        void setroot(Node* r)
        {
            root=r;
        }
        
        void levelorder()
        {
        	if(root==NULL)
        	{
        		return;
			}
			
			Queue q;
			q.enqueue(root);
			
			while(!q.isempty())
			{
				Node* curr=q.dequeue();
				cout<<curr->data<<"\t";
				
				if(curr->leftchild!=NULL)
				{
					q.enqueue(curr->leftchild);
				}
				if(curr->rightchild!=NULL)
				{
					q.enqueue(curr->rightchild);
				}
			}
		}
        
        void displaytree()
        {
        	displaytree(root);
		}
};

int main()
{
    BST tree;

	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);

    tree.setroot(root);
    
    tree.displaytree();

    cout<<"\nLevel Order Traversal\n";
    tree.levelorder();

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
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	    
	    int diameter(Node* root, int &d)
		{
			if(root==NULL)
			{
				return 0;
			}
			
			int lh=diameter(root->leftchild,d);
			int rh=diameter(root->rightchild,d);
			
			int cd=lh+rh;
			
			if(cd>d)
			{
				d=cd;
			}
			
			return 1+max(lh,rh);
		}
		
		int max(int l, int r)
		{
			if(l>=r)
			{
				return l;
			}
			else if(r>l)
			{
				return r;
			}
			
		}
	
	public:
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
		
		void display()
		{
			displaytree(root);
		}
		
//		int max(int a, int b)
//		{
//			return (a>b)?a:b;
//		}
		
		int diameter()
		{
			int dia=0;
			diameter(root,dia);
			return dia;
		}
};
		

int main()
{
	BST tree;

	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	
	tree.setroot(root);
	
	cout<<"Binary Tree\n";
	tree.display();
	
	cout<<"\nDiameter\t"<<tree.diameter()<<" edges\n";
	
	return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#06***********----------------------------------------------------------------

/*
#include<iostream>
#include<climits>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	    
	    void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
		
	    
		bool isbst(Node* node, int minval, int maxval, bool)
		{
			if(node==NULL)
			{
				return true;
			}
			
			if(node->data<=minval || node->data>=maxval)
			{
				return false;
			}
			
			return isbst(node->leftchild, minval, node->data,true) && isbst(node->rightchild, node->data, maxval,false);
		}
	
	public:
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		
		void display()
		{
			displaytree(root);
		}
		
		bool isbst()
		{
			return isbst(root,INT_MIN,INT_MAX,true);
		}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	
	tree.setroot(root);
	
	tree.display();
	
	if(tree.isbst())
	{
	    cout<<"It is a BST";
	} 
	else 
	{
	    cout<<"\nNot a BST";
	}
	return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#07***********----------------------------------------------------------------

///*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	    
	    void displaytree(Node* node, int space=0, int indent=4)
 		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
		
		bool findpath(Node* node, int target, int path[], int &pathlen)
		{
			if(node==NULL)
			{
				return false;
			}
			
			path[pathlen]=node->data;
			pathlen++;
			
			if(node->data==target)
			{
				return true;
			}
			
			if(findpath(node->leftchild, target, path, pathlen) || findpath(node->rightchild, target, path, pathlen))
			{
				return true;
			}
			
			pathlen--;
			
			return false;
		}
		
	public:
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		
		void display()
		{
			displaytree(root);
		}
		
		
		void findpath(int target)
		{
			int path[100];
			int pathlen=0;
			
			if(findpath(root, target, path, pathlen))
			{
				cout<<"\nPath from root to "<<target<<"\t";
				
				for(int i=0; i<pathlen; i++)
				{
					cout<<path[i];
					if(i<pathlen-1)
					{
						cout<<" -> ";
					}
				}
				cout<<"\n";
			}
			else
			{
				cout<<"\nNode target not found\n";
			}
		}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	
	tree.setroot(root);
	
	cout<<"Binary Tree:\n";
	tree.display();
	
	tree.findpath(1);
	tree.findpath(3);
	
	
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
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	    
	    void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
	    
	    
		int sumofleftleaves(Node* node, bool isleft)
		{
			if(node==NULL)
			{
				return 0;
			}
			
			if(node->leftchild==NULL && node->rightchild==NULL && isleft)
			{
				return node->data;
			}
			
			int leftsum=sumofleftleaves(node->leftchild, true);
			int rightsum=sumofleftleaves(node->rightchild, false);
			
			return leftsum+rightsum;
		}
		
		void displayleftleaves(Node* node, bool isleft)
		{
			if(node==NULL)
			{
				return;
			}
			
			if(node->leftchild==NULL && node->rightchild==NULL && isleft)
			{
				cout<<node->data<<" ";
			}
			
			displayleftleaves(node->leftchild, true);
			displayleftleaves(node->rightchild, false);
		}
	    
	public:    
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		void display()
		{
			displaytree(root);
		}
		
		int sumofleftleaves()
		{
			return sumofleftleaves(root, false);
		}
		
		void displayleftleaves()
		{
			cout<<"Left Leaves\t";
			displayleftleaves(root, false);
			cout<<"\n";
		}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	root->rightchild->leftchild=new Node(6);
	
	tree.setroot(root);
	
	cout<<"\nBinary Tree\n";
	tree.display();
	
	cout<<"\n";
	tree.displayleftleaves();
	cout<<"Sum of Left Leaves\t"<<tree.sumofleftleaves()<<"\n";
	
	
	
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
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	    
	    void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
	
	public:
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		void display()
		{
			displaytree(root);
		}
		
		bool printancestor(Node* node, int target)
		{
			if(node==NULL)
			{
				return false;
			}
			
			if(node->data==target)
			{
				return true;
			}
			
			if(printancestor(node->leftchild, target) || printancestor(node->rightchild, target))
			{
				cout<<node->data<<" ";
				return true;
			}
			
			return false;
		}
		
		void printancestors(int target)
		{
			cout<<"\nAncestors of "<<target<<"\n";
			
			if(!printancestor(root, target))
			{
				cout<<"Node not found\n";
			}
			
			cout<<"\n";
		}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	
	tree.setroot(root);
	
	cout<<"\nBinary Tree\n";
	tree.display();
	
	tree.printancestors(5);
	tree.printancestors(10);
	
	
	return 0;
}
//*/



//-------------------------------------------------------------**********QUESTION#10***********----------------------------------------------------------------

/*
#include<iostream>
using namespace std;

class Node
{
	public:
	    int data;
	    Node* leftchild;
	    Node* rightchild;
	
	    Node(int d):data(d),leftchild(NULL),rightchild(NULL){}
};

class BST
{
	private:
	    Node* root;
	
		void displaytree(Node* node, int space=0, int indent=4)
		{
			if(node==NULL)
			{
				return;
			}
			
			space+=indent;
			
			displaytree(node->rightchild, space);
			
			cout<<endl;
			for(int i=indent; i<space; i++)
			{
				cout<<" ";
			}
			cout<<node->data<<"\n";
			
			displaytree(node->leftchild, space);
		}
		
	public:
	    BST():root(NULL){}
		
		void setroot(Node* r)
		{
			root=r;
		}
		
		void display()
		{
			displaytree(root);
		}
		
		void inorder(Node* node, int &count, int k, int &result)
		{
			if(node==NULL || count>=k)
			{
				return;
			}
			
			inorder(node->leftchild, count, k, result);
			
			count++;
			if(count==k)
			{
				result=node->data;
				return;
			}
			
			inorder(node->rightchild, count, k, result);
		}
		
		int smallest(int k)
		{
			int count=0;
			int result=-1;
			
			inorder(root, count, k, result);
			
			return result;
		}
		
		void displayinorder(Node* node)
		{
			if(node==NULL)
			{
				return;
			}
			
			displayinorder(node->leftchild);
			cout<<node->data<<" ";
			displayinorder(node->rightchild);
		}
		
		void displayinorder()
		{
			cout<<"Inorder Traversal\n";
			displayinorder(root);
			cout<<"\n";
		}
};

int main()
{
	BST tree;
	
	Node* root=new Node(3);
	root->leftchild=new Node(2);
	root->rightchild=new Node(4);
	root->leftchild->leftchild=new Node(1);
	root->leftchild->rightchild=new Node(5);
	
	tree.setroot(root);
	
	cout<<"\nBinary Search Tree 1\n";
	tree.display();
	
	cout<<"\n";
	tree.displayinorder();
	
	int k=3;
	cout<<k<<" Smallest Element\t"<<tree.smallest(k)<<"\n";
	
	
	return 0;
}
//*/





