#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x, r, m;
		cin >> x >> r >> m;
		if(r>m){
			cout << "NO\n";
			continue;
		}
		int res = x - 60 * r + 60 * (m-r);
		if(res >= 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
