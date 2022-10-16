#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--){
		int n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;
		
		int ans = 1e9;
		for(int cakes = 0; cakes<=n; cakes++){
			if(e<cakes || h<cakes) break;
			int omelettes = (e-cakes)/2;
			int shake = (h-cakes)/3;
			
			if(cakes+omelettes+shake < n) continue;
			
			int omreq, shreq;
			if(a<b){
				omreq = min(n-cakes, omelettes);
				shreq = n-cakes-omreq;
			}
			else{
				shreq = min(n-cakes, shake);
				omreq = n-cakes-shreq;
			}
			
			int price = cakes*c + omreq*a + shreq*b;
			if(price < ans) ans = price;
		}
		if(ans == 1e9) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}
