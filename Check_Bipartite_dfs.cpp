#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>&adj, vector<int>&vis, int node, int parent, int color)
{
	vis[node] = color;
	for (auto nbr : adj[node])
	{
		if (vis[nbr] == 0)
		{
			if (!dfs(adj, vis, nbr, node, 3 - color))
				return false;
		}
		else if (nbr != parent && color == vis[nbr])
			return false;
	}
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> vis(n + 1, 0);

	int parent = -1, color = 1, src = 0;
	if (dfs(adj, vis, src, parent, color))
		cout << "Yes " << endl;
	else
		cout << "No " << endl;
}