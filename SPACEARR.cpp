#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr;
		int k;
		for(int i = 0; i<n; i++){
			cin >> k;
			arr.push_back(k);
		}
		sort(arr.begin(), arr.end());
		if(arr[0] > 1){
			cout << "Second\n";
			continue;
		}
		int flag = 0;
		int count = 0, i;
		for(i = 1; i<n; i++){
			if(arr[i]<=(i+1)) count += ((i+1) - arr[i]);
			else flag = 1;
		}
		//cout << "XXX" << count << "\n";
		if((count % 2 == 1 && flag == 0)){
			cout << "First\n";
		}
		else{
			cout << "Second\n";
		}
		
	}
	return 0;
}
