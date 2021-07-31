#include<bits/stdc++.h>
using namespace std;

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
	}

	vector<int>indegree(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (auto x : adj[i])
			indegree[x]++;
	}

	queue<int> Q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty())
	{
		int node = Q.front();
		cout << node << " ";
		Q.pop();

		for (auto x : adj[node])
		{
			indegree[x]--;
			if (indegree[x] == 0)
				Q.push(x);
		}
	}
	cout << endl;
}