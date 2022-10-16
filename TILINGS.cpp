#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 5;
	for(int i = 3; i<n; i++){
		arr[i] = (2*arr[i-1] + arr[i-3])%10000;
	}
	cout << arr[n-1]%10000 << endl;
	return 0;
}
