#include <iostream>
using namespace std;
#define MAX 10

class Deque
{
	int q[MAX];
	int front;
	int rear;
	int count;
	public:
		Deque()
		{
			front = -1;
			rear = -1;
			count = 0;
			for(int i=0; i<MAX; i++)
			{
				q[i]=0;
			}
		}
		void insertfront()
		{
			int n;
			cout<<"\n Enter the value to be inserted: ";
			cin>>n;
			if(count<MAX)
			{
				if(front==-1 && rear==-1)
				{
					front=0;
					rear=0;
					q[0]=n;
					count++;
				}
				else
				{
					if(front==0)
					{
						for(int i=rear; i>=0; i--)
						{
							q[i+1]=q[i];
						}
						rear++;
						q[front]=n;
					}
					else
					{
						front--;
						q[front]=n;
					}
					count++;
				}
			}
			else
			{
				cout<<"\n Sorry the queue is full.";
			}
		}
		void insertrear()
		{
			int n;
			cout<<"\n Enter the value to be inserted: ";
			cin>>n;
			if(count<MAX)
			{
				if(front==-1 && rear==-1)
				{
					front=0;
					rear=0;
					q[0]=n;
					count++;
				}
				else
				{
					if(rear==MAX-1)
					{
						for(int i=front; i<MAX; i++)
						{
							q[i]=q[i+1];
						}
						front--;
						q[rear]=n;
					}
					else
					{
						rear++;
						q[rear]=n;
					}
					count++;
				}
			}
			else
			{
				cout<<"\n Sorry the queue is full.";
			}
		}
		void delfront()
		{
			if(front==-1)   //important
			{
				cout<<"\n Sorry the queue is empty.";
			}
			else
			{
				q[front]=0;
				front++;
				count--;	
				if(front>rear)
				{
					front=-1;
					rear=-1;
					count=0;
				}
			}
		}
		void delrear()
		{
			if(rear==-1)
			{
				cout<<"\n Sorry the queue is empty.";
			}
			else
			{
				q[rear]=0;
				rear--;
				count--;
				if(front>rear)     //important
				{
					front=-1;
					rear=-1;
					count=0;
				}
			}
		}
		void display()
		{
			for(int i=0; i<MAX; i++)
			{
				cout<<" "<<q[i];
			}
			
		}
};

int main()
{
	Deque q1;
	int ch;
	char choice;
	do
	{
		cout<<"\n Choose from the following. \n 1. Insert at front \n 2. Insert at rear \n 3. Delete from front \n 4. Delete from rear \n\n Enter your choice: ";
		cin>>ch;
		switch (ch)
		{
			case 1: q1.insertfront();
					cout<<"\n The queue is as follows. \n";
					q1.display();
					break;
			case 2: q1.insertrear();
					cout<<"\n The queue is as follows. \n";
					q1.display();
					break;
			case 3: q1.delfront();
					cout<<"\n The queue is as follows. \n";
					q1.display();
					break;
			case 4: q1.delrear();
					cout<<"\n The queue is as follows. \n";
					q1.display();
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
