#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int flag;
	for(int i=0; i<n-1; i++)
	{
		flag = 0;
		for(int j = 0; j < n-i-1 ; j++)
		{
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		
		if(flag == 0) break;
	}
}

int find()
{
	int m;
	cin >> m;
	int* a = new int[m];
	for(int i=0 ; i < m ; i++)
	{
		cin >> a[i];
	}
	
	bubbleSort(a, m);
	
	int c=1;
	
	int k = m-1;
		
	for(; k>0; k--)
	{
		if(a[k]!=a[k-1]){
			c++;
		}
	}
	return c;	
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t ; i++)
	{
		cout << find() << endl;
	}
	/*for(int i = 0; i < t ; i++)
	{
		cout << arr[i] << endl;
	}*/
}
