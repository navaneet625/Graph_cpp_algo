#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, source,a,b;
    cout << "Enter the number of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;
    cout << "Enter each edge as: node1 node2\n";
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the source node: ";
    cin >> source;

    unordered_map<int, int> vis;  // Distance from the source
    queue<int> Q;

    vis[source] = 0;  // Distance of source to itself is 0
    Q.push(source);

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (auto x : adj[node]) {
            if (vis.find(x) != vis.end())  // If already visited, skip
                continue;
            vis[x] = vis[node] + 1;
            Q.push(x);
        }
    }

    // Output distances from the source node
    cout << "Node distances from source:\n";
    for (const auto &pair : vis) {
        cout << "Node " << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
