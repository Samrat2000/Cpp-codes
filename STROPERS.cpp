#include <bits/stdc++.h>

using namespace std;



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		set<tuple<int, int, int>>check;
		for(int i = 0; i<str.length(); i++){
			int one = 0;
			int count = 0;
			int j;
			for(j = i; j<str.length();j++){
				if(str[j] == '1')
					one++;
				if(one%2)
					count++;
				check.insert({j-i+1, one, count});
			}
		}
    	cout << check.size() << endl;
	}
}
