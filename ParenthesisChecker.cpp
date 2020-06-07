#include <iostream>
using namespace std;

class Stack;
class Node
{
	char val;
	Node *next;
	public:
		Node()
		{
			val='x';
			next=NULL;
		}
		friend class Stack;
};

class Stack
{
	Node *top;
	public:
		Stack()
		{
			top=NULL;
		}
		bool isempty()
		{
			if(top==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void push(char c)
		{
			if(isempty())
			{
				Node *new1;
				new1= new Node;
				new1->val=c;
				new1->next=NULL;
				top=new1;
			}
			else
			{
				Node *new1;
				new1 = new Node;
				new1->val=c;
				new1->next=top;
				top=new1;
			}
			cout<<"\n Pushed.";
		}
		void pop()
		{
			if(!isempty())
			{
				Node *t;
				t=new Node;
				t=top->next;
				delete top;
				top->next=NULL;
				top=t;
				cout<<"\n Popped.";
			}
			else
			{
				cout<<"\n Stack is empty.";
			}
		}
		void display()
		{
			Node *t;
			t=new Node;
			t=top;
			while(t)
			{
				cout<<" "<<t->val;
				t=t->next;
			}
		}
		char peek()
		{
			if(!isempty())
			{
				return (top->val);
			}
			else
			{
				return 0;
			}
		}
};

int main()
{
	string exp;
	Stack ob;
	int flag=1;
	cout<<"\n Enter the expression to be checked: ";
	cin>>exp;
	for(int i=0; exp[i]!='\0'; i++)
	{
		if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
		{
			ob.push(exp[i]);
		}
		else
		{
			if(exp[i]=='}'&&ob.peek()=='{' || exp[i]==')'&&ob.peek()=='(' || exp[i]==']'&&ob.peek()=='[')
			{
				ob.pop();
			}
			else if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
			{
				flag=0;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	if(flag==1 && ob.peek()==0)
	{
		cout<<"\n The expression is well parenthesized."<<endl;
	}
	else
	{
		cout<<"\n The expression is not well parenthesized."<<endl;
	}
	return 0;
}
		
