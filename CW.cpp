#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		vector<char> v;
		for(int i = 0; i<s.length(); i++){
			if(count(v.begin(), v.end(), s[i]) == 0) v.push_back(s[i]);
		}
		for(int i = 0; i<v.size(); i++){
			cout << v[i];
		}
		cout << "\n";
	}
}
