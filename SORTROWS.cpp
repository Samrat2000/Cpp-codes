#include <bits/stdc++.h>  
#include<string.h>  

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	string* str = new string[n];
	for(int i = 0; i<n;){
		cin >> k;
		if(k == -1){
			str[i]+= '\0';
			i++;
			//cout << str[i-1] <<"XXXXX\n";
			continue;
		}
		stringstream m;
		m << k;
		string z = m.str();
		str[i] += (z+'x');
	}
	
	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (str[j] > str[j + 1]) {
                string temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    
    for(int i = 0; i<n;){
    	for(int j = 0; str[i][j]!='\0' ; j++){
    		cout << "ZZ\n";
			if(str[i][j] == 'x'){
				cout << " ";
				continue;
			}
			cout << str[i][j];
		}
		cout << "\n";
	}
	return 0;
}
