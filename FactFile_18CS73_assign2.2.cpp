#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// To multiply the number in array with the next number
int multiply(int x,int mul[],int mul_size)
{
	int c = 0;
	// for loop to read each digit from which is multiplied to x and carry is added to it 
	for(int i=0;i<mul_size;i++)
	{
		int prod = x*mul[i] + c ; 
		mul[i] = prod%10;
		c = prod/10;
	}
	//while is used when carry digits are left after multiplication
	while(c!=0)
	{
		mul[mul_size]=c%10;
		c=c/10;
		mul_size+=1;
	}
	return mul_size;
}

// To find the factorial using multiply function
int factorial_size ( int n )
{
	int fact[500] ;
	int fact_size = 1;
	fact[0] = 1;
	for (int i=2;i<=n;i++)
	{
		fact_size = multiply(i,fact,fact_size) ;
	}
	/*cout << "Printing factorial : " << endl ;
	for(int j=fact_size-1;j>=0;j--)
	{
		cout << fact[j];
	}*/
	return fact_size;
}

int main()
{
	int n,i,fact;
	cout << "Enter the number upto which factorial of digit is required" ;
	cin >> n;
	ofstream myfile;
  	myfile.open ("example.txt");
  	myfile << "Number\t\tDigits" <<endl;
  	for(i=2;i<=n;i++)
  	{
  		myfile << setw(6) << i << "\t\t" << setw(6) << factorial_size(i) <<endl;
	}
  	myfile.close();
}
