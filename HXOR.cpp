#include <bits/stdc++.h>

using namespace std;
#define lli long long int

lli setBitNumber(lli n) 
{ 
  	lli c = 1;
  	for(lli i = 0; i<30; i++){
  		n |= n >> c;
  		c= c+c;
	  } 
    n = n + 1; 
  
    return (n >> 1); 
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		lli n, x;
		cin >> n >> x;
		lli* arr = new lli[n];
		for(lli i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(lli i = 0; i<n,x>0;){
			if(i+1>=n) break;
			if(arr[i]==0) {
				i++;
				continue;
			}
			lli k = setBitNumber(arr[i]);    //lli k = pow(2,(int)log2(arr[i]));     
			lli c=1;
			while(1){
				if((arr[i+c] != 0 && (k^arr[i+c])<arr[i+c])||(i+c==n-1)){
					arr[i] = arr[i]^k;
					arr[i+c] = arr[i+c]^k;
					x--;
					break;
				}
				c++;
			}
		}
		if(n==2&&x%2!=0){
			arr[1] = arr[1]^1;
			arr[0]=arr[0]^1;
		}
		for(lli i = 0; i<n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
