#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout << "*************************************************************\n";
	cout << "            FCFS DISK SCHEDULING IMPLEMENTATION              \n";
	cout << "*************************************************************\n\n";
	int m;
	cout << "Enter total number of tracks on the disk: ";
	cin >> m;
	int head, n, k;
	cout << "Enter number of disk requests: ";
	cin >> n;
	cout << "Enter the disk request sequence: ";
	vector<int> v;
	for(int i = 0; i<n; i++){
		cin >> k;
		v.push_back(k);
	}
	cout << "Enter the head position: ";
	cin >> head;
	int result = 0;
	for(int i = 0; i<n; i++){
		cout << "Track visited: " << v[i] << "\t";
		int j;
		if(i == 0)  j=head;
		else j = v[i-1];
		int diff = abs(v[i]-j);
		cout << "Cylinder movement (" << j << " to " << v[i] << "): "  << diff << "\n";
		result += diff;
	}
	cout << "Total cylinder movement (seek time): " << result << "\n";
}
