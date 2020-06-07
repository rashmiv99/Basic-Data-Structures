#include <iostream>
using namespace std;

class Array
{
	int a[100];
	int n;
	public:
		void accept()
		{
			cout<<"\n Enter the number of students: ";
			cin>>n;
			cout<<"\n Enter the roll numbers below. \n";
			for(int i=0; i<n; i++)
			{
				cout<<"\n Roll number "<<(i+1)<<": ";
				cin>>a[i];
			}
		}
		void sort()
		{
			for(int i=0; i<n; i++)
			{
				for(int j=(i+1); j<n; j++)
				{
					if(a[j]<a[i])
					{
						int temp;
						temp = a[j];
						a[j]=a[i];
						a[i]=temp;
					}
				}
			}
		}
		void display()
		{
			cout<<"\n The roll numbers are as follows. \n";
			for(int i=0; i<n; i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		void linsearch(int key)
		{
			int flag=0;
			for (int i=0; i<n; i++)
			{
				if(a[i]==key)
				{
					cout<<"\n Student found at "<<(i+1)<<endl;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\n Student was not found."<<endl;
			}
		}
		void sentsearch(int key)
		{
			int last = a[n-1];
			a[n-1] = key;
			int i=0;
			while (a[i]!=key)
			{
				i++;
			}
			a[n-1]=last;
			if((i<(n-1))||(key==a[n-1]))
			{
				cout<<"\n Student found at "<<(i+1)<<endl;
			}
			else
			{
				cout<<"\n Student was not found."<<endl;
			}
		}
		void binsearch(int key)
		{
			sort();
			int high, low, mid;
			int flag=0;
			high = (n-1);
			low = 0;
			if(high==low)
			{
				if(a[high]==key)
				{
					flag = 1;
				}
			}
			else
			{
				while (low<=high)
				{
					mid=(low+high)/2;
					if(a[mid]==key)
					{
						flag=1;
						break;
					}
					else if(key>a[mid])
					{
						low = mid+1;
					}
					else if(key<a[mid])
					{
						high = mid-1;
					}
				}
			}
			if(flag==1)
			{
				cout<<"\n Student is found."<<endl;
			}
			else
			{
				cout<<"\n Student was not found."<<endl;
			}
		}
		void fibsearch(int key)
		{
			sort();
			int m=1;
			int m1=1;
			int m2=0;
			do
			{
				m+=m1;
				m1+=m2;
				m2=(m-m1);
			}
			while(m<n);
			int offset=-1;
			int flag=0;
			int temp;
			while (m2>=0)
			{
				if((m2+offset)>(n-1))
				{
					temp=(n-1);
				}
				else if((m2+offset)<(n-1))
				{
					temp=(m2+offset);
				}
				else
				{
					temp=(n-1);
				}
				if(key<a[temp])      //then shift it down by 2
				{
					m-=m1;
					m1-=m2;
					m2=(m-m1);
				}
				else if(key>a[temp])   //shift it down by 1 and change offset
				{
					m=m1;
					m1=m2;
					m2=(m-m1);
					offset = temp;
				}
				else if(key==a[temp])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"\n Student is found."<<endl;
			}
			else
			{
				cout<<"\n Student was not found."<<endl;
			}
		}
};

int main()
{
	Array a;
	int key=0;
	int ch;
	char choice;
	do
	{
		cout<<"\n Choose from the following. \n 1. Linear Search \n 2. Sentinel Search \n 3. Binary Search \n 4. Fibonacci Search \n\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: a.accept();
					cout<<"\n Enter the roll number to be searched: ";
					cin>>key;
					a.linsearch(key);
					break;
			case 2: a.accept();
					cout<<"\n Enter the roll number to be searched: ";
					cin>>key;
					a.sentsearch(key);
					break;
			case 3: a.accept();
					cout<<"\n Enter the roll number to be searched: ";
					cin>>key;
					a.binsearch(key);
					break;
			case 4: a.accept();
					cout<<"\n Enter the roll number to be searched: ";
					cin>>key;
					a.fibsearch(key);
					break;
			default: cout<<"\n Wrong choice.";
					 break;
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>choice;
	}
	while (choice=='y'||choice=='Y');
	return 0;
}
