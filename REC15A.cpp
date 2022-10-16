#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		ll a[n];
		ll o = 0, e = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % 2 == 0) ++e;
			else ++o;
		}
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (e == 0) {
			cout << n << endl;
			continue;
		}		
		if (o == 0) {
			cout << n << endl;
			continue;
		}

		cout << min(o + 2 * (e - 1), e + 2 * (o - 1)) << endl;
			
	}
	return 0;
}
