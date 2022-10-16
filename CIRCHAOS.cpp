#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll maxfact(ll g, ll n)
{
	ll res = 0;
	for(ll i = 1; i*i<=n; i++){
		if(g%i==0){
			if(i<=n) res = max(res,i);
			if(g/i <= n) res = max(res, g/i);
		}
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll arr[m];
		for(ll i = 0; i<m ; i++){
			cin >> arr[i];
		}
		ll g = 0;
		for(ll i = 0; i<m; i++){
			g = gcd(g,arr[i]);
		}
		if(g>n) {
			ll k = maxfact(g,n);
			g = k;
		}
		cout << n-g << endl;
	}
	return 0;
}
