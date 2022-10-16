#include <iostream>

using namespace std ;

//for reading the matrices from user
void read_arr(int **a,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
        	cin >> a[i][j];
        }
    }
}

//to perform multiplication of matrices
int** multiply(int m1, int m2, int **mat1, int n1, int n2, int **mat2) 
{ 
    int x, i, j; 
    int **res; 
    res = new int*[m1] ;
	for(int k = 0;k<m1;k++)
	{
		res[k] = new int[n2];
	}
    for (i = 0; i < m1; i++)  
    { 
        for (j = 0; j < n2; j++)  
        { 
            res[i][j] = 0; 
            for (x = 0; x < m2; x++)  
            { 
                res[i][j] += mat1[i][x] * mat2[x][j]; 
            } 
        } 
    } 
    return res;
} 

//for printing the multiplied matrix
void print_arr(int **m, int m1, int n2)
{
    int i,j;
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

//for deallocation of space assigned to matrices
void dealloc(int &r,int &c,int **&p)
{
	for(int i=0;i<r;i++)
	{
		delete []p[i];
	}
	delete []p;
	p=NULL;
	return;
}

int main()
{
	int r1,c1,r2,c2 ;
	cout << "Enter number of rows in 1st matrix : " ;
	cin >> r1 ;
	cout << "Enter number of columns of 1st matrix : " ;
	cin >> c1 ;
	cout << "Enter number of rows in 2nd matrix : " ;
	cin >> r2 ;
	cout << "Enter number of columns of 2nd matrix : " ;
	cin >> c2 ;
	int **a,**b;
	a = new int*[r1] ;
	for(int i = 0;i<r1;i++)
	{
		a[i] = new int[c1];
	}
	b = new int*[r2] ;
	for(int i = 0;i<r2;i++)
	{
		b[i] = new int[c2];
	}
	cout << "The dimensions of the matrices are " << r1 << " x " << c1 << " and " << r2 << " x " << c2 << endl;
	cout << "\n\nEnter the elements of 1st matrix (row-wise)" << endl;
	read_arr(a,r1,c1);
	cout << "\n\nEnter the elements of 2nd matrix (row-wise)" << endl;
	read_arr(b,r2,c2);
	int **mult;
	mult = multiply(r1,r2,a,c1,c2,b);
	cout << "The matrix after multiplication is" << endl;
	print_arr(mult,r1,c2);
	dealloc(r1,c1,a);
	dealloc(r2,c2,b);
	dealloc(r1,c2,mult);
}
