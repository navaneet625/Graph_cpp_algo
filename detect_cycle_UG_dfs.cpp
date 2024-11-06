#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>> & adj, vector<bool> &vis, int node, int parent){
	// vis[node] = true;
	vis.insert(node);
	for (auto x : adj[node]){
		if(x==parent) continue;
		if(vis.find(x)!=vis.end()) return true;
		if (dfs(adj, vis, x, node))
			return true;
	}
	return false;
}

int main(){
	int n, m,a,b;
	cin >> n >> m;

	// vector<vector<int>> adj(n);
	unordered_map<int,vector<int>>adj

	for (int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// vector<bool> vis(n, false);
	unordered_set<int>vis;

	bool ans = false;
	for (auto x:adj){
		if (vis.find(x.first)==vis.end() && dfs(adj, vis, x.first, -1)){
			ans = true;
			break
		}
	}
	ans ? cout << "Yes \n" : cout << "No \n";
}
