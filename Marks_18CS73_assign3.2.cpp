#include <iostream>

using namespace std;

//allocating size of array for[ each department no. of students
void alloc(int **&p)
{
	int c;
	p = new int*[6];
	for(int i=0;i<6;i++)
	{
		cout << "Enter number of students in department" << (i+1) << " : ";
		cin >> c;
		p[i] = new int[c+1];
		p[i][0]=c;
	}
	cout << "\n\n";
	return;
}

//reading the marks of students
void read(int **&p)
{
	for(int i=0;i<6;i++)
	{
		cout << "\nEnter marks for department " << (i+1) << " : " << endl;
		for(int j=1;j<=p[i][0];j++)
		{
			cout << "Student " << j << " : ";
			cin >> p[i][j];
		}
	}
	return;
}

//displaying the marks entered by the user
void display(int **&p)
{
	cout << "\n\n\nPrinting the marks of Students simultaneously department-wise :" << endl;
	for(int i=0;i<6;i++)
	{
		cout << "Marks of students of Department " << (i+1) << " : " << endl;
		for(int j=1;j<=p[i][0];j++)
		{
			cout << "\t" << p[i][j];
		}
		cout << endl;
	}
	return;
}

//deallocating space from the memory
void dealloc(int **&p)
{
	for(int i=0;i<6;i++)
	{
		delete []p[i];
	}
	delete []p;
	p=NULL;
	return;
}

int main()
{
	int **a = NULL;
	alloc(a);
	read(a);
	display(a);
	dealloc(a);
}
