#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(int** arr) {
    int max = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
        	
            int sum = 0;
            for(int k = 0; k < 3; k++){
                sum += arr[i][j+k];
                sum += arr[i+2][j+k];
            }
            sum += arr[i+1][j+1];
            if(sum > max) max= sum;
        }
    }
    return max;
}

int main()
{
    int** p;
    p = new int*[6];
    for(int i = 0; i < 6; i++){
        p[i] = new int[6];
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> p[i][j];
        }
    }
	
    cout << hourglassSum(p) ; 
    return 0;
}

