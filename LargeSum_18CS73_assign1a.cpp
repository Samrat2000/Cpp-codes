//header files
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string add(string a,string b)
{
	// making a smaller than b
	if(a.length() > b.length())
		swap(a,b);
	string sum = "";
	
	//reversing the number
	reverse(a.begin() , a.end());
	reverse(b.begin() , b.end());
	int carry = 0;
	for (int i=0;i<a.length();i++)
	{
		//calculating sum at each position
		int s = (a[i] - '0') + (b[i] - '0') + carry;
		sum.push_back(s%10 + '0');
		carry = s/10;
	}
	for (int i=a.length();i<b.length();i++)
	{
		//if any digits of larger number left to add
		int s = (b[i] - '0') + carry;
		sum.push_back(s%10 + '0');
		carry = s/10;
	}
	if(carry != 0)
		sum.push_back(carry + '0');
		
	//again reversing back to same
	reverse(sum.begin(),sum.end());
	return sum ;
}

int main()
{
	string s1,s2;
	cout<< "Large number Addition" << endl << "Enter first number: " ;
	cin >> s1;
	cout << "Enter second number : ";
	cin >> s2;
	cout << "Sum = " << add(s1,s2) << endl;
}
