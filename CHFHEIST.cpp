#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int D, d, P, Q;
		cin >> D >> d >> P >> Q;
		int n = D/d;
		int a = n*(2*P+(n-1)*Q)/2;
		int k = D-n*d;
		int b = P + n*Q;
		cout << (a*d+k*b) << "\n";
	}
}
