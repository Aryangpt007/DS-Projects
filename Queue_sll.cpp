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
		
		void insert(int num)	//this method inserts an element at the end of the list
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
		
		int delet()	//this method deletes element from the start of the list
		{
			node *temp1;
			
			int n;
			
			temp1 = listptr;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else if(listptr->next == NULL)								//if its the last element in the list
			{
				n = listptr->data;
		
				delete listptr;
				listptr = NULL;
				temp = NULL;
			}
			else
			{
				n = listptr->data;
		
				temp1 = temp1->next;
				delete listptr;
				listptr = temp1;
			}
			return n;
		}
		
};


main()
{
	List queue;
	
	int n;
	
	menu:
		
	system("cls");
	
	cout << "Enter the operation to be performed:\n1. Insert\n2. Remove\n3. Display\n";
	
	switch(getch())
	{
		case '1':
			cout << "\nEnter the number to be entered\n";
			cin >> n;
			
			queue.insert(n);
			goto menu;
			break;
			
		case '2':
			cout << "\nThe element deleted is: " << queue.delet() << "\n";
			if(getch() == 13)
			{
				goto menu;
			}
			break;
			
		case '3':
			queue.display();
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
