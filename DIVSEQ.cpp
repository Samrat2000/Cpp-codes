#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i< n; i++){
		cin >> arr[i];
	}
	int* dp = new int[n];
	dp[0] = 1;
	for(int i = 1; i<n; i++){
		dp[i] = 1;
		for(int j = 0; j<i; j++){
			if(arr[i]%arr[j]==0){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int max = 1;
	for(int i = 0; i<n; i++){
		max = dp[i]>max?dp[i]:max;
	}
	cout << max << endl;
	return 0;
}
