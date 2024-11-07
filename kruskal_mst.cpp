#include <bits/stdc++.h>
using namespace std;

int find_set(int a, vector<int>& parent) {
    if (parent[a] == -1)
        return a;
    return parent[a] = find_set(parent[a], parent);  // Path compression
}

void union_set(int s1, int s2, vector<int>& parent, vector<int>& rank) {
    if (rank[s1] < rank[s2]) {
        rank[s2] += rank[s1];
        parent[s1] = s2;
    } else {
        rank[s1] += rank[s2];
        parent[s2] = s1;
    }
}

bool com(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];
}

void MST(vector<vector<int>>& edges, int n, int& ans) {
    vector<int> parent(n, -1);
    vector<int> rank(n, 1);

    sort(edges.begin(), edges.end(), com);

    for (auto x : edges) {
        int s1 = find_set(x[0], parent);
        int s2 = find_set(x[1], parent);

        if (s1 != s2) {
            union_set(s1, s2, parent, rank);
            ans += x[2];
        }
    }
}

int main() {
    int n, m, a, b, wt;

    cin >> n >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        edges.push_back({a, b, wt});
    }

    int ans = 0;
    MST(edges, n, ans);

    cout << "Weight of Minimum Spanning Tree: " << ans << endl;
    return 0;
}
