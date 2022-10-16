#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int n, t;
	cin >> n >> t;
	int sum = 0;
	int arr[n];
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int res = 0;
	if(sum <= t) res = n * (t/sum);
	int k = t%sum;
	for(int i = 0; i<n; i++){
		if(arr[i] <= k){
			res++;
			k -= arr[i];
		}
		if(k == 0) break;
	}
	cout << res << "\n";
}
