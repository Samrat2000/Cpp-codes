#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int arr[n][m], sum[n][m];
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cin >> arr[i][j];
			}
		}
		
		if(arr[n-1][m-1] < k){
			cout << "0\n";
			continue; 
		}
		
		
		// sum preprocess:
			//Row-wise sum
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(j == 0) sum[i][0] = arr[i][0];
				else sum[i][j] = sum[i][j-1] + arr[i][j];
			}
		}
		
			//Column-wise sum
		for(int i = 1; i<n; i++){
			for(int j = 0; j<m; j++){
				sum[i][j] += sum[i-1][j];
			}
		}
		
		// done sum preprocessing
		
		/*for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cout << sum[i][j] << " ";
			}
			cout << "\n";
		}*/
		
		int ans = 0;
		
		// for 1x1 submatrix
		for(int i = 0; i<n; i++){
			if(arr[i][0] >= k){
				//cout << "XX" << i << " 0\n";
				ans += ((n-i)*m);
				break;
			}
			int l = 0, h = m-1;
			int mid;
			while(l<=h){
				mid = l + (h-l)/2;
				if(mid == 0){
					l = mid+1;
					continue;
				}
				if(arr[i][mid] >= k && arr[i][mid-1] < k){
					//cout << "XX" << i << " " << mid << "\n";
					ans+=(m-mid);
					break;
				}
				else if(arr[i][mid] >= k && arr[i][mid-1] >= k){
					h = mid-1;
				}
				else if(arr[i][mid] < k && arr[i][mid-1] < k){
					l = mid + 1;
				}
			}
		}
		
		//cout << ans << endl;
		
		
		// for lxl submatrices
		
		for(int mi = 1; mi<n; mi++)
		{
			int s = (mi+1)*(mi+1);
			for(int i = 0; i<(n-mi); i++){
				
				if((i == 0 && (sum[i+mi][mi]/s)>= k) || (i != 0 && ((sum[i+mi][mi] - sum[i-1][mi])/s) >= k)){
					//cout << "XX" << i << " " << 0 << " " << mi << "\n";
					ans += ((n-i-mi)*(m-mi));
					//cout << "XXXX  " << (n-i-mi) << " " << (m-mi) << " " << ans << endl;
					break;
				}
				
				int l = 0, h = m-mi-1;
				int mid;
				while(l<=h){
					mid = l+(h-l)/2;
					if(mid == 0){
						l = mid+1;
						continue;
					}
					int mcurr, mprev;
					if(i == 0){
						if(mid > 0) mcurr = (sum[i+mi][mid+mi] - sum[i+mi][mid-1])/s;
						if((mid-1) > 0) mprev = (sum[i+mi][mid-1+mi] - sum[i+mi][mid-2])/s;
						else if((mid-1) == 0) mprev = sum[i+mi][mid-1+mi]/s;
					}
					else if(i>0){
						if(mid > 0) mcurr = (sum[i+mi][mid+mi] - sum[i+mi][mid-1] - sum[i-1][mid+mi] + sum[i-1][mid-1])/s;
						if((mid-1) > 0) mprev = (sum[i+mi][mid-1+mi] - sum[i+mi][mid-2] - sum[i-1][mid-1+mi] + sum[i-1][mid-2])/s;
						else if((mid-1) == 0) mprev = (sum[i+mi][mid-1+mi] - sum[i-1][mid-1+mi])/s;
					}
					
					
					if(mcurr >= k && mprev < k){
						//cout << "XX" << i << " " << mid << " " << mi << "\n";
						ans+=(m-mid-mi);
						//cout << m << mid << mi << "YYY\n";
						break;
					}
					else if(mcurr >= k && mprev >= k){
						h = mid-1;
					}
					else if(mcurr < k && mprev < k){
						l = mid + 1;
					}
				}
			}
		}
		
		
		
		cout << ans << "\n";
		
	}
}
