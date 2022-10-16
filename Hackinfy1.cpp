#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a,b,c;
		cin >> a >> b >> c;
		string x1, x2, x3;
		if(a.length()<=b.length() && a.length()<=c.length()) {
			x1 = a;
			if(b.length() <= c.length()){
				x2 = b; x3 = c;
			}
			else{
				x2 = c; x3 = b;
			}
		}
		else if(b.length()<=a.length() && b.length()<=c.length()) {
			x1 = b;
			if(a.length() <= c.length()){
				x2 = a; x3 = c;
			}
			else{
				x2 = c; x3 = a;
			}
		}
		else{
			x1 = c;
			if(a.length() <= b.length()){
				x2 = a; x3 = b;
			}
			else{
				x2 = b; x3 = a;
			}
		}
		
		// x1 contains the smallest length string followed by x2, x3
		
		int k = x1.length();
		if(x2.substr(x2.length()-k) == x1 && x3.substr(x3.length() - k) == x1){
			cout << (x2.length() + x3.length() - 2*k) << "\n";
		}
		else{
			cout << (x1.length()+x2.length()+x3.length()) << "\n";
		}
	}
}
