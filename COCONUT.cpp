#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int xa, xb, ya, yb;
		cin >> xa >> xb >> ya >> yb;
		cout << (ya/xa + yb/xb) << "\n";
	}
}
