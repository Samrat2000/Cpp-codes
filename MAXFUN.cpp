#include <bits/stdc++.h>
# define lli long long int
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		lli n;
		cin >> n;
		lli arr[n];
		lli min, max;
		for(lli i = 0; i<n; i++){
			cin >> arr[i];
			if(i == 0){
				min = arr[i]; max = arr[i];
				continue;
			}
			if(arr[i]>max) max = arr[i];
			if(arr[i]<min) min = arr[i];
		}
		lli k = max - min;
		lli m = 0;
		for(int i = 0; i<n; i++){
			if(((arr[i]-min) + (max-arr[i]) + k) > m)
				m = (arr[i]-min) + (max-arr[i]) + k;
		}
		cout << m << endl;
	}
	return 0;
}
