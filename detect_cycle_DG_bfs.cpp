#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>>adj(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<int>inDegree(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (auto x : adj[i])
			inDegree[x]++;
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	int count = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		// cout<<node<<"<<";
		for (auto x : adj[node])
		{
			inDegree[x]--;
			if (inDegree[x] == 0)
				q.push(x);
		}
		count++;
	}
	cout << count << endl;
	(count != n) ? cout << "Yes \n" : cout << "No \n";
}