#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int table[n][n];
	memset(table, 0, sizeof(table));
	for(int i = 0; i<n; i++){
		table[i][i] = 1;
	}
	int start = 0;
	int maxlength = 1;
	
	for(int i = 0; i<n-1; i++){
		if(str[i] == str[i+1]){
			table[i][i+1] = 1;
			if(maxlength<2){
				start = i;
				maxlength = 2;
			}
		}
	}
	
	for(int k = 3; k<=n; k++)
	{
		for(int i = 0; i<n-k+1; i++){
			if(str[i] == str[i+k-1] && table[i+1][i+k-2] == 1){
				table[i][i+k-1] = 1;
				if(k>maxlength){
					start = i;
					maxlength = k;
				}
			}
		}
	}
	
	cout << maxlength << "\n";
	for(int i = start; i< start+maxlength; i++){
		cout << str[i];
	}
	cout<<"\n";
	return 0;
}
