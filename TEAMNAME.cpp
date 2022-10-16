#include <bits/stdc++.h>

using namespace std;

int commonele(auto &pair1, auto &pair2)
{
	vector<char> v1(min(pair1.size(), pair2.size()));
	auto itend = set_intersection(pair1.begin(), pair1.end(), pair2.begin(), pair2.end(), v1.begin());
	return (itend-v1.begin());
}


int main()
{
	
	
	/*int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		map<string, int> container;
		set<char> pref;
		set<string> suff;
		for(int i = 0; i<n; i++){
			cin >> s;
			container[s] = 1;
			pref.insert(s[0]);
			suff.insert(s.substr(1, s.length()-1));
		}
		
		/*cout << "The prefixes are: " << endl;
		for(const auto& e:pref){
			cout << e << endl;
		}
		cout << "The suffixes are: " << endl;
		for(const auto& e:suff){
			cout << e << endl;
		}*
		set<string> good;
		for(const auto &i:pref){
			for(const auto &j:suff){
				if(container[i+j]!=1) good.insert(i+j);
			}
		}
		/*cout << "The good names are: " << endl;
		for(const auto& e:good){
			cout << e << endl;
		}*
		int count = 0;
		for(const auto &i:good){
			string str = i;
			good.erase(i);
			for(const auto &j:good){
				//if(i==j) continue;
				if(container[j[0]+str.substr(1,str.length()-1)]==1 && container[str[0]+j.substr(1,j.length()-1)]==1)
					count++;
			}
		}
		cout << count*2 << endl; */
		
		
		int t;
		cin >> t;
		while(t--){
			int n;
			string s;
			cin >> n;
			map<string, set<char>> container;
			for(int i = 0; i<n; i++){
				cin >> s;
				container[s.substr(1)].insert(s[0]);
			}
			int count = 0;
			for(auto &i: container){
				for(auto &j: container){
					if(i!=j){
						int k = commonele(i.second, j.second);
						count += (i.second.size()-k)*(j.second.size()-k);
					}
				}
			}
			cout << count << endl;
		}
		
	
	return 0;
}
