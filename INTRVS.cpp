#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i = 0; i<n ;i++){
			cin >> arr[i];
		}
		int count = 0;
		for(int i = 0; i<n; i++){
			if(arr[i] != -1) count++;
		}
		if(count < ceil(n/2.0)){
			cout << "Rejected" << endl;
			continue;
		}
		count = 0;
		for(int i = 0; i<n; i++){
			if(arr[i] > k) {
				count++;
				break;
			}
		}
		if(count == 1){
			cout << "Too Slow" << endl;
			continue;
		}
		count = 0;
		for(int i = 0; i<n; i++){
			if(arr[i] >= 0 && arr[i] <= 1) {
				count++;
				break;
			}
		}
		if(count == n){
			cout << "Bot" << endl;
		}
		else{
			cout << "Accepted" << endl;
		}
	}
	return 0;
}
