#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int src, int n, int &ans)
{
	vector<int> dist(n + 1, INT_MAX);
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;

	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		for (auto nbr : adj[node])
		{
			if (dist[nbr] == INT_MAX)
			{
				Q.push(nbr);
				dist[nbr] = dist[node] + 1;
			}
			else if (dist[nbr] >= dist[node]) // backedges..
			{
				ans = min(ans, dist[nbr] + dist[node] + 1);
			}
		}
	}
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

	int ans = n + 1;
	for (int i = 0; i < n; i++)
	{
		bfs(adj, i, n, ans);
	}
	if (ans == n + 1)
		cout << "Cycle note present int the given garph " << "\n";
	else
		cout << "Shortest Cycle length is :" << ans << "\n";
}