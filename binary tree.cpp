// code of binary tree -> creation, preoder, postorder, inorder (using recursion)

#include <iostream>
using namespace std;

class node	//class node having data and pointers to points to left and right node
{
	public:
		int data;
		node *left;
		node *right;
};

class bin_tree : public node	//class bin_tree having all the operation for binary tree
{
	public:
		node *root;
		
		bin_tree()	//default constructor to initialise root
		{
			root = NULL;
		}
		
		void create()
		{
			cout << "\n\n\tCREATE NODE OF BINARY TREE\n";
			char ch; //choice variable for user
			char lr;	//choice variable for user for left or right node
			
			do
			{
				int data;
				node *temp;
				node *newnode = new node();
				
				cout << "\nEnter the value : ";
				cin >> data;
				newnode->data = data;	//storning data in node
				newnode->left = newnode->right = NULL;	//assigning pointer to null
				if (root == NULL)	//condition for empty tree
				{
					root = newnode;
					cout << "Root node created successfully.";
				}
				else
				{
					temp = root;
					while(1)
					{
						cout << "\nAdd node to left or right? R/L\nEnter your choice : ";
						fflush (stdin);
						cin >> lr;
						fflush (stdin);
						if (lr == 'l' || lr == 'L')
						{
							if (temp->left == NULL)
							{
								temp->left = newnode;
								cout << "Node added to the left.";
								break;
							}
							else
							{
								temp = temp->left;
								cout << "Temp moved to its left.";
							}
						}
						else if (lr == 'r' || lr == 'R')
						{
							if (temp->right == NULL)
							{
								temp->right = newnode;
								cout << "Node added to the right.";
								break;
							}
							else
							{
								temp = temp->right;
								cout << "Temp moved to its right.";
							}
						}
					}
				}
				cout << "\n\nAdd anymore node? Y/N\nEnter your choice : ";
				fflush (stdin);
				cin >> ch;
				fflush (stdin);
			}while (ch == 'y' || ch == 'Y');
		}
		
		void preorder_recursion(node *currentnode)	//vlr
		{
			if (currentnode != NULL)
			{
				cout << currentnode->data << " ";
				preorder_recursion (currentnode->left);	//recursive function call to its left
				preorder_recursion (currentnode->right);//recursive function call to its right
			}
		}
		
		void postorder_recursion(node *currentnode)	//lrv
		{
			if (currentnode != NULL)
			{
				preorder_recursion (currentnode->left);	//recursive function call to its left
				preorder_recursion (currentnode->right);//recursive function call to its right
				cout << currentnode->data << " ";
			}
		}
		
		void inorder_recursion(node *currentnode)	//lvr
		{
			if (currentnode != NULL)
			{
				preorder_recursion (currentnode->left);	//recursive function call to its left
				cout << currentnode->data << " ";
				preorder_recursion (currentnode->right);//recursive function call to its right
			}
		}
};

void choice (bin_tree tr)	//function for user menu
{
	int ch;
	cout << "\n\n\nChoose one of the following :\n1. Create Binary Tree\n2. Postorder Recursion\n3. Preorder Recursion\n4. Inorder Recursion\n5. Exit\nEnter Your Choice : ";
	cin >> ch;
	node *tt;
	switch (ch)
	{
		case 1 :
			tr.create();
			choice(tr);
			break;
			
		case 2 :
			cout << "\n\n\tPOSTORDER TRAVERSING\n\n";
			cout << "Postorder : ";
			tr.postorder_recursion(tr.root);
			choice(tr);
			break;
			
		case 3 :
			cout << "\n\n\tPREORDER TRAVERSING\n\n";
			cout << "Preorder : ";
			tr.preorder_recursion(tr.root);
			choice(tr);
			break;
			
		case 4 :
			cout << "\n\n\tINORDER TRAVERSING\n\n";
			cout << "Inorder : ";
			tr.inorder_recursion(tr.root);
			choice(tr);
			break;
			
		case 5 :
			cout << "\n\nProgram Ended!!";
			exit (0);
			break;
			
		case 6 :
			tt = tr.root;
			cout << tt->data << " " << tt->left->data << " " << tt->left->left->data << " " << tt->right->data;
			
		default : 
			cout << "Enter valid choice.";
			choice(tr);
	}
}

main()
{
	bin_tree tr;
	choice (tr);
}
