#include <bits/stdc++.h>

using namespace std;

int timeformat(string s)
{
	//int h,m;
	//char c1, c2;
	//cin >> 
	int k1,k2;
	k1 = s[0]-'0';
	k2 = s[1]-'0';
	int hr = 10 * k1 + k2;
	if(s[5] == 'A' && hr == 12) hr = 00;
	else if(s[5] == 'P' && hr != 12) hr += 12;
	
	k1 = s[3] - '0';
	k2 = s[4] - '0';
	int min = 10 * k1 + k2;
	//cout << "\t YYY " << min << endl;
	return (hr*100 + min);
}

int main()
{
	int t;
	cin >> t;
	string s, k;
	//cin >> s >> k;
	//string str = s+k;
	//int x = timeformat(str);
	//cout << x << endl;
	while(t--)
	{
		cin >> s >> k;
		string str = s+k;
		
		int p = timeformat(str)/1000;
		//cout << "XX  " << p;
		//cout << "XX  " << p << endl;
		int n;
		cin >> n;
		int arr[n];
		string s1, k1, s2, k2;
		for(int i = 0; i<n; i++){
			cin >> s1 >> k1 >> s2 >> k2;
			string str1 = s1+k1;
			string str2 = s2+k2;
			//cout << "XXXX  " << s1 << endl;
			int j1 = (timeformat(str1)/10);
			int j2 = (timeformat(str2)/10);
			if(p>=j1 && p <=j2) arr[i] = 1;
			else arr[i] = 0;
			if(p<j1 && p>j2) arr[i] = 1;
			else arr[i] = 0;			
		}
		for(int i = 0; i<n; i++){
			cout << arr[i];
		}
		cout << endl;
	}
}
