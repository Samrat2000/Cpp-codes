#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Enter string : ";
	getline(cin, str);
	char c;
	cout << "Enter the fillchar of pattern : ";
	cin >> c;
	int len=str.length();
	cout << setw(len) << setfill(' ') << ' '<< str[0] << endl ;
	for (int i = 1 ; i < len ; i++)
	{
		cout << setw(len-i) << setfill(' ') << ' '<< str[i] << setw(2*i-1) << setfill(c) << c << str[i] << endl ;
	}
}
