#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* res = new int[n];
	cin >> arr[0];
	res[0] = 1;
	int key, j;
	for(int i = 1; i<n; i++){
		cin >> arr[i];
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]<key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
		res[i] = j+2;
	}
	
	for(int i = 0; i<n; i++){
		cout << res[i] << endl;
	}
	return 0;
}
