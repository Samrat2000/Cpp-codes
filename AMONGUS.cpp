#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int input[n+1];
	map<int, int> check;
	map<int, int> res;
	for(int i = 0; i<n; i++){
		cin >> input[i];
		check[input[i]]++;
	}
	int k;
	for(int i = 0; i<n+1; i++){
		cin >> input[i];
		res[input[i]]++;
	}
	for(auto it = res.begin(); it!=res.end(); it++){
		if(res[it->first] != check[it->first]) k = it->first;
	}
	cout << k << endl;
	return 0;
}
