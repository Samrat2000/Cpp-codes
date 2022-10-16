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
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		int res[n];
		res[0] = 0;
		for(int i = 1; i<n; i++){
			if(arr[i] == arr[i-1]) res[i] = res[i-1]+1;
			else res[i] = 0;
		}
		
	
		for(int i = n-1; i>=0;){
			int k= res[i];
			if(k == 0){
				i--; continue;
			}
			else{
				int temp = k;
				for(int j = i-1; temp--; j--){
					res[j] = k;
				}
				i-=(k+1);
			}
		}
		
		for(int i = 0; i<n; i++){
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}
