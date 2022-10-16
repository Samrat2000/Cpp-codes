#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int k = ceil(n/4.0) - 1;
		int t = n%4;
		int res = 0;
		int top;
		if(n==4) res += (4*15);
		else if(n<4) {
			if(t == 1) top = 20;
			else top = (t*15+6);
			res += top;
		}
		else if(n<8){
			res += (t*11 + (4-t)*15);
			if(t == 1) top = 20;
			else top = (t*15+6);
			res += top;
		}
		else if(n == 8) res += (44 + 60);
		
		else if(n>8){
			if(t != 0){
				res += (t*11 + (4-t)*15);
				if(t == 1) top = 20;
				else top = (t*15+6);
				res += (top + 44 * (k-1));
			}
			else res += (44 * k + 60);
			
			//res += 44*(k-1);
		}
		//res += ((t*15)+5);
		/*if(n>=4) res += 24;
		res += (36*k);
		if(t!=0){
			res += ((9*t) + 5);
		}
		if(n<4) res += (n*6);*/
		cout << res << "\n";
	}
}
