#include <iostream>
using namespace std;

int main()
{
	int m,n;
	cin >> m;
	int *a,*b;
	a= new int[m];
	for(int i=0;i<m;i++)
	{
		cin >> a[i];
	}
	cin >> n;
	b= new int[n];
	for(int j=0;j<n;j++)
	{
		cin >> b[j];
		int c=0,k;
		for(int i=0;i<b[j];)
		{
			if(a[c]==-1) 
			{
				c++;
				continue;
			}
			k=a[c];
			c++;
			i++;
		}
		b[j]=k;
		a[c-1]=-1;
	}
	for(int i=0;i<n;i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
