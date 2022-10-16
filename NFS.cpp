#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int u,v,a,s;
		cin >> u >> v >> a >> s;
		double res = sqrt(u*u - 2 * a * s);
		if(res > v) cout << "No\n";
		else cout << "Yes\n";
	}
}
