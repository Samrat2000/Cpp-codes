#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout << "*************************************************************\n";
	cout << "           C-SCAN DISK SCHEDULING IMPLEMENTATION             \n";
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
	char dir;
	cout << "Enter the direction of head movement(l=left/r=right): ";
	cin >> dir;
	sort(v.begin(), v.end());
	int result = 0;
	int i = 0;
	for(; i<v.size(); i++){
		if(v[i] == head) break;
	}
	int j, k;
	switch(dir)
	{
		case 'l':
		case 'L':
			if(v[v.size()-1] != head){
				if(find(v.begin(), v.end(), 0)==v.end()){ v.insert(v.begin(), 0); i=i+1;}
				if(find(v.begin(), v.end(), m-1)==v.end()) v.push_back(m-1);
			} 
			while(v.size()>1){
				j = v[i];
				if(i == 0) {
					k = v[v.size()-1];
					v.erase(v.begin()+i); i = v.size()-1;
				}
				else{
					k = v[i-1];
					v.erase(v.begin()+i); i = i-1;
				}
				cout << "Track visited: " << k << "\t";
				int diff = abs(k-j);   if(diff == m-1) diff = 0;
				cout << "Cylinder movement (" << j << " to " << k << "): "  << diff << "\n";
				result += diff;
			}
			break;
			
		case 'r':
		case 'R':
			if(v[0] != head){
				if(find(v.begin(), v.end(), 0)==v.end()){ v.insert(v.begin(), 0); i=i+1;}
				if(find(v.begin(), v.end(), m-1)==v.end()) v.push_back(m-1);
			} 
			while(v.size()>1){
				j = v[i];
				if(i == v.size()-1) {
					k = v[0];
					v.erase(v.begin()+i); i = 0;
				}
				else{
					k = v[i+1];
					v.erase(v.begin()+i);
				}
				cout << "Track visited: " << k << "\t";
				int diff = abs(k-j);       if(diff == m-1) diff = 0;
				cout << "Cylinder movement (" << j << " to " << k << "): "  << diff << "\n";
				result += diff;
			}
			break;
		
		default: 
			cout << "Wrong direction(exiting)!!!\n";
			exit(0);
	}
	cout << "Total cylinder movement (seek time): " << result << "\n";
}
