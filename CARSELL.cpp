#include <iostream>
using namespace std;

void bubbleSort(long a[], int n)
{   
    for (int i = 0; i < n-1; i++)      // Last i elements are already in place  
    	for (int j = 0; j < n-i-1; j++)  
        	if (a[j] < a[j+1]) 
			{
				long k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			} 
} 

int main()
{
	int t;
	cin >> t;
	long* ans;
	ans=new long[t];
	for(int i=0;i<t;i++)
	{
		int n;
		cin>> n;
		if(n>2000) exit(0);
		long* p;
		p=new long[n];
		for(int j=0;j<n;j++)
		{
			cin >> p[j];
		}
		bubbleSort(p,n);
		long s=0;
		for(int j=0;j<n;j++)
		{
			if(p[j]-j > 0) s+=(p[j]-j);
		}
		ans[i]=s;
		delete []p;
	}
	for(int i=0;i<t;i++)
	{
		cout << ans[i] << endl;
	}
	delete []ans;
}
