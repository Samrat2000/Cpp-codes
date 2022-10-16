#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, x;
		cin >> n >> x;
		int s, r;
		int tr = -1;
		for(int i = 0; i<n; i++){
			cin >> s >> r;
			if(r > tr && s <= x){
				tr = r;
			}
		}
		cout << tr << "\n";
	}
}
