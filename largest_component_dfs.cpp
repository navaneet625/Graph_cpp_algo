#include <bits/stdc++.h>
using namespace std ;

int dfs_visit(vector<vector<int>>& adj, vector<bool>& visited, int node)
{
    int node_cnt = 1 ;
    visited[node] = true ;
    for (int neighbor : adj[node])
    {
        if (visited[neighbor])
            continue ;
        node_cnt += dfs_visit(adj, visited, neighbor);
    }
    return node_cnt ;
}

int main()
{
    int n, m ;
    cin >> n >> m ;

    vector<vector<int>> adj(n + 1) ;
    for (int i = 0 ; i < m; ++i)
    {
        int src, dst ;
        cin >> src >> dst ;
        adj[src].push_back(dst) ;
        adj[dst].push_back(src) ;
    }

    int largest_component = 0 ;
    vector<bool> visited(n + 1, false) ;

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])
            continue ;
        int component_size = dfs_visit(adj, visited, i);
        largest_component = max(largest_component, component_size) ;
    }

    cout << largest_component << '\n' ;
}