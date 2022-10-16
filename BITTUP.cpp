#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int getpow(int a, int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	
	if(b%2 == 0){
		int ans = getpow(a, b/2);
		return (ans*ans)%MOD;
	}
	else{
		int ans = getpow(a, b/2);
		return ((a*ans)%MOD*ans)%MOD;
	}
}

signed main()
{
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int k = getpow(2,n)-1;
		int res = getpow(k,m);
		cout << res << "\n";
	}
}
