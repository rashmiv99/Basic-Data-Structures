#include <iostream>
using namespace std;

class List;
class Club
{
	int prn;
	string name;
	Club *next;
	public:
		Club()
		{
			prn = 0;
			name = "xxxx";  //use double quotes
			next=NULL;
		}
		friend class List;
};

class List
{
	Club *start;
	Club *last;
	public:
		List()
		{
			start=NULL;
			last=NULL;
		}
		void insert()
		{
			int ch;
			Club *ele, *p;
			ele = new Club;
			p = new Club;
			cout<<"\n Choose from the following. \n 1. Insert President \n 2. Insert Secretary \n 3. Insert Student \n\n Enter your choice: ";
			cin>>ch;
			switch (ch)
			{
				case 1: cout<<"\n Enter the PRN number of the President: ";
						cin>>(ele->prn);
						cout<<"\n Enter the name of the President: ";
						cin>>(ele->name);
						if(start==NULL)  //list is empty! do not use next!
						{
							start=ele;
							ele->next=NULL;
							last=ele;
							last->next=NULL;
						}
						else
						{
							ele->next=start;
							start=ele;
						}
						break;
				case 2: cout<<"\n Enter the PRN number of the Secretary: ";
						cin>>(ele->prn);
						cout<<"\n Enter the name of the Secretary: ";
						cin>>(ele->name);
						if(start==NULL)
						{
							last=ele;
							ele->next=NULL;
							start=ele;
						}
						else
						{
							last->next=ele;
							last=ele;
							last->next=NULL;
						}
						break;
				case 3: cout<<"\n Enter the PRN number of the student: ";
						cin>>(ele->prn);
						cout<<"\n Enter the name of the student: ";
						cin>>(ele->name);
						if(start==NULL)
						{
							start=ele;
							ele->next=NULL;
							last=ele;
							last->next=NULL;
						}
						else
						{
							ele->next=start->next;
							start->next=ele;
						}
						break;
				default: cout<<"\n Wrong choice: ";
						 break;
			}
		}
		void del()
		{
			int ch, dp, flag=0;
			Club *p, *q;
			p=new Club;
			q=new Club;
			cout<<"\n Choose from the following. \n 1. Delete President \n 2. Delete Secretary \n 3. Delete Student \n\n Enter your choice: ";
			cin>>ch;
			switch(ch)
			{
				case 1: p=start->next;
						delete start;
						start=p;
						break;
				case 2: while(p->next!=last)
						{
							p=p->next;
						}
						p->next=NULL;
						delete last;
						last=p;
						break;
				case 3: cout<<"\n Enter the PRN number of the student you wish to delete: ";
						cin>>dp;
						p=start;
						while(p->next->prn!=dp && p->next!=NULL)
						{
							p=p->next;
						}
						if(p->next->prn == dp)
						{
							q=p->next;
							p->next=q->next;
							delete q;
						}
						else
						{
							cout<<"\n Student not found.";
						}
						break;
				default: cout<<"\n Wrong choice.";
						 break;
			}
		}
		void count()
		{
			int c=0;
			Club *p;
			p=new Club;
			p=start;
			while(p->next!=NULL)
			{
				c++;
				p=p->next;
			}
			c++;       //DONT FORGET
			cout<<"\n The total number of nodes are: "<<c;
		}
		void display()
		{
			Club *p;
			p=new Club;
			p=start;
			while(p!=NULL)   //dont use next!
			{
				cout<<"\n\n "<<p->prn<<"\t"<<p->name<<endl;
				p=p->next;
			}
		}
		void disprev(Club *p)    //using recursion
		{
			if(p!=NULL)   //dont use next! IT IS IF, NOT WHILE.
			{
				disprev(p->next);
				cout<<p->prn<<"\t"<<p->name<<endl;
			}
		}
		void concsort(List l1)
		{
			Club *t;
			Club *p;
			Club *q;
			p=new Club;
			q=new Club;
			t=new Club;
			last->next=l1.start;
			last=l1.last;
			p=start;
			while(p)
			{
				q=p->next;
				while(q)
				{
					if((q->prn)<(p->prn))
					{
						t->prn=q->prn;
						t->name=q->name;
						q->prn=p->prn;
						q->name=p->name;
						p->prn=t->prn;
						p->name=t->name;
					}
					q=q->next;
				}
				p=p->next;
			}
		}
		Club* getstart()
		{
			return start;
		}
};

int main()
{
	int ch;
	char ch1, choice;
	List ob, ob1;   //these are not supposed to be pointers
	Club *a;
	a=ob.getstart();
	do
	{
		cout<<"\n Choose from the following. \n 1. Insert node \n 2. Delete node \n 3. Total number of nodes \n 4. Display all nodes \n 5. Display all nodes in reverse \n 6. Concatenate and sort \n\n Enter your choice: ";
		cin>>ch;
		switch (ch)
		{
			case 1: ob.insert();
					cout<<"\n The list is as follows. ";
					ob.display();
					break;
			case 2: ob.del();
					cout<<"\n The list is as follows. ";
					ob.display();
					break;
			case 3: ob.count();
					break;
			case 4: ob.display();
					break;
			case 5: ob.disprev(a);   //pass start of the list to the function
					break;
			case 6: cout<<"\n We need a second list. ";
					do
					{
						ob1.insert();
						cout<<"\n Do you want to insert anymore? (y/n): ";
						cin>>ch1;
					}
					while(ch1=='y'||ch1=='Y');
					ob.concsort(ob1);
					cout<<"\n The list is as follows. ";
					ob.display();
					break;
			default: cout<<"\n Wrong choice.";
					 break;
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>choice;
	}
	while(choice=='y'||choice=='Y');
	return 0;
}		
