#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, source;

	cin >> n >> m;

	vector < vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> source;
	vector<int> vis(n + 1, -1);

	queue<int> Q;


	vis[source] = 0;
	Q.push(source);

	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		// cout << node << " ";
		for (auto x : adj[node])
		{
			if (vis[x] != -1)
				continue;
			vis[x] = vis[node] + 1;
			Q.push(x);
		}
	}
	for (auto x : vis)
		cout << x << " ";
}