#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>&adj, int n)
{
	vector<int>color(n, -1);

	queue<pair<int, int>>Q;

	for (int i = 0; i < n; i++)
	{
		if (color[i] == -1)
		{
			Q.push({i, 0})
			color[i] = 0;

			while (!Q.empty())
			{
				int node = Q.front().first;
				int c = Q.front().second;
				Q.pop();

				for (auto x : adj[node])
				{
					if (color[x] == c)
						return false;
					if (color[x] == -1)
					{
						color[x] = 1 - c;
						Q.push({x, 1 - c});
					}
				}
			}
		}

	}
	return true;;
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
	vector<int>color(n, -1);

	if (bfs(adj, n))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}