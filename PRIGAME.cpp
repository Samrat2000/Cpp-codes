#include <bits/stdc++.h>

using namespace std;
#define lli long long int

int main()
{
	const lli MAX = 1000000;
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<lli> sieve(MAX+1,1), val(MAX+1);
	
	for(lli i = 2; i*i <= MAX; i++){
		if(sieve[i] == 1){
			for(lli j = 2*i; j<=MAX; j+=i){
				sieve[j] = 0;
			}
		}
	}
	val[0] = 0; val[1] = 0;
	for(lli i = 2; i<=MAX; i++){
		val[i] = val[i-1]+sieve[i];
	}
	
	lli t;
	cin >> t;
	while(t--){
		lli x,y;
		cin >> x >> y;
		if(val[x] <= y) cout << "Chef" ;
		else cout << "Divyam" ;
		cout << "\n";
	}
	return 0;
}
