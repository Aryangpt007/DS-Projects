/* LINKED LIST USING CLASS */

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
		
		int lenght()			//this method displays the no. of elements in the list
		{
			node *temp1;
			int count=0;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else
			{
				for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
				{
					count++;
				}
				
				cout << "The number of elements in the list are: " << count;
				
				return count;
			}
		}
		
		void insert_at_start()	//this method inserts an element at the beginning of the list
		{
			int num;
			
			node *newnode = new node;
			
			cout << "Enter the element to be inserted";
			cin >> num;
			
			newnode->data = num;
			
			if(listptr == NULL)
			{
				listptr = newnode;
				temp = newnode;
			}
			else
			{
				newnode->next = listptr;
				listptr = newnode;
			}
		}
		
		void insert_at_end()	//this method inserts an element at the end of the list
		{
			int num;
			
			node *newnode = new node;
			
			cout << "Enter the element to be inserted";
			cin >> num;
			
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
		
		void insert_at_position()	//this method inserts element at a particular position in the list
		{
			int num,pos,count=2,count1=0;	//pos = position
			node *temp1;				
			temp1 = listptr;
			
			node *newnode = new node;
			
			cout << "Enter the element to be inserted";
			cin >> num;
			
			cout << "Enter the position at which element is to be inserted";
			cin >> pos;
			
			for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
			{
				count1++;
			}
			
			newnode->data = num;
			
			if(listptr == NULL)
			{
				listptr = newnode;
				temp = newnode;
			}
			else if(count1 <= pos-1)			//condition to check if position entered is within range of the list
			{
				cout << "The position is out of range";
			}
			else if(pos == 1)
			{
				temp1 = listptr;
				listptr = newnode;
				listptr->next = temp1;
			}
			else
			{
				for(temp1 = listptr; count < pos; temp1 = temp1->next)
				{
					count++;
				}
				
				newnode->next = temp1->next;
				temp1->next = newnode;
			}
		}
		
		void delete_at_start()	//this method deletes element from the start of the list
		{
			node *temp1;
			
			temp1 = listptr;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else if(listptr->next == NULL)								//if its the last element in the list
			{
				cout << "The element deleted is: " << listptr->data;
		
				delete listptr;
				listptr = NULL;
				temp = NULL;
			}
			else
			{
				cout << "The element deleted is: " << listptr->data;
		
				temp1 = temp1->next;
				delete listptr;
				listptr = temp1;
			}
		}
		
		void delete_at_end()	//this method deletes element from the end of the list
		{
			node *temp1;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
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
			
				cout << "The element deleted is: " << temp->data;
			
				delete temp;
				temp = temp1;
				temp->next = NULL;
			}
		}
		
		void delete_at_position()	//this method deletes element at a particular position
		{
			int pos,count=0;
			
			node *temp1,*temp2;
			temp1 = listptr;
			
			cout << "\nEnter the position at which element is to be deleted";
			cin >> pos;
			
			for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
			{
				count++;
			}
			
			if(listptr == NULL)
			{
				cout << "\nThe list is empty";
			}
			else if(count <= pos-1)			//condition to check if position entered is within range of the list
			{
				cout << "\nThe position is out of range";
			}
			else if(pos == 1)					//if its the first element of the list
			{
				temp1 = listptr;
				
				if(listptr == temp)
				{
					temp = NULL;
				}
				delete (temp1);
				listptr = listptr->next;
			}
			else
			{
				count = 2;
				for(temp1 = listptr; count < pos; temp1 = temp1->next)
				{
					count++;
				}
				
				temp2 = temp1->next;
				
				if(temp2->next == NULL)
				{
					temp = temp1;
				}
				
				cout << "The element deleted is: " << temp2->data;
				temp1->next = temp2->next;
				delete (temp2);
			}
		}
		
		void delete_by_search()		//this method deletes the element entered by the user
		{
			int search;
			
			node *temp1, *temp2;
			temp1 = listptr;
			
			cout << "Enter the element to be deleted";
			cin >> search;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else if((listptr->data) == search)		//if its the first element of the list
			{
				temp1 = listptr;
				listptr = listptr->next;
				delete (temp1);
			}
			else if((listptr->data) != search && (listptr)->next == NULL)
			{
				cout << "The element can not be found";
			}
			else
			{
				while((temp1->next)->data != search && temp1 != NULL)
				{
					temp1=temp1->next;
				}
				
				if(temp1 == NULL)
				{
					cout << "The element can not be found";
				}
				else
				{
					temp2 = (temp1->next)->next;
					
					if(temp2 == NULL)
					{
						temp = temp1;
					}
					delete temp1->next;
					temp1->next = temp2;
				}
			}
		}
		
		void delete_pos()
		{
			int search,i=0,count=0,flag=0;
			
			node *temp1,*temp2;
			temp1 = listptr;
			
			cout << "Enter the element to search";
			cin >> search;
			
			for(temp2 = listptr; temp2 != NULL; temp2 = temp2->next)		//traversing through the list
			{
				count++;
			}
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else
			{
				temp1 = listptr;
				for(i=0;i<count;i++)
				{
					if(temp1->data == search)
					{
						
						cout << "\nThe element is found at: " << i+1;
						flag = 1;
					}
					temp1=temp1->next;
				}
				
				if(flag == 0)
				{
					cout << "The element was not found";
				}
				else
				{
					do
					{
					cout << "\n1. Delete all elements\n2. Delete specific element";
					
						switch(getch())
						{
							case '1':
								{
									temp1 = listptr;
									for(i=0;i<count;i++)
									{
										cout << " for";
										while(temp1->next != NULL)
										{
											if((temp1->next)->data == search && temp1->next != NULL)
											{
												cout << " if";
												temp2 = temp1->next;
												cout << temp2->data;
												temp1->next = temp2->next;
												delete(temp2);
												cout << " delete";
											}
											else if(temp1->next != NULL)
											{
												cout << " else";
												temp1=temp1->next;
											}
										}
									}
								break;
								}
							
							case '2':
								delete_at_position();
								break;
							
							default:
								break;
						}
					}while(getch() == 13);
				}
			}
		}
		
		
		void search()				//to search for an element in a list
		{
			int search,i=0;
			
			node *temp1;
			temp1 = listptr;
			
			cout << "Enter the element to search";
			cin >> search;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else
			{
				while(temp1->data != search && temp1 != NULL)
				{
					temp1=temp1->next;
					i++;
				}
				
				if(temp1 == NULL)
				{
					cout << "The element can not be found";
				}
				else
				{
					cout << "The element is found at: " << i+1;
				}
			}
		}
		
		void reverse()				// to reverse the linked list
		{
			node *temp1 = listptr,*temp2 = (listptr->next),*temp3 =	((listptr->next)->next);
			
			int count=0;
			
			for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
			{
				count++;
			}
			
			temp1 = listptr;
			temp = listptr;
			
			for(int i = 0;i<count-2;i++)
			{
				temp2->next = temp1;
				temp1 = temp2;
				temp2 = temp3;
				temp3 = temp3->next;
			}
			temp2->next = temp1;
			listptr = temp2;
			temp->next = NULL;
			
		}
		
		
		void concatenate()				//To add a second list to the main list
		{
			system("cls");
			
			List lst2;
			
			cout << "\nEnter a new list\n";
			
			lst2.create();				
			
			concatenation_menu:
			
			cout << "\nOPERATIONS:\n1. Concatenate at beginning\n2. Concatenate at intermediate\n3. Concatenate at last\n";
			
			switch(getch())
			{
				case '1':
					if(listptr == NULL)
					{
						listptr = lst2.listptr;
						temp = lst2.temp;
					}
					else
					{
						lst2.temp->next = listptr;
						listptr = lst2.listptr;
					}
					break;
					
				case '2':
					{
					int pos,count=0;	//pos = position
					node *temp1;				
					temp1 = listptr;
			
					cout << "Enter the position at which element is to be inserted";
					cin >> pos;
			
					for(temp1 = listptr; temp1 != NULL; temp1 = temp1->next)		//traversing through the list
					{
						count++;
					}
			
					if(listptr == NULL)
					{
						listptr = lst2.listptr;
						temp = lst2.temp;
					}
					else if(count <= pos-1)			//condition to check if position entered is within range of the list
					{
						cout << "The position is out of range";
					}
					else if(pos == 1)
					{
						listptr = lst2.listptr;
						lst2.temp->next = temp1;
					}
					else
					{
						count = 2;
						for(temp1 = listptr; count < pos; temp1 = temp1->next)
						{
							count++;
						}
				
						lst2.temp->next = temp1->next;
						temp1->next = lst2.listptr;
					}
					break;
					}
					
				case '3':
					if(listptr == NULL)
					{
						listptr = lst2.listptr;
						temp = lst2.temp;
					}
					else
					{
						temp->next = lst2.listptr;
						temp = lst2.temp;
					}
					break;
					
				case 27:
					break;
				
				default:
					goto concatenation_menu;	
			}
		}
		
		
		void sort()
		{
			 node *element1,*element2;
			 int tmp,count=0;
			 
			for(element2 = listptr; element2 != NULL; element2 = element2->next)		//traversing through the list
			{
				count++;
			}
			
			for(int i = 0;i < count;i++)
			{ 
			 	for(element1 = listptr;element1->next;element1 = element1->next)
			 	{
			 		if(element1->data > (element1->next)->data)
			 		{
			 			tmp = element1->data;
			 			element1->data = (element1->next)->data;
			 			(element1->next)->data = tmp;
					}
				}
			}
			
			cout << "\nList Sorted";
		}
};



/* MAIN */
main()
{
	List lst;			//object of List created
	
	menu:				//label for main menu
		
		do
		{
			system("cls");
			
			cout << "What operation you want to perform:\n";
			cout << "1. Create\n";
			cout << "2. Display\n";
			cout << "3. Lenght of the list\n";
			cout << "4. Insert element at start\n";
			cout << "5. Insert element at the last\n";
			cout << "6. Insert element in a particular position\n";
			cout << "7. Delete element at start\n";
			cout << "8. Delete element at the last\n";
			cout << "9. Delete a particular position\n";
			cout << "a. Delete a particular element\n";
			cout << "b. Search for an element\n";
			cout << "c. Reverse the list\n";
			cout << "d. Sort the list\n";
			cout << "e. Concatenate\n";
	
			switch(getch())
			{
				case '1':
					lst.create();
					break;
			
				case '2':
					lst.display();
					break;
			
				case '3':
					lst.lenght();
					break;
			
				case '4':
					lst.insert_at_start();
					break;
			
				case '5':
					lst.insert_at_end();
					break;
			
				case '6':
					lst.insert_at_position();
					break;
			
				case '7':
					lst.delete_at_start();
					break;
			
				case '8':
					lst.delete_at_end();
					break;
			
				case '9':
					lst.delete_at_position();
					break;
			
				case 'a':
					lst.delete_by_search();
					break;
			
				case 'b':
					lst.search();
					break;
			
				case 'c':
					lst.reverse();
					break;
				
				case 'd':
					lst.sort();
					break;
				
				case 'e':
					lst.concatenate();
					break;
					
				case 'f':
					lst.delete_pos();
					break;
				case 27:
					exit(0);
				
				default:
					goto menu;
				
			}
			
			cout << "\nPress Enter for main menu";
		}while (getch() != 27);
}
