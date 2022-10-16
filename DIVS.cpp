#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int a, b;
		cin >> a >> b;
		double res = (a*1.0/b);
		double fractpart, intpart;
		fractpart = modf(res, &intpart);
		//cout << fractpart << "\n";
		int ans = (int)(fractpart*pow(10,k));
		int sum = 0;
		for(int i = 0; i<k; i++){
			sum += (ans%10);
			ans /= 10;
		}
		cout << sum << "\n";
	}
}
