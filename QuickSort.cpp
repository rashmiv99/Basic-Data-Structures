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
			cout<<"\n Enter the percentage of the students below.";
			for(int i=0; i<n; i++)
			{
				cout<<"\n Student "<<(i+1)<<": ";
				cin>>a[i];
			}
		}
		void display()
		{
			cout<<"\n The marks are as follows: ";
			for(int i=0; i<n; i++)
			{
				cout<<" "<<a[i];
			}
			cout<<endl;
		}
		int partition(int lb, int ub)
		{
			float p=a[lb];
			int down=lb;
			int up=ub;
			float temp;
			while(down<up)
			{
				while(a[down]<=p)
				{
					down++;
				}
				while(a[up]>p)
				{
					up--;
				}
				if(down<up)
				{
					temp=a[down];
					a[down]=a[up];
					a[up]=temp;
				}
			}
			a[lb]=a[up];
			a[up]=p;
			return up;
		}
		void quicksort(int lb, int ub)
		{
			int j;
			if(lb<ub)
			{
				j=partition(lb,ub);
				quicksort(lb,j-1);
				quicksort(j+1,ub);
			}
		}
		int getn()
		{
			return n;
		}
};

int main()
{
	Student s;
	s.accept();
	cout<<"\n Before sorting: ";
	s.display();
	cout<<"\n After sorting: ";
	int l=s.getn();
	s.quicksort(0,l-1);
	s.display();
	return 0;
}
