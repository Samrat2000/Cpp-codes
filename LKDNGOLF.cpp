#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, x, k;
		cin >> n >> x >> k;
		if(x % k == 0 || (n+1-x) % k == 0) cout << "yes\n";
		else cout << "no\n";
	}
}
