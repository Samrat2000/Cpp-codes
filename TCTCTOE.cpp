#include <bits/stdc++.h>
#define int long long
using namespace std;

int isWon(string arr[], char c)
{
	if((arr[0][0] == c && arr[0][1] == c && arr[0][2] == c) ||
	    (arr[1][0] == c && arr[1][1] == c && arr[1][2] == c) ||
		(arr[2][0] == c && arr[2][1] == c && arr[2][2] == c) ||
		(arr[0][0] == c && arr[1][0] == c && arr[2][0] == c) ||
		(arr[0][1] == c && arr[1][1] == c && arr[2][1] == c) ||
		(arr[0][2] == c && arr[1][2] == c && arr[2][2] == c) ||
		(arr[0][0] == c && arr[1][1] == c && arr[2][2] == c) ||
		(arr[0][2] == c && arr[1][1] == c && arr[2][0] == c))
		return 1;
	else return 0;
}

int isReachable(string arr[])
{
	int xc=0, oc=0, dc=0;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(arr[i][j] == 'X') xc++;
			if(arr[i][j] == 'O') oc++;
			if(arr[i][j] == '_') dc++;
		}
	}
	if((oc == xc || xc == (oc+1)) && !(isWon(arr,'X') && isWon(arr,'O'))) return dc;
	else return -1;
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string arr[3];
		for(int i = 0; i<3; i++){
			cin >> arr[i];
		}
		if(isReachable(arr) == -1) cout << "3\n";
		else if((isWon(arr,'X') && isReachable(arr)%2==1) || (isWon(arr,'O') && isReachable(arr)%2==0)) cout << "3\n";
		else if(isReachable(arr) == 0 || isWon(arr,'X') || isWon(arr,'O')) cout << "1\n";
		else cout << "2\n";
	}
}
