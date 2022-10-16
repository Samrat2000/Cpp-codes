#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	set<int> arr;
	int k;
	for(int i = 0; i<m+n; i++){
		cin >> k;
		if(k != -1) arr.insert(k);
		else{
			cout << *std::prev(arr.end());
			arr.erase(--arr.end());
			cout << "\n";
		}
	}
	return 0;
}
