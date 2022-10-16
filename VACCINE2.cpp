#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long n, d;
		cin >> n >> d;
		long* arr = new long[n];
		long risk = 0, nonrisk = 0;
		for(int i = 0; i<n ;i++)
		{
			cin >> arr[i];
			if(arr[i]<=9 || arr[i]>=80) risk++;
			else nonrisk++;
		}
		long res = (risk%d!=0)?risk/d + 1: risk/d;
		res += (nonrisk%d!=0)?nonrisk/d + 1: nonrisk/d;
		cout << res << endl;
	}
	return 0;
}
