#include <bits/stdc++.h>

using namespace std;

int shortestPath(int n, vector<int>adj[], int s, int d)
{
	vector<int> dist[n];
	vector<int> visited[n];
	visited[s] = 1;
	for(int i = 0; i<adj[s].size(); i++){
		dist[adj[s][i]] = 1;
	}
	for(int i = 0; i<n; i++){
		if(i != s && dist[i]!=1)dist[i] = INT_MAX;
	}
	while(1)
	{
		
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	int a,b;
	for(int i = 0; i<m; i++){
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int s, d;
	cin >> s >> d;
	//int res = shortestPath(n, adj, s-1, d-1);
	//cout << res << endl;
	return 0;
}
