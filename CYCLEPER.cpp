#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* res = new int[3*n];
	
	for(int i = 0; i< n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	int c = 0;
	for(int i = 0; i<n; i++){
		if(arr[i]==-1) continue;
		if(arr[i]==i+1){
			res[c++] = i+1;
			res[c++] = i+1;
			count++;
			arr[i] = -1;
			res[c++] = 0;
		}
		else{
			res[c++] = i+1;
			int k = arr[i];
			arr[i] = -1;
			while(k != -1){
				res[c++] = k;
				int p = k;
				k = arr[k-1];
				arr[p-1] = -1;
			}
			count++;
			res[c++] = 0;
		}
	}
	cout << count << endl;
	for(int i = 0; i<c; i++){
		if(res[i]==0) cout<<endl;
		else cout<< res[i] << " ";
	}
	return 0;
}
