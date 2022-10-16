#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> result;
    int flag = A[0];
    int k = -1;
    for(int i = 0; i<A.size()-1; i++){
        if(A[i] < A[A.size()-1] ) {
        	//cout << A[i] << "  X\n";
        	flag = A[i];
        	k = i;
        	break;
		}
    }
    if(k == -1) return A;
    
    for(int i = 0; i<k; i++){
        
        result.push_back(A[i]);
    }
    for(int i = A.size()-1; i>=k; i--){
        //cout << A[i] << "XX\n";
        result.push_back(A[i]);
    }
    return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	int k;
	for(int i = 0; i< n; i++){
		cin  >> k;
		arr.push_back(k);
	}
	vector<int> res;
	res = solve(arr);
	for(int i = 0; i<res.size(); i++){
		cout << res[i] << "\n";
	}
	return 0;
}
