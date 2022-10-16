#include <iostream>
#include <string>
using namespace std;

class Node
{
	public:
		int price,position;
		
		Node(int pr=100, int pos=0)
		{
			price= pr;
			position= pos;
		}
};

int main()
{
	int t;
	cin >> t;
	string *s;
	s=new string[t];
	for(int i=0;i<t;i++)
	{
		int n,sum;
		cin>>n>>sum;
		int min_d=100,min_f=100;
		Node* a;
		a=new Node[n];
		for(int j=0;j<n;j++)
		{
			cin >> a[j].price;
		}
		for(int j=0;j<n;j++)
		{
			cin >> a[j].position;
			if(a[j].position==0 && a[j].price<min_d) min_d=a[j].price;
			if(a[j].position==1 && a[j].price<min_f) min_f=a[j].price;
		}
		if(sum+min_d+min_f<=100) s[i]="yes";
		else s[i]="no";
	}
	for(int i=0;i<t;i++)
	{
		cout << s[i] << endl;
	}
}
