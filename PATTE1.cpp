#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int** arr = new int*[4];
		for(int i = 0; i<4; i++){
			arr[i] = new int[n];
		}
		int k = 1;
		for(int i = 0; i<n; i++){
			if(i>0) k = arr[3][i-1];
			for(int j = 0; j<3; j++){
				arr[j][i] = k;
				//cout << arr[j][i] << "XXXX\n";
				k++;
			}
			arr[3][i] = arr[2][i] + arr[0][i];
			//cout << arr[3][i] << "XXXX\n";
		}
		
		for(int i = 0; i<2; i++){
			for(int j = 0; j<n; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		for(int i = 3; i>=2; i--){
			for(int j = 0; j<n; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
