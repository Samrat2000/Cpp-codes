#include <bits/stdc++.h>
#define int long long

using namespace std;

int power(int x, int y, int p)
{
    int res = 1; // Initialize result
 	x = x%p;
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)%p;
 
        // n must be even now
        y = y >> 1; // y = y/2
        x = (x * x)%p; // Change x to x^2
    }
    return res;
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << power(2,n-1,1000000007) << "\n";
	}
}
