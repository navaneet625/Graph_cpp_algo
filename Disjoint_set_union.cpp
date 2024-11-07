#include <bits/stdc++.h>
using namespace std;

int findSet(int a, vector<int>& parent) {
    if (parent[a] == -1)
        return a;
    return parent[a] = findSet(parent[a], parent);  // Path compression
}

void union_set(int s1, int s2, vector<int>& parent, vector<int>& rank) {
    if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
        rank[s2] += rank[s1];
    } else {
        parent[s2] = s1;
        rank[s1] += rank[s2];
    }
}

bool contain_cycle(vector<pair<int, int>>& adj, int n) {
    vector<int> parent(n, -1), rank(n, 1);

    for (auto& edge : adj) {
        int a = edge.first;
        int b = edge.second;
        int s1 = findSet(a, parent);
        int s2 = findSet(b, parent);

        if (s1 == s2)
            return true;  // Cycle detected
        else
            union_set(s1, s2, parent, rank);
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj.push_back({a, b});
    }

    bool ans = contain_cycle(adj, n);

    if (ans)
        cout << "Cyclic graph" << endl;
    else
        cout << "Acyclic graph" << endl;

    return 0;
}
