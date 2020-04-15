#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

class node				//declaring node class which will store the data
{
	public:
		int data;
		node *next;
};

class List : public node		//inheriting node class in List. List will contain all the methods
{
	public:
		node *listptr,*temp;
	
		List()					//contructor to initialize node pointers to NULL
		{
			listptr = NULL;
			temp = NULL;
		}
		
		void create()			//this method creates a new node
		{
			int num;
			
			do
			{
				node *newnode = new node;
				cout<< "Enter the element";
				cin >> num;
				
				newnode->data = num;
				newnode->next = NULL;
				
				if(listptr == NULL)				//condition to check if its the first element of the list
				{
					listptr = newnode;
					temp = newnode;
				}
				else
				{
					temp->next = newnode;
					temp = temp->next;
				}
			}while(getch() != 27);
		}
		
		void display()			//this method displays all elements of a list
		{
			node *temp1;
			
			cout << "\nThe elemets are: \n";
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else
			{
				for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
				{
					cout << temp1->data << "\n";
				}
			}
		}
		
		
		
		void push(int num)	//this method inserts an element at the end of the list
		{
			node *newnode = new node;
			
			newnode->data = num;
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
		
		
		int pop()	//this method deletes element from the end of the list
		{
			int num;
			
			node *temp1;
			
			if(listptr == NULL)
			{
				cout << "The stack is empty";
			}
			else if(listptr == temp)
			{
				delete temp;
				listptr = NULL;
				temp = NULL;
			}
			else
			{
				for(temp1 = listptr; (temp1->next)->next; temp1 = temp1->next);		//traversing to one before the last element
			
				num = temp->data;
			
				delete temp;
				temp = temp1;
				temp->next = NULL;
				
				return num;
			}
		}
		
};



main()
{
	List stack;
	
	int n;
	
	menu:
	
	system("cls");
	
	cout << "Enter the operation to be performed:\n1. Push\n2. Pop\n3. Display\n";
	
	switch(getch())
	{
		case '1':
			cout << "\nEnter the number to be entered\n";
			cin >> n;
			
			stack.push(n);
			goto menu;
			break;
			
		case '2':
			cout << "\nThe element deleted is: " << stack.pop() << "\n";
			if(getch() ==13)
			{
				goto menu;
			}
			break;
			
		case '3':
			stack.display();
			if(getch() == 13)
			{
				goto menu;
			}
			break;
			
		case 27:
			exit(0);
			
		default:
			goto menu;
			
	}
}
