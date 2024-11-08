#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, int>& vis, int node, int color) {
    vis[node] = color;
    for (auto nbr : adj[node]) {
        if (vis.find(nbr) == vis.end()) {  // If the neighbor is unvisited
            if (!dfs(adj, vis, nbr, 3 - color))  // Alternate color
                return false;
        } else if (color == vis[nbr]) {  // Check for the same color in neighbors
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    unordered_map<int, vector<int>> adj;  // Graph using unordered_map

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_map<int, int> vis;  // Visited map with colors
    bool isBipartite = true;
    for (auto& node : adj) {  // Iterate over all nodes in the adjacency map
        if (vis.find(node.first) == vis.end()) {  // If the node is unvisited
            if (!dfs(adj, vis, node.first, 1)) {
                isBipartite = false;
                break;
            }
        }
    }

    isBipartite?cout << "Yes\n ":cout << "No\n" << endl;
    return 0;
}
