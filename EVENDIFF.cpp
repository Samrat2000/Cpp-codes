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
		int even = 0, odd = 0;
		int k;
		for(int i = 0; i<n; i++){
			cin >> k;
			if(k%2 == 0) even++;
			else odd++;
		}
		cout << min(even, odd) << endl;
	}
	return 0;
}
