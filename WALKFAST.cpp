#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		lli n,a,b,c,d,p,q,y;
		cin>>n>>a>>b>>c>>d>>p>>q>>y;
		lli arr[n];
		for(lli i = 0; i<n; i++){
			cin >> arr[i];
		}
		// When train is not taken
		lli walk = abs(arr[b-1] - arr[a-1])*p;
		
		// When train is taken
		lli k = (abs(arr[c-1]-arr[a-1]))*p;
		if(k > y) {
			cout << walk <<"\n";
		}
		else{
			lli train = y + (abs(arr[d-1]-arr[c-1])*q) + (abs(arr[b-1]-arr[d-1])*p);
			lli res = min(walk, train);
			cout << res <<"\n";	
		}
	}
	return 0;
}
