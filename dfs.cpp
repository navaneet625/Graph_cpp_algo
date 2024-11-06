#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>&adj, unordered_set<int>&vis, int u){
	// vis[u] = true;
	vis.insert(u);
	cout << u << " ";
	for (int v : adj[u]){
		if (vis.find(v)==vis.end())
			dfs(adj, vis, v);
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	// vector<int> adj[n + 1];
	unordered_map<int,vector<int>>adj;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);//if graph is undirected
	}
	// vector<int> vis(n + 1, false);
	unordered_set<int> vis
	dfs(adj, vis, 1);
	return 0;
}
