#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
	// data members
	private:
		 int **a, r, c;
	public :
		//Constructor
		Matrix(int row, int col)
		{
			r = row;
			c = col;
			a = new int*[r];
			for(int i=0;i<r;i++)
			{
				a[i] = new int[c];
			}
		}
		
		//Destructor
		~Matrix()
		{
			for(int i=0;i<r;i++)
			{
				delete []a[i];
			}
			delete []a;
		}
		
		void accept()
		{
			cout << "Enter the elements of matrix row-wise : " << endl;
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cin >> a[i][j] ;
				}
			}
		}
		
		void display()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout << setw(4) << a[i][j] << "  ";
				}
				cout << endl;
			}
		}
		
		void add(Matrix &m1,Matrix &m2);
		void sub(Matrix &m1,Matrix &m2);
		void mult(Matrix &m1,Matrix &m2);
};

void Matrix::add(Matrix &m1,Matrix &m2)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a[i][j] = m1.a[i][j] + m2.a[i][j];
		}
	}
}

void Matrix::sub(Matrix &m1,Matrix &m2)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a[i][j] = m1.a[i][j] - m2.a[i][j];
		}
	}
}

void Matrix::mult(Matrix &m1,Matrix &m2) 
{ 
    int x, i, j; 
    for (i = 0; i < m1.r; i++)  
    { 
        for (j = 0; j < m2.c; j++)  
        { 
            a[i][j] = 0; 
            for (x = 0; x < m1.c; x++)  
            { 
                a[i][j] += m1.a[i][x] * m2.a[x][j]; 
            } 
        } 
    } 
} 

int main()
{
	int r1,r2,c1,c2,c;
	cout << "Enter the number of rows of 1st matrix : ";
	cin >> r1;
	cout << "Enter the number of columns of 1st matrix : ";
	cin >> c1;
	cout << "Enter the number of rows of 2nd matrix : ";
	cin >> r2;
	cout << "Enter the number of columns of 1st matrix : ";
	cin >> c2;
	Matrix m1(r1,c1);
	Matrix m2(r2,c2);
	m1.accept();
	cout<< "The matrix1 entered is : " <<endl;
	m1.display();
	m2.accept();
	cout<< "The matrix2 entered is : " <<endl;
	m2.display();
	Matrix sum(r1,c1) , subtract(r1,c1) , prod(r1,c2);
	cout << "1.Addition \n2.Subtraction \n3.Multiplication \nEnter your choice : ";
	cin >> c;
	
	switch(c)
	{
		case 1: //Matrix Addition
				if(r1!=r2 || c1!=c2)
				{
					cout << "Incompatibale matrix size for operation!!"  << endl;
					exit(0);
				}
				sum.add(m1,m2);
				cout << "The sum of matrices is : " << endl;
				sum.display();
				break;
		case 2: //Matrix Subtraction
				if(r1!=r2 || c1!=c2)
				{
					cout << "Incompatibale matrix size for operation!!"  << endl;
					exit(0);
				}
				subtract.sub(m1,m2);
				cout << "The difference of matrix1 from matrix2 is : " << endl;
				subtract.display();
				break;
		case 3: //Matrix Multiplication
				if(r2!=c1)
				{
					cout << "Incompatibale matrix size for operation!!"  << endl;
					exit(0);
				}
				prod.mult(m1,m2);
				cout << "The product of matrices is : " << endl;
				prod.display();
	}
}
