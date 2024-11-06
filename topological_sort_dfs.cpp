#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st, int node) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(adj, vis, st, nbr);
        }
    }
    st.push(node);  // Add node to stack after all its neighbors are processed
}

int main() {
    int n, m,a,b;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;  // Adjacency list using unordered_map and vector

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);  // Directed edge from a to b
    }

    unordered_map<int, bool> vis;  // Visited map

    stack<int> st;
    for (auto x:adj) {
        if (!vis[x.first]) {
            dfs(adj, vis, st, x.first);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
