/*
Implementation of Stacks using Arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#

/*Function Declaration*/
void push(int); 				//Pushes 'int' value passed into the stack
int pop();       				//Pops out most recently added element from the stack		
void print();    				//Prints the wholes Stack

/*Global variable declration*/
int *stack;						//Array for stack declared
     				
int count = 0;					//Keep count for no. of element in stack




main()
{
	system("cls");				//cleares screen
	
	stack = (int*) malloc (10 * sizeof(int));   
	
	printf("Stack Operations:\n1. Push into the stack\n2. Pop element from the Stack\n3. Print elements of the Stack\n4. Exit");
	
	switch(getch())
	{
		case '1':
			system("cls");

			int element;
			
			printf("Enter the element:\n");
			scanf("%d", &element);					//taking input from user
			push(element);
			
			main();
			break;
			
		case '2':
			system("cls");
			
			pop();
			
			if(getch() == 13)
			{
				main();
			}
			
			break;
			
		case '3':
			system("cls");
			
			print();

			break;
			
		case '4':
			exit(0);		//exits the program
			
			break;
	}
}



/*Function Definition*/
void push(int value)
{
	stack[count++] = value;	//first insert the value in the stack then increases the counter		
	printf("%d",stack[count-1]);
}

int pop()
{
	printf("%d", (stack[count - 3]));
	//return (stack[--count]);			//first decreses cunter then retrurn the element removed
}

void print()
{
	printf("	Stack	\n");
	
	for(int i = count;i > 0;i--)
	{
		printf("	 %d \n", stack[i-1]);
	}
	
	if(getch() == 13)			   //executes when enter key is pressed
	{
		main();
	}
}
