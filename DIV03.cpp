#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int* arr = new int[10];
		int k;
		for(int i = 0; i<10; i++){
			cin >> arr[i];
		}
		cin >> k;
		//int j = 9;
		int res = 9;
		for(int i = 9; i>=0 && k>0; i--){
			if(k>0 && k<=arr[i]) {
				arr[i] = arr[i]-k;
				k = 0;
			}
			else if(k>0 && k > arr[i]) {
				arr[i] = 0;
				k = k-arr[i];
				res = i;
			}
			
			cout << "            res = " << k << "   " << res << endl; 
		}
		cout << "KK\n" ;
		if(res!=0){
			int c = res;
			while(c--){
				if(arr[c] != 0) {
					res = c;
					break;
				}
			}
		}
		cout << res << "\n";
		cout << "XX\n";
		delete arr;
	}
	return 0;
}
