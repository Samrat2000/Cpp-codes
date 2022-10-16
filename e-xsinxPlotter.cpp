#include <iomanip>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	double a,b,s;
	cout << "Enter the starting angle in radians :   " ;
	cin >> a;
	cout << "Enter the ending angle in radians :   " ;
	cin >> b;
	cout << "Enter the step length :   " ;
	cin >> s;
	double result;
	for(double i=a;i<=b;i+=s)
	{
		result = tan(i);
		if(result>=0)
		{
			//result=result*80>=80?1:result;
			cout << setw(80*5) << setfill(' ') << '|' << setw(abs(int(result*5))) << setfill('*') << '+' << endl;
			
		}
		else
		{
			//result=result*80<=80?1:result;
			cout << setw(80*5-abs(int(result*5))) << setfill(' ') << '+' << setw(abs(int(result*5))) << setfill('*') << '|' << endl ;
		}
	}
}
