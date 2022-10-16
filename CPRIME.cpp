#include <bits/stdc++.h>

using namespace std;

int isPalin(string str)
{
	for(int i = 0; i<str.length()/2; i++){
		if(str[i] != str[str.length()-1-i]) return 0;
	}
	return 1;
}

int isPrime(int n) 
{ 
    if (n <= 1) 
        return 0; 
    if (n <= 3) 
        return 1; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return 0; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return 0; 
  
    return 1; 
} 

int main()
{
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		stringstream ss;  
  		ss<<k;  
  		string s;  
  		ss>>s; 
		if(isPrime(k)&&isPalin(s)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
