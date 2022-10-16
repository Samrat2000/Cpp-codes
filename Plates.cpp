#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int w = 0;
	while(w < t){
		int n, k, p;
		cin >> n >> k >> p;
		int sum[n+1][k+1];
		memset(sum,0,sizeof(sum));
		int dp[n+1][p+1];
		int m;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=k; j++){
				cin >> m;
				sum[i][j] = m + sum[i][j-1];
			}
		}
		
		for(int i = 0; i<=n; i++){
			for(int j = 0; j<=p; j++){
				if(i==0 || j==0){
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = 0;
				for(int x = 0; x<= min(j,k); x++){
					dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x]);
				}
			}
		}
		cout << "Case #" << (w+1) << ": " << dp[n][p] << "\n";
		w++;
	}
}
