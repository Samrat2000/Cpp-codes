#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll f = 0, s = 1;
		if(n == 1) {
			cout << f << endl;
			continue;
		}
		if(n == 2){
			cout << f << endl;
			cout << f << s << endl;
			continue;
		}
		cout << f << endl;
		cout << f << s << endl;
		for(int i = 3; i<=n; i++){
			cout << f << s;
			for(int j = 3; j<=i; j++){
				ll t = (f+s);
				cout << t;
				f = s;
				s = t;
			}
			f = 0;
			s = 1;
			cout << endl;
		}
	}
	return 0;
}
