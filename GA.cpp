#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int f = 0, s = 1;
		if(n == 1) {
			cout << f << endl;
			continue;
		}
		if(n == 2){
			cout << f << endl;
			cout << f << s << endl;
			continue;
		}
		cout << f << endl;
		cout << f << s << endl;
		for(int i = 3; i<=n; i++){
			cout << f << s;
			for(int j = 3; j<=i; j++){
				int t = f+s;
				cout << t;
				f = s;
				s = t;
			}
			f = 0;
			s = 1;
			cout << endl;
		}
	}
	return 0;
}
