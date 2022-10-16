#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, l, r;
		cin >> n >> l >> r;
		int smin = 0; int smax = 0;
		for(int i = n-1; i>=0; i--){
			smin += pow(2, l-1);
			if(l!=1) l--;
		}
		cout << smin << "\n";
		int c = 0;
		for(int i = 0; i<n; i++){
			smax += pow(2, c);
			if(c!=r-1) c++;
		}
		cout << smax << "\n";
	}
	return 0;
}
