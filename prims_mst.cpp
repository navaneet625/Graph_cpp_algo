#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int prims_mst(priority_queue<pii, vector<pii>, greater<pii>>& Q, unordered_map<int, int>& vis, unordered_map<int, vector<pii>>& adj) {
    int ans = 0;
    // Start from an arbitrary node (assumes at least one node is present in `adj`)
    int start = adj.begin()->first;
    Q.push({0, start});

    while (!Q.empty()) {
        auto node = Q.top();
        Q.pop();
        int v = node.second;
        int wt = node.first;

        if (vis[v])
            continue;
        ans += wt;
        vis[v] = 1;

        for (auto x : adj[v]) {
            if (vis[x.first] == 0)
                Q.push({x.second, x.first});
        }
    }
    return ans;
}

int main() {
    int m, a, b, wt;
    cout << "Enter the number of edges: ";
    cin >> m;

    unordered_map<int, vector<pair<int, int>>> adj;
    cout << "Enter edges (vertex1 vertex2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;

        // Populate the adjacency list for a dynamic number of vertices
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    priority_queue<pii, vector<pii>, greater<pii>> Q;
    unordered_map<int, int> vis;

    cout << "Weight of Minimum Spanning Tree: " << prims_mst(Q, vis, adj) << endl;
    return 0;
}
