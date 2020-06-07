#include <iostream>
#include <cstring>
using namespace std;

class Student
{
	char name[50];
	int rollno;
	bool present;
	float marks;
	public:
		int getrollno()
		{
			return rollno;
		}
		bool getpresent()
		{
			if(present)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		float getmarks()
		{
			return marks;
		}
		void accept()
		{
			char ch;
			cout<<"\n Enter the name of the student: ";
			cin.ignore();
			cin.getline(name,50);
			cout<<" Enter the roll number: ";
			cin>>rollno;
			cout<<" Present? (y/n): ";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<" Enter the marks: ";
				cin>>marks;
				present=true;
			}
			else
			{
				marks=0;
				present=false;
			}
		}
};

void aveg (int n, Student s[100])
{
	float sum=0;
	float avrg=0;
	for(int i=0; i<n; i++)
	{
		sum+=s[i].getmarks();
	}
	avrg=(sum/n);
	cout<<"\n The average of the class is: "<<avrg;
}

void hilo (int n, Student s[100])
{
	float high = s[0].getmarks();
	float low = s[0].getmarks();
	for(int i=1; i<n; i++)
	{
		if(s[i].getmarks()>high)
		{
			high=s[i].getmarks();
		}
		if (s[i].getmarks()<low)
		{
			low=s[i].getmarks();
		}
	}
	cout<<"\n The highest marks scored is "<<high<<" and the lowest is "<<low;
}

void mode (int n, Student s[100])
{
	int count=0;
	int c=0;
	float marks=0;
	for (int i=0; i<n; i++)
	{
		count=0;
		for (int j=0; j<n; j++)
		{
			if(s[i].getmarks()==s[j].getmarks())
			{
				count++;
				if(c<count)
				{
					marks=s[i].getmarks();
					c=count;
				}
			}
		}
	}
	cout<<"\n The marks scored the most is: "<<marks;
}

void abs (int n, Student s[100])
{
	for(int i=0; i<n; i++)
	{
		if (!(s[i].getpresent()))
		{
			cout<<"\n The absent students are: "<<s[i].getrollno()<<", ";
		}
	}
}

int main()
{
	int n,choice;
	char ch;
	Student s[100];
	cout<<"\n Enter the number of students you'd like to enter: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		s[i].accept();
	}
	do
	{
		cout<<"\n Choose from the following. \n 1. Average of the class \n 2. Highest and lowest mark of the class \n 3. Mark scored the most \n 4. Absent students \n\n Enter your choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1: aveg(n,s);
					break;
			case 2: hilo(n,s);
					break;
			case 3: mode(n,s);
					break;
			case 4: abs(n,s);
					break;
			default: cout<<"\n Wrong choice.";
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	return 0;
}
