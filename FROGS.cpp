#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		int k, c;
		map<int, int> pos;
		for(int i = 0; i<n; i++){
			cin >> k;
			arr[i] = k;
			pos[k] = i;
		}
		map<int, int> check;
		for(int i = 0; i<n; i++){
			cin >> k;
			check[arr[i]] = k;
		}
		int tot = 0;
		for(int i = 2; i<=n; i++){
			if(pos[i] > pos[i-1]) continue;
			else{
				int hit = ceil(float(pos[i-1]-pos[i]+1)/check[i]);
				tot += hit;
				pos[i] += hit * check[i]; 
			}
		}
		cout << tot << endl;
	}
	return 0;
}
