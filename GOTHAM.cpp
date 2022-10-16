#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n ; i++) cin >> A[i];
	int q;
	cin >> q;
	while(q--){
		int x, k;
		cin >> x >> k;
		int dist = 0;
		int dc = 0;
		while(k > 0 && x <= n){
			if(k <= A[x-1]){
				A[x-1] -= k;
				dist += (k*dc);
				k = 0;
			}
			else{
				k -= A[x-1];
				dist += (A[x-1]*dc);
				A[x-1] = 0;
			}
			x++; dc++;
		}
		cout << dist << "\n";
	}
}
