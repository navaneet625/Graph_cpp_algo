#include<bits/stdc++.h>
using namespace std;

int findminVertex(int *distance, int *vis, int n)
{
	int minVertex = -1;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
			minVertex = i;
	}
	return minVertex;
}
void dijkstra(int ** adj_mat, int n)
{
	int *distance = new int[n];
	int *vis = new int[n];

	for (int i = 0; i < n; i++)
	{
		distance[i] = INT_MAX;
		vis[i] = 0;
	}

	distance[0] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int  minVertex = findminVertex(distance, vis, n);
		vis[minVertex] = 1;
		for (int j = 0; j < n; j++)
		{
			if (adj_mat[minVertex][j] != 0 && !vis[j])
			{
				int dist = distance[minVertex] + adj_mat[minVertex][j];
				if (dist < distance[j])
				{
					distance[j] = dist;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << distance[i] << endl;
	}
	delete [] distance;
	delete [] vis;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int **edges = new int*[n];

	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;

		edges[a][b] = wt;
		edges[b][a] = wt;
	}
	dijkstra(edges, n);

	for (int i = 0; i < n; i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
}