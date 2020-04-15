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
		
		void preorder_r(node *rnode)
		{
			if(rnode)
			{
				cout << rnode->data << " ";
				preorder_r(rnode->left);
				preorder_r(rnode->right);
			}
		}
		
		void search(int nn)
		{
			node *temp1;
			temp = root;
			
			while(1)
			{
				if(temp1->data == nn)
				{
					cout << "\nElement found";
					break;
				}
				else if(nn < temp1->data)
				{
					temp1 = temp1->left;
				}
				else if(nn > temp1->data)
				{
					temp1 = temp1->right;
				}
				else if(temp1 == NULL)
				{
					cout << "\n Element not found";
					break;
				}
			}
		}
		
		void delt(int nd)
		{
			node *temp1;
			temp = root;
			
			while(1)
			{
				if(temp1->data == nn)
				{
					cout << "\nElement found";
					if(temp1->right == NULL && temp1->left == NULL)
					{
						delete temp1;
					}
					else if(temp1->right == NULL || temp1->left == NULL)
					{
						
					}
					
					
					break;
				}
				else if(nn < temp1->data)
				{
					temp1 = temp1->left;
				}
				else if(nn > temp1->data)
				{
					temp1 = temp1->right;
				}
				else if(temp1 == NULL)
				{
					cout << "\n Element not found";
					break;
				}
			}
		}
		
};



main()
{
	int number;
	
	Tree tree;
	
	node *root_node;

	do
	{
		printf("Enter the operation to perform:\n1. Create\n2. Inorder recursive\n3. Search\n4. ");
	
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
				
			case '3'
				
		}
		
		cout << "\n Press esc to exit \nPress any other key to continue\n";
		
	}while(getch() != 27);
}
