#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,unordered_set<int>&vis, int u, int &size){
	// vis[u] = true;
	vis.insert(u);
	// cout << u << " ";
	size++;
	for (int v : adj[u]){
		if (vis.find(v)==vis.end())
			dfs(adj, vis, v, size);
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	// vector<int> adj[n + 1];
	unordered_map<int , vector<int>> adj;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);//if graph is undirected
	}
	// vector<int> vis(n + 1, false);
	unordered_set<int>vis
	int count = 0;
	vector<int> S;
	for (auto x:adj){
		if (vis.find(x.first) == false){
			count++;
			int size = 0;
			dfs(adj, vis, x.first, size);
			S.push_back(size);
		}
	}
	cout << count << endl;

	for (auto x : S)
		cout << x << " ";
	return 0;
}
