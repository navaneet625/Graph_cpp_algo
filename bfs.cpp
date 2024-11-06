#include<bits/stdc++.h>
using namespace std;
int main(){

	int n_nodes, n_edges;
	cin >> n_nodes >> n_edges;
	// vector<vector<int>> adj(n_nodes + 1);
	unordered_map<int,vector<int>> adj;
	for (int i = 0; i < n_edges; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a)//if graph is undirected
	}
	queue<int> Q;
	// vector<bool> visited(n_nodes + 1, false);
	unordered_set<int>visited;
	int source;
	cin>>source; // it should be the name of existing node 
	visited.insert(source);
	Q.push(source);
	while (!Q.empty()){
		int node = Q.front();
		Q.pop();
		cout << node << " ";
		for (int neighbour : adj[node]){
			if (visited.find(neighbour)==visisted.end())
				continue;
			// visited[neighbour] = true/
			visited.insert(neighbour);
			Q.push(neighbour);
		}
	}
	return 0;
}
