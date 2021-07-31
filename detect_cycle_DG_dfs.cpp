#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool>&stk, int node)
{
	vis[node] = true;
	stk[node] = true;

	for (auto x : adj[node])
	{
		if (stk[x] == true)
			return true;
		else if (!vis[x] && dfs(adj, vis, stk, x))
			return true;
	}
	stk[node] = false;
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<bool>vis(n, false), stk(n, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && dfs(adj, vis, i, stk))
		{
			flag = true;
			break;
		}
	}
	cout << flag << endl;
}