#include <bits/stdc++.h>
 
 using namespace std;
 
 int main()
 {
 	int t;
 	cin >> t;
 	while(t--){
 		int n, k;
 		cin >> n >> k;
 		if(n<k || k==0) cout << n << endl;
 		else cout << (n%k) << endl;
 	}
 	return 0;
 }
