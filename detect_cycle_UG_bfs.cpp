#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>&adj, vector<bool>&vis, int src, int n)
{
	vis[src] = true;
	vector<int>parent(n, -1);
	queue<int> Q;
	Q.push(src);
	bool flag = false;
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		for (auto x : adj[node])
		{
			if (!vis[x])
			{
				vis[x] = true;
				Q.push(x);
				parent[x] = node;
			}
			else if (x != parent[u])
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
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
	vector<bool>vis(n, false);

	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && bfs(adj, vis, i, n))
		{
			flag = true;
			break;
		}
	}

	flag ? cout << "Yes \n" : cout << "No \n";
	return 0;
}