#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>


int prims_mst(priority_queue < pii, vector<pii>, greater<pii >>&Q, vector<int>&vis, vector<vector<pii>>&adj)
{
	int ans = 0;

	Q.push({0, 0});

	while (!Q.empty())
	{
		auto node = Q.top();
		Q.pop();
		int v = node.second;
		int wt = node.first;

		if (vis[v])
			continue;
		ans += wt;
		vis[v] = 1;

		for (auto x : adj[v])
		{
			if (vis[x.first] == 0)
				Q.push({x.second, x.first});
		}
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;

		adj[a].push_back({b, wt});
		adj[b].push_back({a, wt});
	}
	priority_queue<pii, vector<pii>, greater<pii>> Q;

	vector<int>vis(n, 0);

	cout << prims_mst(Q, vis , adj) << endl;

}