#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int>&parent)
{
	if (parent[i] == -1)
		return i;
	return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int>&parent, vector<int>&rank)
{
	int s1 = find(x, parent);
	int s2 = find(y, parent);

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

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
	return v1[2] < v2[2];
}
int kruskal_algo(vector<vector<int>>&edgelist, int n)
{
	vector<int>parent(n, -1);
	vector<int>rank(n, 1);

	int ans = 0;

	sort(edgelist.begin(), edgelist.end(), sortcol);

	for (auto edge : edgelist)
	{
		int x = edge[0], y = edge[1], wt = edge[2];

		int s1 = find(x, parent);
		int s2 = find(y, parent);
		if (s1 != s2)
		{
			Union(s1, s2, parent, rank);
			ans += wt;
		}
	}
	return ans;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edgelist;

	for (int i = 0; i < m; i++)
	{
		int a, b, wt;
		cin >> a >> b >> wt;
		edgelist.push_back({a, b, wt});
	}

	cout << kruskal_algo(edgelist, n) << endl;

}