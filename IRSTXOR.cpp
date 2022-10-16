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
		if(n==0){
			cout << 1 << "\n";
			continue;
		}
		int count = 0;
		lli t = n;
    	while( n != 0)  
    	{  
    		n >>= 1;  
       		count += 1;  
    	} 
    	lli p = 1 << count;
    	lli k = 1 << (count-1);
    	lli a = k-1;
    	lli b = p-1;
		//int p = (int)log2(n);
		//int k = (int)pow(2,p);
		//int a = k-1;
		//int b = (int)pow(2,p+1) - 1;
		lli res = a*b - a*(t-k);
		cout << res << "\n";
	}
	return 0;
}
