#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>> &adj, unordered_set<int> &vis,int node, unordered_map<int,bool>&stk){
	vis.insert(node);
	stk[node]=true;

	for (auto x : adj[node]){
		if (stk[x])
			return true;
		else if (vis.find(x)==vis.end() && dfs(adj, vis,x, stk))
			return true;
	}
	stk[node] = false;
	return false;
}

int main(){
	int n, m,a,b;
	cin >> n >> m;
	unordered_map<int,vector<int>>adj;
	unordered_set<int>vis;
	unordered_map<int,bool>stk;

	for (int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
	}
	bool flag = false;
	for (auto x:adj){
		if (vis.find(x.first)==vis.end() && dfs(adj, vis, i, stk)){
			flag = true;
			break;
		}
	}
	cout << flag << endl;
}
