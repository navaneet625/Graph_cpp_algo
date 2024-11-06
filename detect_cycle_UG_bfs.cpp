#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int,vector<int>>&adj,unordered_set<int>&vis ,int src){
	vis.insert(src);
	unordered_map<int,int>parent;
	queue<int> Q;
	Q.push(src);
	bool flag = false;
	while (!Q.empty()){
		int node = Q.front();
		Q.pop();
		for (auto x : adj[node]){
			if (vis.find(x)==vis.end()){
				vis.insert(x);
				Q.push(x);
				parent[x] = node;
			}
			else if (x != parent[node]){
				flag = true;
				break;
			}
		}
	}
	return flag;
}

int main(){
	int n, m,a,b;
	cin >> n >> m;
	unordered_map<int,vector<int>>adj;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	unordered_set<int>vis;
	bool flag = false;

	for (auto x:adj){
		if (vis.find(x.first)==vis.end() && bfs(adj, vis, i)){
			flag = true;
			break;
		}
	}

	flag ? cout << "Yes \n" : cout << "No \n";
	return 0;
}
