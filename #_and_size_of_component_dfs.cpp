#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], vector<int>&vis, int u, int &size)
{
	vis[u] = true;
	// cout << u << " ";
	size++;
	for (int v : adj[u])
	{
		if (!vis[v])
			dfs(adj, vis, v, size);
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
		adj[b].push_back(a);//if graph is undirected
	}
	vector<int> vis(n + 1, false);
	int count = 0;
	vector<int> S;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == false)
		{
			count++;
			int size = 0;
			dfs(adj, vis, i, size);
			S.push_back(size);
		}
	}
	cout << count << endl;

	for (auto x : S)
		cout << x << " ";
	return 0;
}