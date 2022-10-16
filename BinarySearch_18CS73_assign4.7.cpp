#include <iostream> 

using namespace std; 
  
// A recursive binary search function
int binarySearch(int *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
  
int main() 
{ 
	cout << "Enter the size of the array : ";
	int len,x;
	cin >> len;
    int *arr;
    arr = new int[len];
    cout << "Enter the elements : " << endl;
	for(int i=0;i<len;i++)
	{
		cin >> arr[i];	
	} 
	cout << "Enter the element to bw searched : ";
	cin >> x;
    int result = binarySearch(arr, 0, len - 1, x); 
    if (result == -1) 
		cout << x << " is not present in array" << endl;
	else
        cout << x << " is present at index " << result << endl;
        
    delete []arr;
}
