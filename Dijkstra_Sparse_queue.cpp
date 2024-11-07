#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;

int main() {
    int n, m, a, b, wt;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        // adj[b].push_back({a, wt});  // For undirected graph
    }

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src;
    cin >> src;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int v = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist != dist[v])
            continue;

        for (auto x : adj[v]) {
            int u = x.first;
            int edgeWeight = x.second;

            if (dist[v] + edgeWeight < dist[u]) {
                dist[u] = dist[v] + edgeWeight;
                parent[u] = v;
                pq.push({dist[u], u});
            }
        }
    }

    // Output the shortest distances from the source
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}