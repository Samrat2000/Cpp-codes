#include <bits/stdc++.h>

using namespace std;

int main()
{
	int  n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	map<int, int> m;
	int s = n1+n2+n3;
	int k;
	for(int i = 0; i<n1; i++){
		cin >> k;
		m[k]=1;
	}
	int c1 = 0;
	for(int i = 0; i<n2; i++){
		cin >> k;
		if(m.find(k) != m.end()){
			m[k]=2;
			c1++;
		}
		else m[k] = 1;
	}
	
	for(int i = 0; i<n3; i++){
		cin >> k;
		if(m.find(k) != m.end()){
			if(m[k]!=2) c1++;
			m[k]=2;
		}
		else m[k] = 1;
	}
	
	cout << c1 << "\n";
	for(auto i= m.begin(); i!=m.end(); i++){
		if(i->second >= 2) 
			cout << i->first << "\n";
	}
	return 0;
}
