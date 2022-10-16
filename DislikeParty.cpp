#include <iostream>

using namespace std;

class Node
{
	public:
		int data1,data2;
		
		Node(int d1=-1, int d2=-1)
		{
			data1= d1;
			data2= d2;
		}
};

		
int main()
{
	int t,a[10][10];
	cin >> t;
	for(int i=0; i < 10; i++)
	{
		for(int j=0; j < 10 ; j++)
		{
			cin >> a[i][j];
			if(a[i][j]>t)
			{
				cout << "Input not valid!!!";
				exit(0);
			}
		}
	}
	int c=0;
	Node **p;
	p=new Node*[10];
	for(int j=0;j<10;j++)
	{
		p[j]=new Node[9];
		
		for(int i=0;i< 9;i++)
		{
			int flag=0;
			
			for(int k=0;k<j;k++)
			{
				
				if(a[j][i+1]==a[k][0])
				{
					for(int m=0;m<9;m++)
					{
						
						if(a[j][0]==a[k][m+1])
						{
							p[j][i].data1=-1;
							p[j][i].data2=-1;
							flag=1;
							break;
						}
				 	}
					break;
				}
			}
			if(flag==1) continue;
			p[j][i].data1=a[j][0];
			
			p[j][i].data2=a[j][i+1];
			
			c++;
		}
	}
	int result = t*(t-1)/2 - c;
	cout << result;
	for(int i=0;i<9;i++)
	{
		delete []p[i];
	}
	delete []p;
}
