#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int h, x, y, c;
		cin >> h >> x >> y >> c;
		int k = h * (x + y/2);
		if(k > c) cout << "No\n";
		else cout << "Yes\n";
	}
}
