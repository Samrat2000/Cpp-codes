#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	while(k--)
	{
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		
		int pos = -1;
		for(int i = n-2; i>=0; i--){
			if(arr[i]<arr[i+1]){
				pos = i;
				break;
			}
		}
		
		for(int i = n-1; i>pos; i--){
			if(arr[pos]<arr[i]){
				int k = arr[pos];
				arr[pos] = arr[i];
				arr[i] = k;
				break;
			}
		}
		
		for(int i = 0; i<=pos; i++){
			cout << arr[i] << " ";
		}
		for(int i=n-1; i>pos; i--){
			cout << arr[i] << " ";
		}
		cout <<"\n";
	}
	return 0;
}
