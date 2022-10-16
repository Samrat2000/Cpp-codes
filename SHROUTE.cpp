#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for(int i = 0; i<n; i++) cin >> a[i];
		for(int i = 0; i<m; i++) cin >> b[i];
		
		map<int, int> mp;
		for(int i = 0; i<n; i++){
			if(i == 0) mp[i] = 0;
			if(a[i]!=0) mp[i] = 0;
			else mp[i] = INT_MAX;
		}
		
		int right = -1;
		for(int i = 0; i<n; i++){
			if(a[i]==1) right = i;
			if(a[i]==0 && right != -1) mp[i]=min(mp[i], i-right);
		}
		
		int left = -1;
		for(int i = n-1; i>=0; i--){
			if(a[i]==2) left = i;
			if(a[i]==0 && left != -1) mp[i]=min(mp[i], left-i);
		}
		
		for(int i = 0; i<m; i++){
			int k = b[i]-1;
			if(mp[k]!=INT_MAX) cout<<mp[k] << " ";
			else cout << "-1 ";
		}
		cout << "\n";
	}
}
