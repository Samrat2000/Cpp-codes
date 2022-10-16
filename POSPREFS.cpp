#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int* arr = new int[n];
		int sign = 1;
		for(int i = 0; i<n;){
			if(k==0){
				arr[i] = -1 * (i+1);
				i++;
				continue;
			}
			arr[i] = sign*(i+1);
			if(sign == 1) k--;
			if(i+1<n) {
				if(k!=0) {
					arr[i+1] = sign*(i+2);
					if(sign == 1) k--;
				}
				else
					arr[i+1] = -1 * (i+2);
			}
			sign = -1*sign;
			i+=2;
		}
		for(int i = n-1; k!=0; i--){
			if(arr[i]>0) continue;
			arr[i] = -1*arr[i];
			k--;
		}
		for(int i = 0; i<n; i++){
			cout << arr[i] <<" ";
		}
		cout << endl;
	}
	return 0;
}
