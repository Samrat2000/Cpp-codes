#include <iostream>
using namespace std;

int middle(int arr[]){
	//int* start = (int*) (&arr);
	//int* end = (int*) (&arr+1);
	//cout << start << endl;
	//cout << end << endl;
	int res = (*(&arr+1)-arr);
	return res;
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	int mid = middle(a);
	cout << (*(&a+1)-a);
	return 0;
}
