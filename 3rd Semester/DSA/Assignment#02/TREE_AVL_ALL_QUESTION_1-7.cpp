//-------------------------------------------------------------**********QUESTION#01***********----------------------------------------------------------------

///*
#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node* leftchild;
        Node* rightchild;
        int height;

        Node(int d):key(d),leftchild(NULL),rightchild(NULL),height(1){}
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
		
		Node* insertion(Node* node, int key, bool& duplicate)
		{
			if(node==NULL)
			{
				return new Node(key);
			}
			
			if(key<node->key)
			{
				node->leftchild=insertion(node->leftchild,key,duplicate);
			}
			else if(key>node->key)
			{
				node->rightchild=insertion(node->rightchild,key,duplicate);
			}
			else
			{
				duplicate=true;
				return node;
			}
			
			updateheight(node);
			
			int balance=getbalance(node);
			
			//CASE 1:	(LL):
			if(balance>1 && key<node->leftchild->key)
			{
				return rotateright(node);
			}
			
			//CASE 2:	(LR):
			if(balance>1 && key>node->leftchild->key)
			{
				node->leftchild=rotateleft(node->leftchild);
				return rotateright(node);
			}
			
			//CASE 3:	(RR)
			if(balance<-1 && key>node->rightchild->key)
			{
				return rotateleft(node);
			}
			
			//CASE 4:	(RL)
			if(balance<-1 && key<node->rightchild->key)
			{
				node->rightchild=rotateright(node->rightchild);
				return rotateleft(node);
			}
			
			return node;
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
            cout<<node->key<<"\n";

            displaytree(node->leftchild, space);
        }
        
        Node* rotateright(Node* unbalancednode)
		{
			Node* elevatedbranchroot=unbalancednode->leftchild;
			Node* rightsubtree=elevatedbranchroot->rightchild;
			elevatedbranchroot->rightchild=unbalancednode;
			unbalancednode->leftchild=rightsubtree;
			
			updateheight(unbalancednode);
			updateheight(elevatedbranchroot);
			
			return elevatedbranchroot;
		}

        Node* rotateleft(Node* unbalancednode)
		{
			Node* elevatedbranchroot=unbalancednode->rightchild;
			Node* leftsubtree=elevatedbranchroot->leftchild;
			elevatedbranchroot->leftchild=unbalancednode;
			unbalancednode->rightchild=leftsubtree;
			
			updateheight(unbalancednode);
			updateheight(elevatedbranchroot);
			
			return elevatedbranchroot;
		}
		
		void updateheight(Node* node)
		{
			if(node==NULL)
			{
				return;
			}
				
			int leftheight=height(node->leftchild);
			int rightheight=height(node->rightchild);
			
			node->height=1+ (leftheight>rightheight?leftheight:rightheight);
			
		}

    public:
        BST():root(NULL){}

        int height(Node* node)
        {
            if(node==NULL)
            {
            	return 0;
			}
            return node->height;
        }

        int getbalance(Node* node)
        {
            if(node==NULL)
            {
            	return 0;
			}
            return height(node->leftchild) - height(node->rightchild);
        }

       

        void insert(int val)
        {
            bool duplicate=false;
            root=insertion(root, val, duplicate);
        }
        

        void display()
        {
            displaytree(root);
        }
};

int main()
{
    BST t;

    cout<<"Insert sequence:\t10, 20, 30\n";
    t.insert(10);
    t.insert(20);
    t.insert(30);

    cout<<"\nBalanced Tree after insertion\n\n";
    t.display();

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
        int height;

        Node(int d):data(d),left(NULL),right(NULL),height(1){}
};

class BST
{
    private:
        Node* root;

        int max(int a, int b)
        {
            return (a>b)?a:b;
        }

        int height(Node* node)
        {
            if(node!=NULL)
            {
                return node->height;
            }
            else 
            {
                return -1;
            }
        }

        void updateheight(Node* node)
        {
            int leftheight=height(node->left);
            int rightheight=height(node->right);

            node->height=1+ (leftheight>rightheight?leftheight:rightheight);
        }

        int getbalance(Node* node)
        {
            if(node!=NULL)
            {
                return height(node->left)-height(node->right);
            }
            else 
            {
                return 0;
            }
        }

        Node* rotateright(Node* unbalancednode)
        {
            Node* elevatedbranchroot=unbalancednode->left;
            Node* rightsubtree=elevatedbranchroot->right;
            elevatedbranchroot->right=unbalancednode;
            unbalancednode->left=rightsubtree;

            updateheight(unbalancednode);
            updateheight(elevatedbranchroot);

            return elevatedbranchroot;
        }

        Node* rotateleft(Node* unbalancednode)
        {
            Node* elevatedbranchroot=unbalancednode->right;
            Node* leftsubtree=elevatedbranchroot->left;
            elevatedbranchroot->left=unbalancednode;
            unbalancednode->right=leftsubtree;

            updateheight(unbalancednode);
            updateheight(elevatedbranchroot);

            return elevatedbranchroot;
        }

        Node* findmin(Node* node)
        {
            while(node->left != NULL)
            {
                node=node->left;
            }
            return node;
        }

        Node* deletion(Node* node, int key)
		{
			if(node==NULL)
			{
				return node;
			}
			
			if(key<node->data)
			{
				node->left=deletion(node->left,key);
			}
			else if(key>node->data)
			{
				node->right=deletion(node->right,key);
			}
			else
			{
				//found=true;
				
				if(node->left==NULL)
				{
					Node* temp=node->right;
					delete node;
					return temp;
				}
				else if(node->right==NULL)
				{
					Node* temp=node->left;
					delete node;
					return temp;
				}
				else
				{
					Node* temp=findmin(node->right);
					node->data=temp->data;
					node->right=deletion(node->right,temp->data);
				}
			}
			
			updateheight(node);
			
			int balance=getbalance(node);
			
			//CASE 1:	(LL):
			if(balance>1 && getbalance(node->left)>=0)
			{
				return rotateright(node);
			}
			
			//CASE 2:	(LR):
			if(balance>1 && getbalance(node->left)<0)
			{
				node->left=rotateleft(node->left);
				return rotateright(node);
			}
			
			//CASE 3:	(RR)
			if(balance<-1 && getbalance(node->right)<=0)
			{
				return rotateleft(node);
			}
			
			//CASE 4:	(RL)
			if(balance<-1 && getbalance(node->right)>0)
			{
				node->right=rotateright(node->right);
				return rotateleft(node);
			}
			
			return node;
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
            cout<<node->data << "\n";

            displaytree(node->left, space);
        }

    public:
        BST():root(NULL){}

        void setroot(Node* r)
        {
            root=r;
        }

        void Delete(int key)
        {
            root=deletion(root,key);
        }

        void display()
        {
            displaytree(root);
        }
};

int main()
{
    BST t;

    Node* r=new Node(20);
    r->left=new Node(10);
    r->right=new Node(30);
    r->right->right=new Node(40);

    t.setroot(r);

    cout << "Before deletion:\n";
    t.display();

    t.Delete(20);

    cout << "\nAfter deletion:\n";
    t.display();

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
        Node* left;
        Node* right;

        Node(int d):data(d),left(NULL),right(NULL){}
};

class AVL
{
    private:
        Node* root;
        
        int height(Node* node)
        {
            if(node==NULL)
			{
				return 0;
			}
			
            int lh=height(node->left);
            int rh=height(node->right);
            
            if(lh>rh)
            {
            	return lh+1;
			}
			else if(rh>lh)
			{
				return rh+1;
			}
        }
        
        void printBalanceFactor(Node* node)
        {
            if(node==NULL)
			{
				return;
			}

            int lh=height(node->left);
            int rh=height(node->right);
            
            int bf=lh-rh;

            printBalanceFactor(node->left);

            cout<<"Node "<<node->data<<" -> Balance Factor = "<<bf<<"\n";

            printBalanceFactor(node->right);
        }
    
    public:
        AVL():root(NULL){}

        void setroot(Node* r)
        {
            root=r;
        }

        void displayBF()
        {
            cout<<"Balance Factors\n";
            printBalanceFactor(root);
            cout<<"\n";
        }
};

int main()
{
    AVL tree;

    Node* root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(30);
    root->left->left=new Node(5);
    root->right->right=new Node(40);

    tree.setroot(root);

    cout<<"\nbalance facrtors\n\n";
    tree.displayBF();

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
        Node* left;
        Node* right;

        Node(int d):data(d),left(NULL),right(NULL){}
};

class AVL
{
    private:
        Node* root;

        void displaytree(Node* node, int space=0, int indent=5)
        {
            if(node==NULL)
                return;

            space += indent;

            displaytree(node->right, space);

            cout<<endl;
            for(int i=indent;i<space;i++)
                cout<<" ";
            cout<<node->data;

            displaytree(node->left, space);
        }

        Node* rotateright(Node* unbalancednode)
        {
            Node* elevatedbranchroot=unbalancednode->left;
            Node* rightsubtree=elevatedbranchroot->right;
            elevatedbranchroot->right=unbalancednode;
            unbalancednode->left=rightsubtree;
            return elevatedbranchroot;
        }

        Node* rotateleft(Node* unbalancednode)
        {
            Node* elevatedbranchroot=unbalancednode->right;
            Node* leftsubtree=elevatedbranchroot->left;
            elevatedbranchroot->left=unbalancednode;
            unbalancednode->right=leftsubtree;
            return elevatedbranchroot;
        }

        Node* LR(Node* unbalancednode)
        {
            unbalancednode->left=rotateleft(unbalancednode->left);
            return rotateright(unbalancednode);
        }

        Node* RL(Node* unbalancednode)
        {
            unbalancednode->right=rotateright(unbalancednode->right);
            return rotateleft(unbalancednode);
        }

    public:

        AVL():root(NULL){}

        void setroot(Node* r)
        {
            root=r;
        }
        
        
        void rotateright()
        {
            root = rotateright(root);
        }

        void rotateleft()
        {
            root = rotateleft(root);
        }

        void LR()
        {
            root = LR(root);
        }

        void RL()
        {
            root = RL(root);
        }

        void display(string msg)
        {
            cout<<"\n"<<msg<<"\n";
            displaytree(root);
            cout<<"\n";
        }
};

int main()
{
    AVL tree;
    
    
    Node* a = new Node(30);
    a->left = new Node(20);
    a->left->left = new Node(10);
    tree.setroot(a);

    tree.display("\nBefore LL Rotation");
    tree.rotateright();
    tree.display("After LL Rotation");
    
    
    Node* b = new Node(10);
    b->right = new Node(20);
    b->right->right = new Node(30);
    tree.setroot(b);

    tree.display("\nBefore RR Rotation");
    tree.rotateleft();
    tree.display("After RR Rotation");
    
    
    Node* c = new Node(30);
    c->left = new Node(10);
    c->left->right = new Node(20);
    tree.setroot(c);

    tree.display("\nBefore LR Rotation");
    tree.LR();
    tree.display("After LR Rotation");
    
    
    Node* d = new Node(10);
    d->right = new Node(30);
    d->right->left = new Node(20);
    tree.setroot(d);

    tree.display("\nBefore RL Rotation");
    tree.RL();
    tree.display("After RL Rotation");

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
        Node* left;
        Node* right;

        Node(int d):data(d),left(NULL),right(NULL){}
};

class AVL
{
    private:
        Node* root;

    public:
        AVL():root(NULL){}
        
        void setroot(Node* r)
		{
			root=r;
		}

        int height(Node* node)
        {
            if(node==NULL)
			{
				return 0;
			}
            int lh=height(node->left);
            int rh=height(node->right);
            
            return (lh>rh?lh:rh)+1;
        }

        bool isBalanced(Node* node)
        {
            if(node==NULL)
			{
				return true;
			}

            int lh=height(node->left);
            int rh=height(node->right);

            int bf=lh-rh;

            if(bf>1 || bf<-1)
			{
				return false;
			}

            return isBalanced(node->left) && isBalanced(node->right);
        }

        void check()
        {
            if(isBalanced(root))
            {
            	cout<<"Tree IS AVL Balanced\n";
			}
            else
            {
            	cout<<"Tree is NOT AVL Balanced\n";
			} 
        }
};

int main()
{
    AVL tree;

    Node* r=new Node(30);
    r->left=new Node(20);
    r->right=new Node(40);
    r->left->left=new Node(10);

    tree.setroot(r);
    
    tree.check();
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
        Node* left;
        Node* right;

        Node(int d):data(d),left(NULL),right(NULL){}
};

class AVL
{
    private:
        Node* root;
        
        
        void displaytree(Node* node, int space=0, int gap=5)
        {
            if(node==NULL)
            {
                return;
            }

            space=space+gap;

            displaytree(node->right,space);

            cout<<endl;
            for(int i=gap;i<space;i++)
            {
                cout<<" ";
            }
            cout<<node->data;

            displaytree(node->left,space);
        }
        
        
        Node* sortedArrayToAVL(int arr[],int start,int end)
        {
            if(start>end)
            {
                return NULL;
            }

            int mid=(start+end)/2;
            Node* node=new Node(mid[arr]);
            
            node=new Node(arr[mid]);

            node->left=sortedArrayToAVL(arr,start,mid-1);
            node->right=sortedArrayToAVL(arr,mid+1,end);

            return node;
        }

    public:

        AVL():root(NULL){}
        
        void setroot(Node* r)
        {
            root=r;
        }
        
        int height(Node* node)
        {
            if(node==NULL)
            {
                return -1;
            }

            int lh=height(node->left);
            int rh=height(node->right);

            return (lh>rh?lh:rh)+1;
        }
        
        void buildtree()
        {
            int n;
            cout<<"Enter size of array\t";
            cin>>n;

            if(n<=0)
            {
                cout<<"Invalid size\n";
                return;
            }

            int* arr=new int[n];

            cout<<"Enter "<<n<<" sorted values\n";
            
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }

            Node* temp=sortedArrayToAVL(arr,0,n-1);
            setroot(temp);

            cout<<"\nAVL Tree Created Successfully\n";

            delete[] arr;
        }
        
        void display()
        {
            cout<<"\nAVL TREE\n\n";
            displaytree(root);
            cout<<"\n\n";
        }
};

int main()
{
    AVL tree;
    tree.buildtree();
    tree.display();

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
        Node* left;
        Node* right;

        Node(int d):data(d),left(NULL),right(NULL){}
};

class AVL
{
    private:
        Node* root;

    public:
        AVL():root(NULL){}

        void setroot(Node* r)
        {
            root=r;
        }
        
        void levelOrder()
        {
            if(root==NULL)
            {
                cout<<"Tree is Empty!\n";
                return;
            }

            Node* Q[100];
            int front=0,rear=0;

            Q[rear++]=root;

            cout<<"\nLevel Order Output: ";

            while(front<rear)
            {
                Node* curr=Q[front++];
                cout<<curr->data<<" ";

                if(curr->left!=NULL)
                {
                    Q[rear++]=curr->left;
                }

                if(curr->right!=NULL)
                {
                    Q[rear++]=curr->right;
                }
            }

            cout<<"\n\n";
        }
        
        void buildtree()
        {
            Node* a=new Node(30);
            a->left=new Node(20);
            a->right=new Node(40);
            a->left->left=new Node(10);
            a->right->right=new Node(50);

            setroot(a);
        }
};

int main()
{
    AVL tree;

    tree.buildtree();

    cout<<"====== AVL Level Order BFS Traversal ======\n";
    tree.levelOrder();

    return 0;
}
*/




