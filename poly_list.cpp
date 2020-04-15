/* APPLLICATION OF SINGLY LINKED LIST */
	/*Representation of Polynomials*/
	
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

using namespace std;

class polynode
{
	public:
		
		double coef;
		int exp;
		polynode *next;
};

class polyclass : public polynode
{
	polynode *listptr,*temp;
	
	public:
		polyclass()
		{
			listptr = NULL;
			temp = NULL;
		}
		
		create_poly(double c,int e)
		{
	
				polynode *newnode = new polynode;
		
				newnode->coef = c;
				newnode->exp = e;	
				newnode->next = NULL;
				
				if(listptr == NULL)
				{
					listptr = newnode;
					temp = newnode;
				}			
				else
				{
					temp->next = newnode;
					temp = temp->next;
				}
		
		}
		
		void display_poly()			//this method displays all elements of a list
		{
			polynode *temp1;
			
			if(listptr == NULL)
			{
				cout << "The list is empty";
			}
			else
			{
				for(temp1 = listptr; temp1->next != NULL; temp1 = temp1->next)		//traversing through the list
				{
					cout << temp1->coef << "x^" << temp1->exp << " + ";
				}
				
				if(temp1->exp == 0)
				{
					cout << temp1->coef;
				}
				else
				{
					cout << temp1->coef << "x^" << temp1->exp;
				}
			}
		}
		
		polynode* getpoly()
		{
			return listptr;
		}
};



void polyadd()
{
	polyclass p1,p2,res;
	
	int  i=1;
	
	polynode *n1 = new polynode;
	polynode *n2 = new polynode;
	
	double c;
	int e;
	
	cout << "\nEnter first polynomial\n";
	
	do
	{
		cout << "\nEnter Co-efficient";
		cin >> c;
		cout << "\nEnter power of x";
		cin >> e;
		
		p1.create_poly(c,e);
	}while(getch() == 13);
	
	cout << "\nPolynomial:\n";
	p1.display_poly();
	n1 = p1.getpoly();
	
	cout << "\nEnter second polynomial\n";
	
	do
	{
		cout << "\nEnter Co-efficient";
		cin >> c;
		cout << "\nEnter power of x";
		cin >> e;
		
		p2.create_poly(c,e);
	}while(getch() == 13);
	
	cout << "\nPolynomial:\n";
	p2.display_poly();
	n2 = p2.getpoly();
	
	while(n1 != NULL && n2 !=NULL)
	{
		if(n1->exp == n2->exp)
		{
			res.create_poly(((n1->coef)+(n2->coef)),(n1->exp));
			n1 = n1->next;
			n2 = n2->next;
		}
		else if(n1->exp > n2->exp)
		{
			res.create_poly((n1->coef),(n1->exp));
			n1 = n1->next;
		}
		else
		{
			res.create_poly((n2->coef),(n2->exp));
			n2 = n2->next;
		}
	}
	
	while(n1 != NULL)
	{
		res.create_poly((n1->coef),(n1->exp));
		n1 = n1->next;
	}
	while(n2 != NULL)
	{
		res.create_poly((n2->coef),(n2->exp));
		n2 = n2->next;
	}
	cout << "\n(";
	p1.display_poly();
	cout << ") + (";
	p2.display_poly();
	cout << ") = ";
	res.display_poly();
}



void evalpoly()
{
	polyclass p3;
	
	double c,x,sum=0;
	int e;
	
	polynode *n3 = new polynode;
	
	cout << "\nEnter first polynomial\n";
	
	do
	{
		cout << "\nEnter Co-efficient";
		cin >> c;
		cout << "\nEnter power of x";
		cin >> e;
		
		p3.create_poly(c,e);
	}while(getch() == 13);
	
	cout << "\nPolynomial:\n";
	p3.display_poly();
	n3 = p3.getpoly();
	
	cout << "\nEnter the value of x:\n";
	cin >> x;
	
	while(n3)
	{
		sum = sum + ((n3->coef) * (pow(x,(n3->exp))));
		n3 = n3->next;
	}
	
	cout << "\nThe value of the polynomial is : " << sum; 
	
	
}



void mulpoly()
{
	int j=0;
	
	polyclass p4,p5,res1;
	
	polynode *n4 = new polynode;
	polynode *n5 = new polynode;
	polynode *result = new polynode;
	polynode *cmp = new polynode;
	polynode *temp1 = new polynode;
	
	double c;
	int e;
	
	cout << "\nEnter first polynomial\n";
	
	do
	{
		cout << "\nEnter Co-efficient";
		cin >> c;
		cout << "\nEnter power of x";
		cin >> e;
		
		p4.create_poly(c,e);
	}while(getch() == 13);
	
	cout << "\nPolynomial:\n";
	p4.display_poly();
	n4 = p4.getpoly();
	
	cout << "\nEnter second polynomial\n";
	
	do
	{
		cout << "\nEnter Co-efficient";
		cin >> c;
		cout << "\nEnter power of x";
		cin >> e;
		
		p5.create_poly(c,e);
	}while(getch() == 13);
	
	cout << "\nPolynomial:\n";
	p5.display_poly();
	
	
	while(n4)
	{
		n5 = p5.getpoly();
		while(n5)
		{
			res1.create_poly(((n4->coef)*(n5->coef)),((n4->exp)+(n5->exp)));
			n5 = n5->next;
		}
		n4 = n4->next;
	}
	cout << "\n";
	res1.display_poly();
	result = res1.getpoly();
	
	while(result)
	{
		cmp = result;
		while(cmp->next)
		{
			//cout << "\ncompare " << j << " \n";
			//cout << "\n" << result->exp << " " << (cmp->next)->exp << "\n";
			if(result->exp == (cmp->next)->exp)
			{

				temp1 = (cmp->next)->next;
				result->coef = result->coef + (cmp->next)->coef;
				delete (cmp->next);
				cmp->next = temp1;
			}
			cmp = cmp->next;
		}
		j = j + 1;
		result = result->next;
	}
	cout << "\n";
	res1.display_poly();
	
}




main()
{
	system("cls");
	cout << "What operation do you want to perform:\n1. Addition of Polynomials\n2. Evaluating a Polynomial\n3. Multiply two polynomials\n";
	
	switch(getch())
	{
		case '1':
			polyadd();
			break;
			
		case '2':
			evalpoly();
			break;
			
		case '3':
			mulpoly();
			break;
	}
}




