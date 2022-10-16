#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,y,x;
		cin >> a >> y >> x;
		int res = 0;
		if(y>a) {
			res = 1 + a * x;
		}
		else{
			res = a * x - (a-y)*x;
		}
		cout << res << "\n";
	}
}
