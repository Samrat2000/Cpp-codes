#include <bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a>> b;
		if(gcd(a,b) == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}
