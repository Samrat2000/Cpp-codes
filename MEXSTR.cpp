#include <bits/stdc++.h>

using namespace std;

void getSubsequence(set<string> &sub, string str, int n, int index = -1, string curr = "")
{
	if (index == n)
        return;
 
    if (!curr.empty()) {
        //cout << curr << "\n";
        sub.insert(curr);
    }
 
    for (int i = index + 1; i < n; i++) {
 		
 		if(curr == "0" && str[i] == '0') continue;
 		
 		if(curr == "0" && str[i] == '1') curr = "1";
        else curr += str[i];
        
        if(sub.count(curr)){
        	curr = curr.erase(curr.size() - 1);
        	continue;
		} 
        
        getSubsequence(sub, str, n, i, curr);
 
        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		set<string> subs;
		getSubsequence(subs, s, s.size());
		//for (auto it = subs.begin(); it != subs.end(); ++it)
        //	cout << *it << "\n";
        
        
        if(subs.count("0") == 0) {
        	cout << "0\n";
        	continue;
		}
        queue<string> q;
 
    	q.push("1");
 
    	while (1) {
        	string s1 = q.front();
        	q.pop();
        	if(subs.count(s1) == 0) {
        		cout << s1 << "\n";
        		break;
			}
 
        	string s2 = s1; 
        	q.push(s1.append("0"));
 
        	q.push(s2.append("1"));
    	}
	}
}
