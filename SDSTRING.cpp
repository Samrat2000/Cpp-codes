#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cz = 0, co = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i] == '0') cz++;
			else co++;
		}
		if(cz==0||co==0){
			cout << -1 << endl;
			continue;
		}
		if(cz==co) cout << 0 << endl;
		else if((cz-co)%2==0) cout << abs((cz-co)/2) << endl;
		else cout << -1 << endl;
	}
	return 0;
}
