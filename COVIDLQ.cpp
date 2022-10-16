#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string *s;
	s=new string[t];
	for(int i=0;i<t;i++)
	{
		int n;
		cin >> n;
		int *pos;
		pos=new int[n];
		int c=-1,flag=1;
		for(int j=0;j<n;j++)
		{
			/*if(c==-1 && j==n-1) 
			{
				pos[j]=1;  //to ensure atleast one spot is occupied
				break;
			}*/
			cin >> pos[j];
			if(c==-1 && pos[j]==1)
			{
				c=j;
				continue;
			}
			if(flag==1 && pos[j]==1)
			{
				c=j-c;
				flag=(c<6)?0:1;
				c=j;
			}
		}
		if(flag==1) s[i]="YES";
		else s[i]="NO";
		delete []pos;
	}
	for(int i=0;i<t;i++)
	{
		cout << s[i] << endl;
	}
	delete []s;
}
