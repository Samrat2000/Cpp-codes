#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m, n;
		cin >> m >> n;
		int res = (m*(m-1)/2)*n + (n*(n-1)/2)*m;
		cout << res << "\n";
	}
}
