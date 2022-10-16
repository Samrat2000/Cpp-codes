#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int count = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='1' && ((i+1)==s.length() || s[i+1]=='0')) count++;
		}
		cout << count << "\n";
	}
	return 0;
}
