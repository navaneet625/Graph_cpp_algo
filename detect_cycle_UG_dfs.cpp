#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> & adj, vector<bool> &vis, int node, int parent)
{
	vis[node] = true;
	for (auto x : adj[node])
	{
		if (!vis[x] && dfs(adj, vis, x, node))
			return true;
		else if (x != parent)
			return true;
	}
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> vis(n, false);

	int src;
	cin >> src;
	bool ans = false;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && dfs(adj, vis, src, -1))
		{
			ans = true;
			break
		}
	}
	ans ? cout << "Yes \n" : cout << "No \n";
}