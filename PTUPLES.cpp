#include <bits/stdc++.h>

using namespace std;

#define N 1000001

int main()
{
	
	bool prime[N];
	memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
	int ans[N] = {0};
	int count = 0;
	for(int i = 5; i<=N; i++){
		if(prime[i] && prime[i-2]) count++;
		ans[i] = count;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n < 5) cout << 0 << endl;	
		else cout << ans[n] << endl;
	}
	return 0;
}
