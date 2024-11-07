#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;

int main() {
    int n, m, a, b, wt;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);  // Adjacency list

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        // If it's an undirected graph, add this:
        // adj[b].push_back({a, wt});
    }

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> vis(n, false);

    int src;
    cin >> src;

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        // Find the unvisited node with the smallest distance
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        // If there are no reachable nodes left, break
        if (dist[v] == INF)
            break;

        vis[v] = true;

        // Update distances to neighboring nodes
        for (auto e : adj[v]) {
            int u = e.first;
            int weight = e.second;
            if (dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                parent[u] = v;
            }
        }
    }

    // Output the distances from the source
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }

    int t;
    cin>>t;

    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    
    return 0;
}