#include <iostream>
using namespace std;

class String
{
	char str[100];
	int len;
	public:
		String()
		{
			len=0;
		}
		void accept()
		{
			cout<<"\n Enter a string: ";
			cin>>str;
			len = calclen();        //DONT FORGET!
		}
		void display()
		{
			cout<<"\n The string is: "<<str<<"\n The length is: "<<len<<endl;
		}
		int calclen()
		{
			int count=0;
			for(int i=0; str[i]!='\0'; i++)
			{
				count++;
			}
			return count;
		}
		void concat(String s1)
		{
			int c=0;
			for(int i=0; i<s1.len; i++)
			{
				str[len+i]=s1.str[i];
				c++;
			}
			len=len+c;
			str[len]='\0';
		}
		void copy(String s1)
		{
			len=s1.len;
			for(int i=0; i<len; i++)
			{
				str[i]=s1.str[i];
			}
			str[len]='\0';
		}
		void reverse()
		{
			for(int i=0; i<(len/2); i++)
			{
				char temp;
				temp = str[i];
				str[i] = str[len-i-1];
				str[len-i-1] = temp;
			}
		}
		void charfreq(char c)
		{
			int count=0;
			for(int i=0; i<len; i++)
			{
				if(str[i]==c)
				{
					count++;
				}
			}
			cout<<"\n The frequency of the character entered is: "<<count<<endl;
		}
		void delchar(char c)
		{
			for(int i=0; i<len; i++)
			{
				if(str[i]==c)
				{
					for(int j=(i+1); j<len; j++)
					{
						str[j-1]=str[j];
					}
					len--;
					i--;
				}
			}
			str[len]='\0';
		}
		void equal(String s1)
		{
			int flag=1;
			if(len==s1.len)
			{
				for(int i=0; i<len; i++)
				{
					if(str[i]!=s1.str[i])
					{
						flag = 0;
						break;
					}
				}
			}
			else
			{
				flag = 0;
			}
			if(flag==1)
			{
				cout<<"\n The strings are equal."<<endl;
			}
			else
			{
				cout<<"\n The strings are not equal."<<endl;
			}
		}
		void palindrome()
		{
			int flag=1;
			for(int i=0; i<(len/2); i++)
			{
				if(str[i]!=str[len-i-1])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"\n The entered string is a palindrome."<<endl;
			}
			else
			{
				cout<<"\n The entered string is not a palindrome."<<endl;
			}
		}
		void checksub(String s1)
		{
			int flag = 0;
			for(int i=0; i<len; i++)
			{
				if((str[i]==s1.str[0]) && ((i+s1.len)<=len))
				{
					flag=1;                     //needs to change each time, otherwise flag remains 0
					for(int j=0; j<s1.len; j++)
					{
						if(s1.str[j]!=str[i+j])
						{
							flag=0;
						}
					}
				}
			}
			if(flag==1)
			{
				cout<<"\n The entered string is a substring."<<endl;
			}
			else
			{
				cout<<"\n The entered string is not a substring."<<endl;
			}
		}
		void replacesub(String s1, String s2)   //s1 is the substring to be replaced, s2 is the string in its place
		{
			int flag=0;
			int i=0;
			for(i=0; i<len; i++)
			{
				if((str[i]==s1.str[0]) && (i+s1.len<=len))
				{
					flag=1;
					for(int j=0; j<s1.len; j++)
					{
						if(s1.str[j]!=str[i+j])
						{
							flag=0;
						}
					}
					if(flag==1)
					{
						int extra=(s2.len)-(s1.len);
						len=len+extra;
						if(extra>0)
						{
							for(int j=(len-1); j>=i; j--)
							{
								str[j+extra]=str[j];
							}
						}
						else
						{
							for(int j=(i-extra); j<len; j++)
							{
								str[j+extra]=str[j];
							}
						}
						for(int j=0; j<s2.len; j++)
						{
							str[i+j]=s2.str[j];
						}
						len=len+extra;
						str[len]='\0';
					}
				}
			}
		}
		void delsub(String s, int start, int length)
		{
			int j=0;
			for(int i=0; i<s.len; i++)
			{
				if(i<(start-1)||i>(start+length-2))
				{
					str[j]=s.str[i];
					j++;
				}
			}
			str[j]='\0';
			len=j;
		}
};

int main()
{
	String s,s1,s2;
	char c, ch;
	int choice,start,length;
	do
	{
		cout<<"\n Choose from the following. \n 1. Calculate length of string. \n 2. Concatenate two strings. \n 3. Copy one string to another string. \n 4. Reverse an entered string \n 5. Calculate the frequency of a particular character. \n 6. Delete all occurances of a particular character. \n 7. Check if two strings are equal. \n 8. Check if an entered string is a palindrome. \n 9. Check if an entered string is a substring of a main string. \n 10. Replace an entered substring with another string in a given main string. \n 11. Delete the part of the main string with start and length values. \n\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: s.accept();   //everytime accept is called, len() is also called.
					s.display();
					break;
			case 2: s.accept();
					s1.accept();
					s.concat(s1);
					s.display();
					break;
			case 3: s.accept();
					s1.accept();
					s.copy(s1);
					s.display();
					break;
			case 4: s.accept();
					s.reverse();
					s.display();
					break;
			case 5: s.accept();
					cout<<"\n Enter the character: ";
					cin>>c;
					s.charfreq(c);
					break;
			case 6: s.accept();
					cout<<"\n Enter the character: ";
					cin>>c;
					s.delchar(c);
					s.display();
					break;
			case 7: s.accept();
					s1.accept();
					s.equal(s1);
					break;
			case 8: s.accept();
					s.palindrome();
					break;
			case 9: s.accept();
					s1.accept();
					s.checksub(s1);
					break;
			case 10: s.accept();
					 s1.accept();
					 s2.accept();
					 s.replacesub(s1,s2);
					 s.display();
					 break;
			case 11: s.accept();
					 cout<<"\n Enter the start position: ";
					 cin>>start;
					 cout<<"\n Enter the length: ";
					 cin>>length;
					 s1.delsub(s,start,length);
					 s1.display();
					 break;
			default: cout<<"\n Wrong choice.";
					 break;
		}
		cout<<"\n Do you want to continue? (y/n): ";
		cin>>ch;
	}
	while (ch=='y'||ch=='Y');
	return 0;
}
