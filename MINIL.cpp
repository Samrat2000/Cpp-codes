
/*

1
5 5
*****
.....
*.*..
..**.
.*..*

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		char arr[a][b];
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				cin >> arr[i][j];
			}
		}
		int count = 0;
		int ca = 0, cb = 0;
		if(a&1 && b&1){
			for(int i = 0; i<a; i++){
				for(int j = 0; j<b; j++){
					if(((i%2 == 0 && j%2 == 0) || (i%2 && j%2)) && arr[i][j] != '*') count++; 					
					if(((i%2 == 0 && j%2) || (i%2 && j%2 == 0)) && arr[i][j] != '.') count++;
				}
			}
			cout << count << endl;
		}
		else {
			for(int i = 0; i<a; i++){
				for(int j = 0; j<b; j++){
					if(((i%2 == 0 && j%2 == 0) || (i%2 && j%2)) && arr[i][j] != '*') ca++; 					
					if(((i%2 == 0 && j%2) || (i%2 && j%2 == 0)) && arr[i][j] != '.') ca++;
				}
			}
			for(int i = 0; i<a; i++){
				for(int j = 0; j<b; j++){
					if(((i%2 == 0 && j%2 == 0) || (i%2 && j%2)) && arr[i][j] != '.') cb++; 					
					if(((i%2 == 0 && j%2) || (i%2 && j%2 == 0)) && arr[i][j] != '*') cb++;
				}
			}
			cout << min(ca, cb) << endl;
		}
		
	}
	return 0;
}
