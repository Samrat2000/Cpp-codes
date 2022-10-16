#include <bits/stdc++.h>

using namespace std;

//to display pages in the free frames
void display(vector<int> v)
{
	cout << "Free frames' status: ";
  	for(int i = 0; i<v.size(); i++)
  	{
    	cout << v[i] << " ";
   	}
  	cout << "\n";
}

//to find the position of the element to be replaced
int toReplace(map<int, int> mp, vector<int> v)
{
	int small = 0;
	int count = mp[v[0]];
	for(int i = 0; i<v.size(); i++){
		if(count>mp[v[i]]){
			small = i;
			count = mp[v[i]];
		}
	}
	return small;
}

int main()
{
	cout << "*************************************************************\n";
	cout << "          OPTIMAL PAGE REPLACEMENT IMPLEMENTATION            \n";
	cout << "*************************************************************\n\n";
	int f;
	cout << "Enter the number of free frames: ";
	cin >> f;
	if(f==0){
		cout << "No free frames!! Pages cannot be allocated\n";
		exit(0);
	}
	vector<int> v;
	map<int, int> mp;
	int n;
	cout << "Enter number of pages in the sequence: ";
	cin >> n;
	cout << "Enter the page reference sequence: ";
	int arr[n];
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		mp[arr[i]]++;  //to keep count of occurence of each element entered
	}
	int total = 0;
	for(int i = 0; i<n; i++){
		int k = arr[i];
		cout << "\n" << k << " --> ";
		
		//when the page is not present in the free frames
		if(find(v.begin(), v.end(), k)==v.end()){ 
			//when one or more frames are still free
			if(v.size()!=f){
				v.push_back(k);
				cout << "Miss\t"; total++;
				mp[k]--;
				display(v);
			}
			//when no frames are still free
			else if(v.size()==f){
				int m = toReplace(mp, v);
				v.erase(v.begin()+m);
				v.push_back(k);
				cout << "Miss\t"; total++;
				mp[k]--;
				display(v);
			}
		}
		//when the page is present in the free frames
		else{
			cout << "Hit\t";
			mp[k]--;
			display(v);
		}
	}
	cout << "\nTotal number of page faullts: " << total << "\t";
	cout << "\tPage fault rate: " << (total*1.0/n);
	cout << "\n";
}
