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
		lli sodd = 0, seven = 0;
		for(lli i = n; i>0; i/=10){
			lli k = i%10;
			if(k&1) sodd += k;
			else seven += k;
		}
		if(sodd == 0 && seven%4==0) cout << "Yes\n";
		else if(seven == 0 && sodd%3==0) cout << "Yes\n";
		else if(sodd%3==0 || seven%4==0) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
