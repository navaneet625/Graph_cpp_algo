#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n_nodes, n_edges;
	cin >> n_nodes >> n_edges;
	vector<vector<int>> adj(n_nodes + 1);
	for (int i = 0; i < n_edges; i++)
	{
		int src, dst;
		cin >> src >> dst;
		adj[src].push_back(dst);
		//adj[b].push_back(a)//if graph is undirected
	}
	queue<int> Q;
	vector<bool> visited(n_nodes + 1, false);
	int source = 1;
	visited[source] = true;

	Q.push(source);
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		cout << node << " ";
		for (int neighbour : adj[node])
		{
			if (visited[neighbour])
				continue;
			visited[neighbour] = true;
			Q.push(neighbour);
		}
	}
	return 0;
}