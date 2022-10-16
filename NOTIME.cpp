#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,h,x;
	cin >> n >> h >> x;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int k = h-x;
	int i;
	for(i = 0; i<n; i++){
		if(arr[i]>=k){
			cout << "YES\n";
			break;
		}
	}
	if(i == n) cout << "NO\n";
	return 0;
}
