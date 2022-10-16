#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		long a,b;
		cin >> a >> b;
		long aodd = (a%2!=0)?((a+1)/2):(a/2);
		long aeven = a/2;
		long bodd = (b%2!=0)?((b+1)/2):(b/2);
		long beven = b/2;
		cout << (aodd*bodd + aeven*beven) << endl;
	}
	return 0;
}
