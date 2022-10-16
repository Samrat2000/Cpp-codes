#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int x,y,K,N;
		cin >> x >> y >> K >> N;
		if((x-y)%(K+K)) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
