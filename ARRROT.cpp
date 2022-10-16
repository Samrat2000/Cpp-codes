#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int n;
	cin >> n;
	int k;
	int sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> k;
		sum += k;
		sum = sum % 1000000007;
	}
	
	int q;
	cin >> q;
	for(int i = 0; i<q; i++){
		cin >> k;
	}
	for(int i = 0; i<q; i++){
		sum = sum + sum;
		sum = sum % 1000000007;
		cout << sum << "\n";
	}
}
