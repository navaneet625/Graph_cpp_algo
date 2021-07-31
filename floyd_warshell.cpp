#include<bits/stdc++.h>
using namespace std;

vector < vector<int>> floyd_warshell(vector<vector<int>>graph)
{
	vector<vector<int>>dist(graph);
	int n = graph.size();
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j] && (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return dist;
}

int main()
{
	vector<vector<int>> graph = {
		{0, INT_MAX, -2, INT_MAX},
		{4, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 2},
		{INT_MAX, -1, INT_MAX, 0}
	};

	auto dist = floyd_warshell(graph);
	int n = dist.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}