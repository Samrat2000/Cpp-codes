#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int count = 0;
	for(int i = 0; i<n; i++){
		int k = 2*arr[i];
		int l = 0;
		int r = n-1;
		while(l<r){
			if(arr[l]+arr[r]==k){
				count++;
				break;
			}
			else if(arr[l]+arr[r]<k) l++;
			else r--;
		}
	}
	cout << count << endl;
}
