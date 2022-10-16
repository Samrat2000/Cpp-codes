#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> v;
		int c;
		int sum = 0;
		for(int i = 0; i<n; i++){
			cin >> c;
			v.push_back(c);
			sum+=c;
		}
		if(n < 2 || sum < 2*k){
			cout << -1 << endl;
			continue;
		}
		sort(v.begin(), v.end(), greater<int>());
		int i = 0, sa = 0, sb = 0;
		int count=0;
		while(i<n){
			int flag = -1;
			if(v[i] == -1) continue;
			sa += v[i];
			//cout << "XX " << v[i] << "  " << i << " XX\n";
			count++;
			v[i] = -1;
			if(sa >= k) break;
			int j ;
			
			for(j = i+1; j<n; j++){
				if(v[j] >= k-sa && v[j] != -1) flag = j;
			}
			if(flag > -1) {
				sa += v[flag];
				//cout << "XX " << v[flag] << "  " << flag << " XX\n";
				count++;
				v[flag] = -1;
			}
			if(sa >= k) break;
			i++;
		}
		if(sa < k){
			cout << -1 << endl;
			continue;
		}
		while(i++<n){
			
			if(v[i] == -1) continue;
			sb += v[i];
			//cout << "XXX " << v[i] << " XXX\n";
			count++;
			v[i] = -1;
			if(sb >= k) break;
			//i++;
		}
		if(sb < k){
			cout << -1 << endl;
			continue;
		}
		
		cout << count << endl;
	}
	return 0;
}
