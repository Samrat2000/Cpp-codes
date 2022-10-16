#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int zc = 0, oc = 0;
		int i = 0;
		for(; i<str.length(); i++)
		{
			if(str[i] == '0') zc++;
			else{
				oc++;
			}
			if(ceil((i+1)/2.0) <= oc){
				cout << "YES\n";
				break;
			}
		}
		if( i == n) cout << "NO\n";
	}
}
