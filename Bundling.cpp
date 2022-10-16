#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef struct node{
	node* child[26];
	int count = 0;
}trie;

const int N = 1e5;
int n,k;
trie* root;

string arr[N];

void insert(string &s)
{
	trie* cur = root;
	for(int i = 0; i<s.size(); i++){
		char m = s[i] - 'A';
		if(!cur->child[m])
			cur->child[m] = new trie();
		cur = cur->child[m];
	}
	cur->count++;
}

int res = 0;

void dfs(trie* cur, int lvl)
{
	for(int i = 0; i<26; i++){
		if(cur->child[i]){
			dfs(cur->child[i], lvl+1);
			cur->count += cur->child[i]->count;
		}
	}
	while(cur->count >= k){
		cur->count -= k;
		res += lvl;
	}
}

int main()
{
	int t;
	cin >> t;
	int tc = 0;
	while(t--){
		tc++;
		root = new trie();
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			insert(arr[i]);
		}
		dfs(root, 0);
		cout << "Case #" << tc << ": " << res << "\n";
	}
	return 0;
}

