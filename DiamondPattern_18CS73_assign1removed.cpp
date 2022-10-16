/*
Diamond pattern with numbers
      1
    32123
  543212345
    32123
      1
Input : n = number of lines(n must be odd)
*/


// header files for input/output and manipulators
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of lines(must be odd)  : ";
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		int s = (i<=n/2+1)?(n-(2*(i-1))):(n-(2*(n%i)));   // s to manage leading space
		int k = (i<=n/2+1)?(4*(i-1)+1):(4*(n%i)+1);       // k to manage no. of number outputs for each line
		cout << setw(3 * s) << setfill(' ') << ' ' ;      // to print spaces
		int t = (i<=n/2+1)?(2*i-1):(2*(n%i+1)-1);         // t  to manage the highest number for each line (for i=2, highest number is 3)
		// loop to print number outputs
		for(int j=0 ; j < k ; j++ )
		{			
			cout << setw(3) << setfill(' ') << ((j<t)?(t-j):(t-((t-1)*2)%j));  // printing numbers 
			// setw is explictly set to 3 for neatness in pattern for number greater than 9
		}
		cout << endl ;    // marks the end of line
	}
}
