#include <iostream>
using namespace std;

int main()
{
	int n, t1=0, t2=1, t3;
	cout<< "Number of terms: ";
	cin>> n;
	
	if(n>=1) cout << t1 << " ";
	if(n>=2) cout << t2 << " ";
	for(int i = 3; n>=3 && i<=n; i++)
	{
		t3 = t1+t2;
		cout << t3 <<" ";
		t1 = t2;
		t2 = t3;
	}
	return 0;
}
