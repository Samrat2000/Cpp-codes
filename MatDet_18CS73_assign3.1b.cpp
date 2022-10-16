#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//allocation of matrix space
void alloc(int **&p,int &r)
{
	cout << "Enter number of rows/columns for square matrix : " ;
	cin >> r;
	p = new int*[r];
	for(int i=0;i<r;i++)
	{
		p[i] = new int[r];
	}
	return;
}

//for reading matrix from user
void read(int **&p,int &r)
{
	cout << "Enter elements row-wise : " << endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++)
		{
			cin >> p[i][j];
		}
	}
	return;
}

//for displaying the matrix user entered
void show(int **&p,int &r)
{
	cout << "Matrix to find determinant is " << endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout << setw(4) << p[i][j];
		}
		cout << endl;
	}
	return;
}

//for deallocation of space assigned to matrices
void dealloc(int **&p,int &r)
{
	for(int i=0;i<r;i++)
	{
		delete []p[i];
	}
	delete []p;
	p=NULL;
	return;
}

//for computing the determinant using recursion
double deter(int **p, int r)
{
	double d;
	int c,subi,i,j,subj;
	int **submat=NULL;
	submat = new int*[r];
	for(i=0;i<r;i++)
	{
		submat[i] = new int[r];
	}
	if(r==2)
		return ((p[0][0]*p[1][1])-(p[1][0]*p[0][1]));
	else
	{
		for(c=0;c<r;c++)
		{
			subi=0;
			for(i=1;i<r;i++)
			{
				subj=0;
				for(j=0;j<r;j++)
				{
					if(j==c)
						continue;
					submat[subi][subj] = p[i][j];
					subj++;
				}
				subi++;
			}
			d += (pow(-1,c) * p[0][c] * (deter(submat,r-1)));
		}
	}
	dealloc(submat,r);
	return d;
}

int main()
{
	int n;
	int **a=NULL;
	alloc(a,n);
	read(a,n);
	show(a,n);
	double det=deter(a,n);
	cout << "Determinent of the matrix entered is : " << det << endl;
	dealloc(a,n);
}
