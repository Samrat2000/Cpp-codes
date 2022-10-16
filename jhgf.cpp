#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		int count = 0, i = 0;
		for(; i<n; i++){
			if(str[i] == '*') count++;
			else if(str[i] != '*' && count >= k){
				cout << "YES\n";
				count = 0;
				break;
			}
			else count = 0;
		}
		
		if(i!=n) continue;
		
		if(count >= k) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
