#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool>&vis, stack<int>&st, int node)
{
	vis[node] = true;
	for (auto nbr : adj[node])
	{
		if (!vis[nbr])
			dfs(adj, vis, st, nbr);
	}
	st.push(node);
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
	}
	vector<bool>vis(n + 1, false);

	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == false)
			dfs(adj, vis, st, i);
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}