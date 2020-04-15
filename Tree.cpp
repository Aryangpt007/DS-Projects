#include <iostream>
#include <conio.h>

using namespace std;

class node				//Intitialising tree node
{
	public:
		int data;
		node *right;
		node *left;
};

class node1		//declaring node class which will store the data
{
	public:
		node *dat;
		node1 *next;
};

class List : public node1		//inheriting node class in List. List will contain all the methods
{
	public:
		node1 *listptr,*temp;
	
		List()					//contructor to initialize node pointers to NULL
		{
			listptr = NULL;
			temp = NULL;
		}
			
		
		void push(node *num)	//this method inserts an element at the end of the list
		{
			node1 *newnode = new node1;
			
			newnode->dat = num;
			newnode->next = NULL;
			
			if(listptr == NULL)
			{
				listptr = newnode;
				temp = newnode;
			}
			else
			{
				temp->next = newnode;
				temp = newnode;
			}
		}
		
		
		node* pop()	//this method deletes element from the end of the list
		{
			node *num;
			
			node1 *temp1;
			
			if(listptr == NULL)
			{
				cout << "The stack is empty";
			}
			else if(listptr == temp)
			{
				num = temp->dat;
				
				delete temp;
				listptr = NULL;
				temp = NULL;
				
				return num;
			}
			else
			{
				for(temp1 = listptr; (temp1->next)->next; temp1 = temp1->next);		//traversing to one before the last element
			
				num = temp->dat;
			
				delete temp;
				temp = temp1;
				temp->next = NULL;
				
				return num;
			}
		}
		
};


class Tree : public node, public List			//Intialising tree and its methods
{
	public:
		node *root;					//root node to point to start of the tree
		Tree()
		{
			root = NULL;
		}
		
		List stack;
		
		void create(int a)			//function to create tree
		{
			char dirr;
			int flag = 0;
			
			node *newnode = new node;
			node *temp;
			temp = root;
			
			newnode->data = a;
			newnode->right = NULL;
			newnode->left = NULL;
			
			if(root == NULL)
			{
				root = newnode;
				temp = root;
			}
			else
			{
				do
				{
					cout << "\nPress l to enter left Press r to enter right\n";
					dirr = getch();
					
					if(dirr == 'l' || dirr == 'L')
					{
						if(temp->left == NULL)
						{
							temp->left = newnode;
							flag = 0;
						}
						else
						{
							temp = temp->left;
							flag = 1;
						}
					}
					else if(dirr == 'r' || dirr == 'R')
					{
						if(temp->right == NULL)
						{
							temp->right = newnode;
							flag = 0;
						}
						else
						{
							temp = temp->right;
							flag = 1;
						}
					}
				}while(flag == 1);
			}
		}
		
		void preorder_r(node *rnode)
		{
			if(rnode)
			{
				cout << rnode->data << " ";
				preorder_r(rnode->left);
				preorder_r(rnode->right);
			}
		}
		
		int count(node *rnode)
		{
			static int count = 0;
			if(rnode)
			{
				count++;
				preorder_r(rnode->left);
				preorder_r(rnode->right);
			}
			return count;
		}
		
		void inorder_r(node *rnode)
		{
			if(rnode)
			{	
				inorder_r(rnode->left);
				cout << rnode->data << " ";
				inorder_r(rnode->right);
			}
		}
		
		void postorder_r(node *rnode)
		{
			if(rnode)
			{
				postorder_r(rnode->left);
				postorder_r(rnode->right);
				cout << rnode->data << " ";
			}
		}
		
		void inorder()
		{
			node *temp2;
			temp2 = root;
			
			while(1)
			{
				while(temp2)
				{
					stack.push(temp2);
					temp2 = temp2->left;
				}
				if(stack.listptr == NULL)
				{
					break;
				}
				
				temp2 = stack.pop();
				cout << temp2->data << " ";
				temp2 = temp2->right;
			}
		}
		
		void preorder()
		{
			node *temp2;
			temp2 = root;
			
			while(1)
			{
				while(temp2)
				{
					cout << temp2->data << " ";
					stack.push(temp2);
					temp2 = temp2->left;
				}
				
				if(stack.listptr == NULL)
				{
					break;
				}
					
				temp2 = stack.pop();
				temp2 = temp2->right;				
			}
		}
		
		void postorder()
	
	{
			node *temp2;
			temp2 = root;
			
			while(1)
			{
				while(temp2)
				{
					stack.push(temp2);
					stack.push(temp2);
					temp2 = temp2->left;
				}
				
				if(stack.listptr == NULL)
				{
					break;
				}
					
				temp2 = stack.pop();
			
				if(stack.listptr != NULL && (stack.temp)->dat == temp2)
				{
					temp2 = temp2->right;
				}
				else
				{
					cout << temp2->data << " ";
					temp2 = NULL;
				}					
			}
		}
		
};


void mirr(node *tr)
{
	Tree tree2;
	
	List stack1,stack2;
	
	node *temp1,*temp2;
	node *newnode = new node;
	newnode->data = 0;
	newnode->left = NULL;
	newnode->right = NULL;
	tree2.root = newnode;
	temp1 = tr;
	temp2 = tree2.root;
	
	while(1)
	{
		while(temp1)
		{
			temp2->data = temp1->data;
			stack1.push(temp1);
			stack2.push(temp2);

			if(temp1->left != NULL)
			{
			
				node *newnode = new node;
				newnode->data = 0;
				newnode->left = NULL;
				newnode->right = NULL;
				temp2->right = newnode;
			}
			temp1 = temp1->left;
			
			temp2 = temp2->right;
		}
		if(stack1.listptr == NULL && stack2.listptr == NULL)
		{
			break;
		}
	
		temp1 = stack1.pop();
		temp2 = stack2.pop();
	
		if(temp1->right != NULL)
		{
		
			node *newnode = new node;
			newnode->data = 0;
			newnode->left = NULL;
			newnode->right = NULL;
			temp2->left = newnode;
		}
		temp1 = temp1->right;
		temp2 = temp2->left;
	
	}
	
	tree2.inorder();
	
}


main()
{
	int number;
	
	Tree tree;
	
	node *root_node;

	do
	{
		printf("Enter the operation to perform:\n1. Create\n2. Preorder recursive\n3. Inorder recursive\n4. Postorder recursive\n5. Inorder Non-recursive\n6. Preorder Non-recursive\n7. Postorder Non-recursive\n8. Insert a element\n9. Copy Tree");
	
		switch(getch())
		{
			case '1':
				do
				{
					cout << "\nEnter the number to insert\n";
					cin >> number;
					tree.create(number);
				}while(getch() != 27);
				
				break;
				
			case '2':
				root_node = tree.root;
				tree.preorder_r(root_node);
				break;
				
			case '3':
				root_node = tree.root;
				tree.inorder_r(root_node);
				break;
			
			case '4':
				root_node = tree.root;
				tree.postorder_r(root_node);
				break;
				
			case '5':
				cout << "\n";
				tree.inorder();
				break;
				
			case '6':
				cout << "\n";
				tree.preorder();
				break;
				
			case '7':
				cout << "\n";
				tree.postorder();
				break;
				
			case '8':
				cout << "\nEnter the number to insert\n";
				cin >> number;
				tree.create(number);
				break;
				
			case '9':
				tree.inorder();
				mirr(tree.root);
				break;
			
		
				
		/*	case 'a':
				cout << "\nThe no. of nodes are: " << tree.count(tree.root);
				break;
				
			case 'b':
				cout << "\nThe no. of leaf nodes are: " << tree.lcount(tree.root);
				break;*/
		}
		
		cout << "\n Press esc to exit \nPress any other key to continue\n";
		
	}while(getch() != 27);
}

