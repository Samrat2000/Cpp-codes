#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		int g = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			g = gcd(g,arr[i]);
		}
		int count = 0;
		for(int i = 0; i<n; i++){
			count += (arr[i]/g);
		}
		cout << g << " " << count << endl;
	} 
	return 0;
}
