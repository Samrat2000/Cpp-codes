#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		lli n;
		cin >> n;
		if(n==1){
			cout << "Grinch" << endl;
			continue;
		}
		if(n==2 || n%2){
			cout << "Me" << endl;
			continue;
		}
		
		int c = 0;
		for(int i = 3; i*i<=n; i+=2){
			if(n%i==0 && (n/i)%2==0){
				cout << "Me" << endl;
				c = 1;
				break;
			}
		}
		if(c==0) cout << "Grinch" << endl;
	}
	return 0;
	
}
