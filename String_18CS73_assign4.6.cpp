#include <iostream>

using namespace std;

class String
{
	private :
		// data members
		char* s;
		int string_len;
		int len;
		
	public:
		//Constructor1
		String()
		{
			s= new char;
			*s='\0';
			string_len=1;
			len =0;
		}
		
		//Constructor2
		String(char * str, int str_len)
		{
			s=new char[str_len];
			for(int i=0;i<str_len; i++)
				s[i]=str[i];
			string_len=str_len;
			int i=0;
			while(s[i]!='\0')
				i++;
			len=i;
		}
		
		//Destructor
		~String()
		{
			delete []s;
		}
		
		
		void print();
		int length();
		void concat(String &b);
		char charAt(int i);
		String* substring(int i , int j);
		
};

//for finding length of the string
int String :: length()
{
	return len;
}

//concatenation of 2 strings
void String :: concat(String &b)
{
	int new_len = len + b.length();
	char * ns=new char[new_len+1];
	for(int i=0;i<len;i++)
		ns[i]=s[i];
		
	for(int i=len;i<new_len;i++)
		ns[i]=b.s[i-len];
	ns[new_len]='\0';
	delete []s;
	s=ns;
	len=new_len;
	string_len= new_len+1;
	
}

//finding character at i-th position
char String::charAt(int i)
{
	return s[i];
}

//for getting substring from index i to j,i inclusive, j not inclusive
String* String::substring(int i, int j)
{
	char* c=new char[j-i+1];
	for(int k=i; k<j;k++)
		c[k-i]=s[k];
	c[j-i]='\0';
	String* l= new String(c,j-i+1);
	return l;
  }  
  
//printing the string
void String:: print()
{
	cout<<s<<endl;
}


int main(void)
{
	int f, ch;
	while(1)
	{
		cout<<"\nMain menu\n0. Exit\n1.get length\n2. get character at given index\n3.concate two strings\n4. Get substring";
		cout<<"\nEnter your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				{
					char str[100];
					cout<<"enter a string : ";
					cin>>ws;
					cin.getline(str,100);
					String S(str,100);
					//S.print();
					cout<<endl;
					cout<<"Length of string:"<<S.length()<<endl;
				}
				break;
			case 2:
				{
				char str[1000];
				cout<<"Enter a string:"<<endl;
				cin>>ws;
				cin.getline(str,1000);
				String S(str,1000);
				cout<<"Enter a index to get character at:"<<endl;
				char a;
				int i;
				cin>>i;
				if(i>=0 && i<S.length())
				{
						a=S.charAt(i);
						cout<<"The character at index"<<i<<" is "<<a<<endl;
				}
				else
				{
						cout<<"Error: invalid index."<<endl;
				}
				}
				break;
			case 3:
				{
				char str1[1000],str2[1000];
				cout<<"Enter the first string:"<<endl;
				cin>>ws;
				cin.getline(str1,1000);
				String S1(str1,1000);
				cout<<"Enter the second string:"<<endl;
				cin>>ws;
				cin.getline(str2,1000);
				String S2(str2,1000);
				cout<<"First string :";
				S1.print();
				cout<<endl;
				cout<<"Second string :";
				S2.print();
				cout<<endl;
				cout<<"Results:"<<endl;
				S1.concat(S2);
				S1.print();
				cout<<endl;
				}
				break;
			case 4:
				{
				char str[1000];
				cout<<"Enter a string :"<<endl;
				cin>>ws;
				cin.getline(str,1000);
				String S(str,1000);
				int i,j;
				cout<<"Enter a starting and ending index"<<endl;
				cin>>i>>j;
				if(i>=0 && j>=0 && i<S.length() && j<S.length())
				{
					String*S1=S.substring(i,j);
					cout<<"Substring is:"<<endl;
					S1->print();
					cout<<endl;
				}
				else
				{
					cout<<"Error: invalid index"<<endl;
				}
				}
				break;
			default:
					cout<<"Sorry no such choice available."<<endl;
		}	
	}
	return 0;
}
