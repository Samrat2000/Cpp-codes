#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		int count = 0, i;
		int attend = 90;
		//cout << attend << "  XX \n";
		for(i = 0; i<n; i++){
			if(str[i]=='1') count++;
		}
		if(120-n+count>=90) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
