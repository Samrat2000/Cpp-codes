#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		int player,lead;
		
		Node(int d1=1, int d2=0)
		{
			player= d1;
			lead= d2;
		}
};

int main()
{
	int round,k=0;
	cin >> round;
	int *p1, *p2;
	p1=new int[round];
	p2=new int[round];
	int s1=0, s2=0;
	Node result;
	for(int i=0;i<round;i++)
	{
		cin >> p1[i] >> p2[i];
		s1+=p1[i];
		s2+=p2[i];
		if(abs(s1-s2)< abs(k)) continue;
		k=s1-s2;
		if(k<0)
		{
			result.player=2;
			result.lead=-1*k;
		}
		else
		{
			result.player=1;
			result.lead=k;
		}
	}
	cout << result.player << " " << result.lead;
}
