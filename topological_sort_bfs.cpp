#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m,a,b;
    cin >> n >> m;
    unordered_map<int, vector<int>> adj;  // Adjacency list using unordered_map and vector

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);  // Add directed edge from node a to node b
    }

    unordered_map<int, int> indegree;  // In-degree map

    // Calculate in-degrees of all nodes
    for (const auto& node : adj) {
        for (int neighbor : node.second) {
            indegree[neighbor]++;
        }
    }

    queue<int> Q;
    // Initialize queue with nodes having in-degree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    // Perform topological sort
    while (!Q.empty()) {
        int node = Q.front();
        cout << node << " ";
        Q.pop();

        for (auto x : adj[node]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                Q.push(x);
            }
        }
    }
    cout << endl;
    return 0;
}
