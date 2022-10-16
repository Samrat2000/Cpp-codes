#include <bits/stdc++.h>
using namespace std;

//to display pages in the free frames
void display(queue<int> q)
{
	cout << "Free frames' status: ";
  	while (!q.empty())
  	{
   		cout << q.front() << " ";
    	q.pop();
  	}
  	cout << "\n";
}

int main()
{
	cout << "*************************************************************\n";
	cout << "            FIFO PAGE REPLACEMENT IMPLEMENTATION             \n";
	cout << "*************************************************************\n\n";
	int f;
	cout << "Enter the number of free frames: ";
	cin >> f;
	queue<int> q;
	set<int> s;
	int n;
	cout << "Enter number of pages in the sequence: ";
	cin >> n;
	cout << "Enter the page reference sequence: ";
	int arr[n];
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int total = 0;
	for(int i = 0; i<n; i++){
		int k = arr[i];
		cout << "\n"<< k << " --> ";
		
		//when the page is not present in the free frames
		if(s.find(k)==s.end()){
			//when one or more frames are still free
			if(q.size()!=f){
				s.insert(k);
				q.push(k);
				cout << "Miss\t"; total++;
				display(q);
			}
			//when no frames are still free
			else if(q.size()==f){
				int m = q.front();
				q.pop();
				s.erase(m);
				q.push(k);
				s.insert(k);
				cout << "Miss\t"; total++;
				display(q);
			}
		}
		//when the page is present in the free frames
		else{
			cout << "Hit\t";
			display(q);
		}
	}
	cout << "\nTotal number of page faullts: " << total << "\t";
	cout << "\tPage fault rate: " << (total*1.0/n);
	cout << "\n";
}

