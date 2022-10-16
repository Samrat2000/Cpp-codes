#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	set<int> look;
	int k;
	for(int i = 0; i<n; i++){
		cin >> k;
		look.push_back(k);
	}
	sort(look.begin(), look.end());
	for(auto it = look.begin(); it!=look.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
