#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int x,y,z;
		cin >> x >> y >> z;
		int max = -1;
		if(x >= y && x>=z){
			max = x;
			x = 0;
		}
		else if(y >= x && y >= z){
			max = y;
			y = 0;
		}
		else{
			max = z;
			z = 0;
		}
		if(max == x + y + z){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
