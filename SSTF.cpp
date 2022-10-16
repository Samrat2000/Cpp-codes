#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout << "*************************************************************\n";
	cout << "            SSTF DISK SCHEDULING IMPLEMENTATION              \n";
	cout << "*************************************************************\n\n";
	int m;
	cout << "Enter total number of tracks on the disk: ";
	cin >> m;
	int head, n, in;
	cout << "Enter number of disk requests: ";
	cin >> n;
	cout << "Enter the disk request sequence: ";
	vector<int> v;
	for(int i = 0; i<n; i++){
		cin >> in;
		v.push_back(in);
	}
	cout << "Enter the head position: ";
	cin >> head;
	v.push_back(head);
	sort(v.begin(), v.end());
	int result = 0;
	int i = 0;
	for(; i<=n; i++){
		if(v[i] == head) break;
	}
	int j, k;
	while(v.size()>1){
		j = v[i];
		if(i == 0) {
			k = v[i+1];
			v.erase(v.begin()+i);
		}
		else if(i == v.size()-1) {
			k = v[i-1];
			v.erase(v.begin()+i); i = i-1;
		}
		else if(v[i]-v[i-1] <= v[i+1]-v[i]){
			k = v[i-1];
			v.erase(v.begin()+i); i = i-1;
		}
		else {
			k = v[i+1];
			v.erase(v.begin()+i);
		}
		
		cout << "Track visited: " << k << "\t";
		int diff = abs(k-j);
		cout << "Cylinder movement (" << j << " to " << k << "): "  << diff << "\n";
		result += diff;
	}
	cout << "Total cylinder movement (seek time): " << result << "\n";
}
