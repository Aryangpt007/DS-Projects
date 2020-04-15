#include <iostream>
#include <conio.h>

using namespace std;

class node				//Intitialising tree node
{
	public:
		int data;
		node *right;
		node *left;
		
		node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
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

class Tree : public node			//Intialising tree and its methods
{
	public:
		node *root;					//root node to point to start of the tree
		Tree()
		{
			root = NULL;
		}
		
		
		void create(int a)			//function to create tree
		{
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
					if(temp->data > a)
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
					else if(temp->data < a)
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
		
		int countn(node *rnode)
		{
			static int count = 0;
			if(rnode)
			{
				count++;
				countn(rnode->left);
				countn(rnode->right);
			}
			return count;
		}
		
		int leaf_count(node *rnode)
		{
			static int count1 = 0;
			if(rnode != NULL)
			{
				leaf_count(rnode->left);
				if((rnode->left == NULL) && (rnode->right == NULL))
				{
					count1++;
				}
				leaf_count(rnode->right);
			}
			return count1;
		}
		
		void inorder(node *rtt)
		{
			node *temp2;
			temp2 = rtt;
			List stack;
			
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
		
};

void mirr(node *tr)
{
	Tree tree2;
	
	cout << "\n";
	tree2.inorder(tr);
	
	List stack1,stack2;
	
	node *temp1,*temp2;
	node *newnode = new node();
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
				node *newnode = new node();
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
			node *newnode = new node();
			temp2->left = newnode;
		}
		temp1 = temp1->right;
		temp2 = temp2->left;
	}
	cout << "\n";
	tree2.inorder(tree2.root);
}

void tcopy(node *tr)
{
	Tree tree2;
	
	cout << "\n";
	tree2.inorder(tr);
	
	List stack1,stack2;
	
	node *temp1,*temp2;
	node *newnode = new node();
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
				node *newnode = new node();
				temp2->left = newnode;
			}
			temp1 = temp1->left;
			
			temp2 = temp2->left;
		}
		if(stack1.listptr == NULL && stack2.listptr == NULL)
		{
			break;
		}
		
		temp1 = stack1.pop();
		temp2 = stack2.pop();
		
		if(temp1->right != NULL)
		{
			node *newnode = new node();
			temp2->right = newnode;
		}
		temp1 = temp1->right;
		temp2 = temp2->right;
	}
	cout << "\n";
	tree2.inorder(tree2.root);
}

main()
{
	int number;
	
	Tree tree;
	
	node *root_node;

	do
	{
		printf("Enter the operation to perform:\n1. Create\n2. Copy\n3. Mirror\n4. Total no. of nodes\n5. Total no. of leaf nodes");
	
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
				tcopy(tree.root);
				break;
				
			case '3':
				mirr(tree.root);
				break;
				
			case '4':
				cout << "\nThe no. of nodes are: " << tree.countn(tree.root);
				break;
				
			case '5':
				cout << "\nThe no. of leaf nodes are: " << tree.leaf_count(tree.root);
				break;
				
		}
		
		cout << "\n Press esc to exit \nPress any other key to continue\n";
		
	}while(getch() != 27);
}
