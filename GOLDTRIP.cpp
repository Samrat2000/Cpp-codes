#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int q;
		cin >> q;
		while(q--){
			int q1, q2;
			cin >> q1 >> q2;
			int sum = 0;
			for(int i = q1-1; i<q2; i++){
				sum+= arr[i];
			}
			cout << sum <<"\n";
		}
	}
	return 0;
}
