#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> A;
		vector<int> B;
		int k;
		int maxA, maxB, minA, minB;
		for(int i = 0; i < n; i++)
		{
			cin >> k;
			A.push_back(k);
		}
		sort(A.begin(), A.end());
		for(int i = 0; i < n; i++)
		{
			cin >> k;
			B.push_back(k);
		}
		sort(B.begin(), B.end());
		int res = A[0]+B[n-1];
		for(int i = 1; i<n; i++){
			int c = A[i] + B[n-1-i];
			res = max(res, c);
		}
		cout << res << "\n";
	}
}
