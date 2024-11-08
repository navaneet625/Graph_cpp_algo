#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>>& adj, int src, int& ans) {
    unordered_map<int, int> dist;  // Distance map for each node
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for (auto nbr : adj[node]) {
            if (dist.find(nbr) == dist.end()) {  // Not visited
                Q.push(nbr);
                dist[nbr] = dist[node] + 1;
            }
            // Detecting a cycle through a back edge
            else if (dist[nbr] >= dist[node]) {
                ans = min(ans, dist[nbr] + dist[node] + 1);
            }
        }
    }
}

int main() {
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;
    cout << "Enter each edge as: source destination\n";
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = INT_MAX;
    unordered_set<int> visited_nodes;  // Set to track nodes we start BFS from
    for (const auto& pair : adj) {
        int node = pair.first;
        if (visited_nodes.find(node) == visited_nodes.end()) {
            visited_nodes.insert(node);
            bfs(adj, node, ans);
        }
    }

    if (ans == INT_MAX)
        cout << "Cycle not present in the given graph.\n";
    else
        cout << "Shortest Cycle length is: " << ans << "\n";
    return 0;
}
