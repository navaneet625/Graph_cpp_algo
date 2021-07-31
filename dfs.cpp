#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[], vector<int>&vis, int u)
{
	vis[u] = true;
	cout << u << " ";
	for (int v : adj[u])
	{
		if (!vis[v])
			dfs(adj, vis, v);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		//adj[b].push_back(a);//if graph is undirected
	}
	vector<int> vis(n + 1, false);
	dfs(adj, vis, 1);
	return 0;
}