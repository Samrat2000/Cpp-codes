/*1
100111011010111*/
#include <bits/stdc++.h>

using namespace std;

int countOne(string str)
{
	int c = 0;
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i]=='1') c++;
	}
	if(c%2 == 0) return 1;
	else return 0;
}

string rev(string str){
	reverse(str.begin(), str.end());
	return str;
}

int equivalent(string a, string b)
{
	if(a.length() <= 2 || b.length() <= 2) return 0;
	if(countOne(a) && countOne(b) && a == rev(b)) return 1;
	else{
		if((a[a.length()-1] == b[b.length()-1] && equivalent(a.substr(0,a.length()-1), b.substr(0,b.length()-1)))||
		(a[0] == b[0] && equivalent(a.substr(1,a.length()-1), b.substr(1,b.length()-1)))) return 1;
	}
	return 0;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << equivalent(str1, str2) << endl;
}
