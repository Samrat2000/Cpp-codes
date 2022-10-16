#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr=new int[n];
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		if(n==1)
		{
			cout << arr[0] << "\n";
			continue;
		}
		int j,key;
		for(int i = 1; i<n; i++){
			key = arr[i];
			j = i-1;
			while(j>=0 && arr[j] > key){
				arr[j+1] = arr[j];
				j = j-1;
			}
			arr[j+1] = key;
		}
		
		int t=0;
		int burner[] = {0,0};
		for(int i=n-2; i>=0;i--){
			if(i==n-2){
				burner[0] = arr[n-1]; 
				burner[1] = arr[n-2]; 
			}
			
			if(burner[0]==0) {
				burner[0] = arr[i]; 
			}
			else if(burner[1]==0) {
				burner[1] = arr[i]; 
			}
			
			int k = min(burner[0], burner[1]);
			t = t+k;
			burner[0] -= k;
			burner[1] -= k;
		}
		if(burner[0]!=0) t+=burner[0];
		else if(burner[1]!=0) t+=burner[1];
		cout << t << "\n";
	}
	return 0;
}
