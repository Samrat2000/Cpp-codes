#include <iostream>
#include <string>
using namespace std;

void swap(int *a, int *b)
{
	int t;

	t=*a;
	*a=*b;
	*b=t;

}

int main()
{
	int t;
	cin >> t;
	string *s;
	s=new string[t];
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		int* a;
		a=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int j=0;j<n-k;j++)
		{
			if(a[j]>a[j+k]) swap(a[j],a[j+k]);
			//cout << "XXX"<< endl;
		}
		int c=1;
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1]) 
			{
				c=0;
				break;
			}
		}
		if(c==1) s[i]="yes";
		else s[i]="no";
		//cout << "XXX"<< endl;
	}
	for(int i=0;i<t;i++)
	{
		cout << s[i] << endl;
	}
}
