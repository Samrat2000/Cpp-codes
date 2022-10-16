#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; 
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> check;
		int k;
		string p = "prekrasnyy";
		for(int i = 0;i<n; i++){
			cin >> k;
			if(p ==  "ne krasivo") continue;
			check[k]++;
			if(check[k]>1) p= "ne krasivo";
		}
		cout << p <<"\n";
	}
	return 0;
}
