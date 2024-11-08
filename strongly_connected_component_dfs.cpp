#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis, int node, vector<int>& st) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(adj, vis, nbr, st);
        }
    }
    st.push_back(node);
}

void dfs_(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis, int node) {
    vis[node] = true;
    cout << node << " ";
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs_(adj, vis, nbr);
        }
    }
}

int main() {
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj, rev_adj;
    cout << "Enter each edge as: node1 node2\n";
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    unordered_map<int, bool> vis;
    vector<int> st;  // Stack for storing the finishing order of nodes

    // Perform DFS for the original graph to get finishing times
    for (auto& [node, _] : adj) {
        if (!vis[node]) {
            dfs(adj, vis, node, st);
        }
    }
    // Reset visited map for the reverse DFS
    vis.clear();
    // Perform DFS on the reversed graph in the order of the finishing times
    char comp_name = 'A';
    for (int i = st.size() - 1; i >= 0; i--) {
        int node = st[i];
        if (!vis[node]) {
            cout << "Component " << comp_name << " --> ";
            dfs_(rev_adj, vis, node);
            cout << endl;
            comp_name++;
        }
    }
    return 0;
}
