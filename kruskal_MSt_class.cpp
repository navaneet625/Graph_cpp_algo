#include<bits/stdc++.h>
using namespace std;

class DSU {
	int *parent;
	int *rank;

public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int findSet(int i)
	{
		if (parent[i] == -1)
			return i;
		return parent[i] = findSet(parent[i]);
	}

	void Union(int x, int y)
	{
		int s1 = findSet(x);
		int s2  = findSet(y);

		if (s1 != s2)
		{
			if (rank[s1] < rank[s2])
			{
				rank[s2] += rank[s1];
				parent[s1] = s2;
			}
			else
			{
				rank[s1] += rank[s2];
				parent[s2] = s1;
			}
		}
	}
};

class Graph {

	vector<vector<int>> edgelist;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y});
	}

	int kruskal_mst() {
		sort(edgelist.begin(), edgelist.end());

		int ans = 0;
		DSU s(V);
		for (auto edge : edgelist) {
			int w = edge[0], x = edge[1], y = edge[2];

			if (s.findSet(x) != s.findSet(y)) {
				s.Union(x, y);
				ans += w;
			}
		}
		return ans;
	}

};

int main()
{
	Graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);

	cout << g.kruskal_mst() << endl;
	return 0;
}