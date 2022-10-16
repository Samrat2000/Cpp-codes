// My name is 123Samrat
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the string :";
	char s[100];
	cin >> s;
	
	for(int i = 0; s[i] ; i++)
	{
		cout << s[i] << endl;
		if((s[i]-'0')>=0 && (s[i]-'0')<=9) {
			cout << "String contains number!";
			break;
		}
	}
	cout << "String does not contain number.";
}
