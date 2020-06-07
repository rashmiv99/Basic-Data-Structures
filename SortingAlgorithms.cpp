#include <iostream>
using namespace std;

class Student
{
	float a[100];
	int n;
	public:
		void accept()
		{
			cout<<"\n Enter the number of students: ";
			cin>>n;
			cout<<"\n Enter the percentage of students below.";
			for(int i=0; i<n; i++)
			{
				cout<<"\n Student "<<(i+1)<<": ";
				cin>>a[i];
			}
		}
		void display()
		{
			cout<<"\n The percentages are below.";
			for(int i=0; i<n; i++)
			{
				cout<<" "<<a[i];
			}
		}
		void selsort()
		{
			for(int i=0; i<n; i++)
			{
				for(int j=(i+1); j<n; j++)
				{
					if(a[j]<a[i])
					{
						float temp;
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
				}
			}
		}
		void bubsort()
		{
			int pass=1;
			for(int i=0; i<n; i++)
			{
				for (int j=0; j<(n-pass); j++)
				{
					if(a[j+1]<a[j])
					{
						float temp;
						temp = a[j+1];
						a[j+1]=a[j];
						a[j]=temp;
					}
				}
				pass++;
			}
		}
		void inssort()
		{
			int i,j;
			for(i=0; i<n; i++)
			{
				j=i;
				while(j>0 && a[j]<a[j-1])
				{
					float temp;
					temp = a[j-1];
					a[j-1]=a[j];
					a[j]=temp;
					j--;         //it's a while loop dont forget!
				}
			}
		}
		void shellsort()
		{
			float temp;
			int i,j;
			int gap;
			for(gap=(n/2); gap>0; gap=gap/2)
			{
				for(i=gap; i<n; i++)
				{
					temp=a[i];
					for(j=i; j>=gap && a[j-gap]>temp; j=j-gap)
					{
						a[j]=a[j-gap];
					}
					a[j]=temp;
				}
			}
		}
};

int main()
{
	Student s;
	int choice;
	char ch;
	do
	{
		cout<<"\n Choose from the following. \n 1. Selection Sort \n 2. Bubble Sort \n 3. Insertion Sort \n 4. Shell Sort \n\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: s.accept();
					cout<<"\n Before sorting:- ";
					s.display();
					cout<<"\n After sorting:- ";
					s.selsort();
					s.display();
					break;
			case 2: s.accept();
					cout<<"\n Before sorting:- ";
					s.display();
					cout<<"\n After sorting:- ";
					s.bubsort();
					s.display();
					break;
			case 3: s.accept();
					cout<<"\n Before sorting:- ";
					s.display();
					cout<<"\n After sorting:- ";
					s.inssort();
					s.display();
					break;
			case 4: s.accept();
					cout<<"\n Before sorting:- ";
					s.display();
					cout<<"\n After sorting:- ";
					s.shellsort();
					s.display();
					break;
			default: cout<<"\n Wrong choice.";
					 break;
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>ch;			
	}
	while(ch=='y'||ch=='Y');
	return 0;
}		
