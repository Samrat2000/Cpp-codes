#include <iostream>

using namespace std;


int findLCM(int a, int b) 
{ 
    int lar = max(a, b); 
    int small = min(a, b); 
    for (int i = lar; ; i += lar) { 
        if (i % small == 0) 
            return i; 
    } 
} 

int main()
{
	int x,y,p,q;
	cin >> x >> y >> p >> q;
	int b1=1,b2=1,b3=1;
	b3=(findLCM(x,p)/p) * (findLCM(y,q)/q);
	b1=(b3*p)/x;
	b2=(b3*q)/y;
	cout << b1 << '\t' << b2 << '\t' << b3 << endl;
}
