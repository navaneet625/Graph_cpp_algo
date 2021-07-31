#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> board(50, 0);
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	vector<vector<int>>adj(37);
	for (int u = 0; u <= 36; u++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int v = u + dice;
			v += board[v];
			if (v <= 36)
				adj[u].push_back(v);
		}
	}
	adj[36].push_back(36);
	queue<int> q;
	q.push(0);
	vector<int>vis(37, INT_MAX);
	vis[0] = 0;
	unordered_map<int, int> mp;
	mp[0] = 0;
	while (!q.empty())
	{
		int node = q.front();
		// cout << node << " ";
		q.pop();
		for (auto v : adj[node])
		{
			if (vis[v] == INT_MAX)
			{
				vis[v] = vis[node] + 1;
				q.push(v);
				mp[v] = node;
			}
		}
	}
	int temp = 36, src = 0;
	while (temp != src)
	{
		cout << temp << "<--";
		temp = mp[temp];
	}
	cout << src << endl << vis[36] << endl;

}