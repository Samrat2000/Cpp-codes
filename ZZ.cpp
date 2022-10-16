#include<bits/stdc++.h>
using namespace std;

string Solve (int N) {
   int sum = 1;
   int i;
   for(i=2; i*i <= N ; i++) {
       if(N%i == 0){
           sum = sum+ i + (N/i);
       }
   }
   //cout << "XX" ;
   if(sum == N) return "YES";
   else "NO"; 
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++) {
        int N;
        cin >> N;
        string out = Solve(N);
        cout << out << "\n";
    }
}
