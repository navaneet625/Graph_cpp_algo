#include<bits/stdc++.h>
using namespace std;

void Bellman_ford(vector<vector<int>>&Edges, vector<int>&Dist, int n)
{
	//relax Edges n-1 times
	for (int i = 0; i < n - 1; i++)
	{
		for (auto x : Edges)
		{
			int a = x[0], b = x[1], wt = x[2];
			if (Dist[a] != INT_MAX && Dist[a] + wt < Dist[b])
				Dist[b] = Dist[a] + wt;
		}
	}
	for (auto x : Edges)
	{
		int a = x[0], b = x[1], wt = x[2];
		if (Dist[a] != INT_MAX && Dist[a] + wt < Dist[b])
		{
			cout << "Negative wt cycle are there in the graph \n";
			exit(0);
		}
	}

}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> Edges;

	for (int i = 0; i < m; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;
		Edges.push_back({a, b, wt});
	}
	vector<int> Dist(n + 1, INT_MAX);
	int src;
	cin >> src;
	Dist[src] = 0;
	Bellman_ford(Edges, Dist, n);

	for (auto x : Dist)
		cout << x << " ";
	return 0;
}