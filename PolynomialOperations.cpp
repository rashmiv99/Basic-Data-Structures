#include <iostream>
using namespace std;

int power(float x, int r)
{
	int prod=1;
	for (int i=0; i<r; i++)
	{
		prod*=x;
	}
	return prod;
}

class Polynomial;
class Term
{
	float c;
	int e;
	public:
		Term()
		{
			c=0;
			e=0;
		}
		Term(float coeff, int expo)
		{
			c=coeff;
			e=expo;
		}
		friend class Polynomial;
		friend void operator<<(ostream &out, Polynomial &p);   //if there is &operator, then it should have a return type.
		friend void operator>>(istream &in, Polynomial &p);
};

class Polynomial
{
	Term *t;        //dynamically initialised
	int n;
	public:
		Polynomial()
		{
			t= new Term[100];
			n=0;
		}
		void sortshift()
		{
			for(int i=0; i<n; i++)    //selection sort
			{
				for(int j=(i+1); j<n; j++)
				{
					if((t[j].e)<(t[i].e))
					{
						Term temp(t[j].c,t[j].e);
						t[j]=t[i];
						t[i]=temp;
					}
				}
			}
			for(int i=0; i<n-1; i++)     //i<n-1 REMEMBER why? checking two consecutive elements, so it cant check an element after end
			{
				if((t[i].e)==(t[i+1].e))
				{
					t[i].c+=t[i+1].c;
					for(int j=(i+2); j<n; j++)
					{
						t[j-1]=t[j];
					}
					n--;     //no. of elements reduce
					i--;    //index reduces
				}
			}
			for(int i=0; i<n; i++)
			{
				if(t[i].c==0)
				{
					for(int j=(i+1); j<n; j++)
					{
						t[j-1]=t[j];
					}
					n--;
					i--;
				}
			}
		}
		void add (Polynomial p1, Polynomial p2)
		{
			Polynomial sum;
			int i=0;
			int j=0;
			int k=0;
			while (i<p1.n && j<p2.n)        //1st while loop
			{
				if((p1.t[i].e)==(p2.t[j].e))
				{
					sum.t[k].c=(p1.t[i].c)+(p2.t[j].c);
					sum.t[k].e=p1.t[i].e;
					i++;
					j++;
					k++;
				}
				else
				{
					if((p1.t[i].e)>(p2.t[j].e))
					{
						sum.t[k].c=p1.t[i].c;
						sum.t[k].e=p1.t[i].e;
						k++;
						i++;
					}
					else
					{
						sum.t[k].c=p2.t[j].c;
						sum.t[k].e=p2.t[j].e;
						k++;
						j++;
					}
				}
			}
			while(i<p1.n)          //2nd while loop
			{
				sum.t[k].c=p1.t[i].c;
				sum.t[k].e=p1.t[i].e;
				k++;
				i++;	
			}
			while(j<p2.n)      //3rd while loop
			{
				sum.t[k].c=p2.t[j].c;
				sum.t[k].e=p2.t[j].e;
				k++;
				j++;
			}
			sum.n=k;
			sortshift();
			cout<<"\n The sum of the polynomials is: ";
			cout<<sum;
		}
		void multiply(Polynomial p1, Polynomial p2)
		{
			Polynomial mul;
			int k=0;
			for(int i=0; i<p1.n; i++)
			{
				for(int j=0; j<p2.n; j++)
				{
					mul.t[k].c=(p1.t[i].c)*(p2.t[j].c);   //multiply coeffs, add expos
					mul.t[k].e=(p1.t[i].e)+(p2.t[j].e);
					k++;
				}
			}
			mul.n=k;
			mul.sortshift();
			cout<<"\n The product of the polynomials is: "<<mul;
		}
		void evaluate(float val)
		{
			float ans;
			for(int i=0; i<n; i++)
			{
				ans+=(t[i].c)*power(val, t[i].e);
			}
			cout<<"\n The value of the expression is: "<<ans;
		}
		friend void operator<<(ostream &out, Polynomial &p);
		friend void operator>>(istream &in, Polynomial &p);
};

void operator<<(ostream &out, Polynomial &p)
{
	for(int i=0; i<p.n; i++)
	{
		out<<p.t[i].c<<"x^"<<p.t[i].e;
		if(i!=((p.n)-1))
		{
			out<<" + ";
		}
	}
}

void operator>>(istream &in, Polynomial &p)
{
	cout<<"\n Enter the number of terms: ";
	in>>p.n;
	p.t=new Term[p.n];
	for(int i=0; i<p.n; i++)
	{
		cout<<"\n Term "<<(i+1)<<": ";
		cout<<"\n Enter the coefficient: ";
		in>>p.t[i].c;
		cout<<"\n Enter the exponent: ";
		in>>p.t[i].e;
	}
	p.sortshift();
}

int main()
{
	int ch;
	char choice;
	float val;
	Polynomial p, p1, result;
	do
	{
		cout<<"\n Choose from the following. \n 1. Addition \n 2. Multiplication \n 3. Evaluation \n\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Enter the first polynomial: ";
					cin>>p;
					cout<<"\n Enter the second polynomial: ";
					cin>>p1;
					result.add(p,p1);
					break;
			case 2: cout<<"\n Enter the first polynomial: ";
					cin>>p;
					cout<<"\n Enter the second polynomial: ";
					cin>>p1;
					result.multiply(p,p1);
					break;
			case 3: cout<<"\n Enter the polynomial: ";
					cin>>p;
					cout<<"\n Enter the value of x: ";
					cin>>val;
					p.evaluate(val);
					break;
			default: cout<<"\n Wrong choice."<<endl;
					 break;
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>choice;
	}
	while(choice=='y'||choice=='Y');
	return 0;
}
