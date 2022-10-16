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
		int arr[n];
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		
		int count = 0, i = 0;
		int startf, endf, gg = 0;
		for(; i<n; i++){
			if(i == 0){
				startf = arr[i];
				continue;
			}
			if(count >= 1 && arr[i]>startf){
				cout << "NO\n";
				break;
			}
			
			if(arr[i]>= arr[i-1]) continue;
			else{
				endf = arr[i-1];
				count++;
				if(count >= 1 && arr[i]>startf){
					cout << "NO\n";
					gg = 1;
				}
			}
			if(gg == 1) break;
		}
		if(i == n){
			cout << "YES\n" << count << "\n";
		}
	}
}
