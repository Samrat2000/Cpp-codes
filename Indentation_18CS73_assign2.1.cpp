#include <iostream>
#include <string>

using namespace std;


//to repeat tabs
string repeat(string s,int n)
{
	string s1 = s ;
	for (int i=1; i<n; i++)
	{
		s += s1;
	}
	return s;
}
void indent()
{
	string code[100];
	string tab="  ";
	int tab_var =0;
	cout << "Type 'quit' and enter when you finished entering the code : " << endl ;
	cout << "Enter the cpp code : " << endl;
	
	int i=1;
	cin >> code[0];
	//user input
	while(code[i-1]!="quit" && i<100)
	{
		cin >> code[i++];
	}
	int j=0;
	
	
	//functional loop
	while(j<i)
	{
		if(code[j][0] == '}')
			tab_var -= 1;
		cout << (repeat(tab,tab_var) + code[j])<< endl ;
		if(code[j][0] == '{')
			tab_var += 1;
		j++;
	}
}

int main(void)
{
	cout << endl ;
	indent();
	return 0;
}
