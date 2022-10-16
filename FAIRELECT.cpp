#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<int> v1;
		vector<int> v2;
		int s1 = 0, s2 = 0;
		int k;
		for(int i = 0; i<n; i++){
			cin >> k;
			v1.push_back(k);
			s1 = s1 + k;
		}
		for(int i = 0; i<m; i++){
			cin >> k;
			v2.push_back(k);
			s2 = s2 + k;
		}
		if(s1>s2){
			cout << 0 << endl;
			continue;
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), greater<int>());
		int flag = 0, i;
		for(i = 0; i<min(n,m); i++){
			s1 = s1-v1[i]+v2[i];
			s2 = s2-v2[i]+v1[i];
			if(s1 > s2){
				flag = 1;
				break;
			}
		}
		if(flag == 0) cout << -1 << endl;
		else cout << (i+1) << endl;
	}
	return 0;
}
