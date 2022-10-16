#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n,k;
int arr[N];

bool check(int d)
{
	int fd = 0;
	for(int i = 1; i<n; i++){
		fd += ((arr[i]-arr[i-1] - 1)/d);
	}	
	if(fd <= k) return true;
	else return false;
}

int binsearch(int low, int high)
{
	while(low < high){
		int mid = (high+low)/2;
		if(check(mid)){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}
	return low;
}

int main()
{
	int t;
	cin >> t;
	int tc = 0;
	while(t--){
		tc++;
		cin >> n >> k;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int res = binsearch(1, 1e9);
		cout << "Case #" << tc << ": " << res << "\n";
	}
	return 0;
}
