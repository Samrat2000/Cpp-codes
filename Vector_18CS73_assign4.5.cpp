#include <iostream>

using namespace std;

class Vector
{
	private:
		//data memebers
		int *arr;
	public:
		int size;
		
		
		//Constructor
		Vector(int l)
		{
			size=l;
			arr=new int[size];
		}
		
		//Destructor
		~Vector()
		{
			delete []arr;
		}
		
		void accept();
		void dotProduct(Vector &a);
		void scalarMult(int k);
		void vectorAdd(Vector &a);
		void vectorSub(Vector &a);
};


//Accept vector
void Vector::accept()
{
	for(int i=0;i<size;i++)
	{
		cin >> arr[i];
	}	
}

//Dot Prduct
void Vector::dotProduct(Vector &a)
{
	int s=(a.size<=size)?(a.size):(size);
	int pro = 0;
	for(int i=0;i<s;i++)
	{
		pro += a.arr[i] * arr[i];
	}
	cout << "Dot Product of these vectors are : " << pro <<endl;
}

//Scalar Product
void Vector::scalarMult(int k)
{	
	for(int i=0;i<size;i++)
	{
		arr[i]=k* arr[i];
	}
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << "\t";
	}
}

//Vector Addition
void Vector::vectorAdd(Vector &a)
{
	int s=(size<=a.size)?(size):(a.size);  
	size=(size>a.size)?(size):(a.size);
	for(int i=0;i<s;i++)
	{
		arr[i] += a.arr[i];
	}
	while(s<a.size)
	{
		arr[s]= a.arr[s];
		s++;
	}
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << "\t";
	}
}

//Vector Subtraction
void Vector::vectorSub(Vector &a)
{
	int s=(size<=a.size)?(size):(a.size); 
	size=(size>a.size)?(size):(a.size);
	for(int i=0;i<s;i++)
	{
		arr[i] -= a.arr[i];
	}
	while(s<a.size)
	{
		arr[s]= -1*a.arr[s];
		s++;
	}
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << "\t";
	}
}


int main()
{
	while(1)
	{
		int c,k,len,len1;
		cout << "\n1.Dot Product \n2.Scalar Multiplication \n3.Vector Addition \n4.Vector Subtraction \n5.Exit \nEnter your choice : ";
		cin >> c;
		switch(c)
		{
			case 1: {
					cout << "Enter the length of the 1st array : ";
					cin >> len;
					Vector v(len);
					cout <<"Enter the elements of this array : " << endl;
					v.accept();
					cout << "Enter the length of the 2nd array : ";
					cin >> len1;
					Vector v1(len1);
					cout <<"Enter the elements of this array : " << endl;
					v1.accept();
					v.dotProduct(v1);
				}
				break;
					
			case 2: {
					cout << "Enter the length of the array : ";
					cin >> len;
					Vector v(len);
					cout <<"Enter the elements of this array : " << endl;
					v.accept();
					cout << "Enter the element to be multiplied : ";
					cin >> k;
					v.scalarMult(k);
				}
				break;
				
			case 3: {
					cout << "Enter the length of the 1st array : ";
					cin >> len;
					Vector v(len);
					cout <<"Enter the elements of this array : " << endl;
					v.accept();
					cout << "Enter the length of the 2nd array : ";
					cin >> len1;
					Vector v1(len1);
					cout <<"Enter the elements of this array : " << endl;
					v1.accept();
					cout << "Vector addition of the above vectors is : " << endl;
					v.vectorAdd(v1);
				}
				break;
				
			case 4: {
					cout << "Enter the length of the 1st array : ";
					cin >> len;
					Vector v(len);
					cout <<"Enter the elements of this array : " << endl;
					v.accept();
					cout << "Enter the length of the 2nd array : ";
					cin >> len1;
					Vector v1(len1);
					cout <<"Enter the elements of this array : " << endl;
					v1.accept();
					cout << "Vector subtraction of 2nd vector from 1st vector is : " << endl;
					v.vectorSub(v1);
				}
				break;
				
			case 5: exit(0);
		}
	}
}
