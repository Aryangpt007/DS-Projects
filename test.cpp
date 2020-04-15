#include<iostream>
using namespace std;

class polynode
{
	public:
	float coef;
	int exp;
	polynode *next;
};

class polylist:public polynode
{
	public:
		polynode *listptr,*temp;
		polylist()
		{
			listptr=NULL;
			temp=NULL;
		}
		void create();
		void display();
		void add_poly();
		void mul_poly();
		polynode* get_node();
		
};

void polylist::create()
{
		polynode *newnode=new polynode;
		float c;
		int e;
		cout<<"Enter coefficient and exponent:";
		cin>>c;
		cin>>e;
		newnode->coef=c;
		newnode->exp=e;
		newnode->next=NULL;
		
		if(listptr==NULL)
		{
			listptr=temp=newnode;
		}
	

		if(e!=0)
		{
			
			temp->next=newnode;
			temp=temp->next;
			create();
			
		}
		else if(e==0)
		{
			newnode->coef=c;
			newnode->exp=e;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
	}
}


void polylist::display()
{
	polynode *temp1 = new polynode;
	for(temp1=listptr;temp1!=NULL;temp1=temp1->next)
		{
			cout<<temp1->coef<<"x^"<<temp1->exp<<"\t";
		}
}

polynode* polylist::get_node()
{
	return listptr;
}

void polylist::mul_poly()
{
	float s1;
	int s2;
	polylist p1,p2,p3;
	
	cout<<"\nList 1\n";
	p1.create();
	cout<<"\nList 2\n";
	p2.create();
	
	polynode *t1=p1.get_node();
	polynode *t2=p2.get_node();
	polynode *t3=p3.get_node();
	
	if(t1==NULL || t2==NULL)
	{
		temp=listptr;
	}
	for(t1;t1!=NULL;t1=t1->next)
	{
		t2 = p2.listptr;
		for(t2;t2!=NULL;t2=t2->next)
		{
			polynode *newnode=new polynode;
			polynode *temp1;
			temp1=newnode;
			s1=(t1->coef)*(t2->coef);
			s2=(t1->exp)+(t2->exp);
			newnode->coef=s1;
			newnode->exp=s2;
			newnode->next=NULL;
			if(t3 == NULL)
			{
				p3.listptr = newnode;
				t3=newnode;
				t3->next = NULL;
			}
			else
			{
				t3->next = newnode;
				t3 = t3->next;
			}
		}
	}
	polynode *t4,*t5;
	for(t3;t3!=NULL;t3=t3->next)
	{
		for(t4=t3->next;t3!=NULL;t3=t3->next)
		{
			cout<<"ABCD";
			if(t3->exp==t4->exp)
			{
				t5=t4->next;
				t3->coef=t3->coef+t4->coef;
				delete t4;
				t3->next=t5;
			}
		}
	}
	
	p3.display();
}

void polylist::add_poly()
{
	polylist p1,p2,p3;
	polynode *t1 = new polynode;
	polynode *t2 = new polynode;
	polynode *t3 = new polynode;
	polynode *t4 = new polynode;
	cout<<"\nList 1\n";
	p1.create();
	cout<<"\nList 2\n";
	p2.create();
	
	t1=p1.get_node();
	t2=p2.get_node();
	t3=p3.get_node();
	t4 = t3;

	polynode *newnode = new polynode;
	while(t1!=NULL && t2!=NULL)
	{
		cout<<"ABCD";
		if(t1->exp==t2->exp)
		{
			cout << "if1";
			newnode->coef=(t1->coef)+(t2->coef);
			newnode->exp=t1->exp;
			newnode->next=NULL;
			
			t1=t1->next;
			t2=t2->next;
			if(t3 == NULL)
			{
				t3=newnode;
			}
			else
			{
				t3->next=newnode;
				t3=t3->next;
			}
			
		}
		
		else if(t1->exp < t2->exp)
		{
			cout << "if2";
			newnode->coef=t2->coef;
			newnode->exp=t2->exp;
			newnode->next=NULL;
			t2=t2->next;
			if(t3 == NULL)
			{
				t3=newnode;
			//	t4 = t3;
			}
			else
			{
				t3->next=newnode;
				t3=t3->next;
			}
		}
		
		else
		{
			cout << "if3";
			newnode->coef=t1->coef;
			newnode->exp=t1->exp;
			newnode->next=NULL;
			t1=t1->next;
			if(t3 == NULL)
			{
				t3=newnode;
			//	t4 = t3;
			}
			else
			{
				t3->next=newnode;
				t3=t3->next;
			}
		}
	}
	
	while(t1)
	{
		newnode->coef=t1->coef;
		newnode->exp=t1->exp;
		newnode->next=NULL;
		t1=t1->next;
		if(t3 == NULL)
			{
				t3=newnode;
			//	t4 = t3;
			}
			else
			{
				t3->next=newnode;
				t3=t3->next;
			}
	}
	
	while(t2)
	{
		newnode->coef=t2->coef;
		newnode->exp=t2->exp;
		newnode->next=NULL;
		t2=t2->next;
		if(t3 == NULL)
			{
				t3=newnode;
			//	t4 = t3;
			}
			else
			{
				t3->next=newnode;
				t3=t3->next;
			}
	}
//p3.listptr = t4;
	cout << t4->exp;
	p3.display();
}
int main()
{
	polylist p;
	char ch;
	while(ch!='n'|| ch!='N')
	{
		cout<<"Enter \n 1 for creating a polynomial\n 2 for displaying the polynomial \n 3 for adding two polynomials \n 4 for multiplying two polynomials";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case '1': p.create();
				  	  break;
		
			case '2': p.display();
			          break;
			
			case '3': p.add_poly();
					  break;
			          
			case '4': p.mul_poly();
					  break;
		}
		cout<<"\nDo you want to continue(Y/N)";
	   	cin>>ch;	
	   	
	   	polynode *c1 = new polynode;
	   	polynode *c2 = new polynode;
	   	
	   	polylist x;
	   	
	   //	c1 = x.get_node();
	   	
	   	c1->coef=12;
	   	c1->exp=3;
	   	c1->next=NULL;
	   	
	   	x.listptr = c1;
	   	
	   	c2->coef=13;
	   	c2->coef=0;
	   	c2->next = NULL;
	   	c1->next = c2;
	   	c1 = c1->next;
	   	//c2 = x.get_node();
	   	cout << (x.listptr->next)->coef;
	}
	
	return 0;
}
