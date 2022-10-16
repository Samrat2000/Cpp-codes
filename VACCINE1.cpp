#include <bits/stdc++.h>

using namespace std;

int main()
{
	int d1, v1, d2, v2, p;
	cin >> d1 >> v1 >> d2 >> v2 >> p;
	int count = min(d1, d2) - 1;
	int temp;
	if(d1<d2) temp=v1;
	else temp = v2;
	while(1){
		if(count < max(d1,d2)-1){
			count++;
			p-=temp;
		}
		else{
			count++;
			p-=(v1+v2);
		}
		if(p<=0) break;
	}
	cout << count << endl;
}
