#include <bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int, vector<int>>& adj) {
    unordered_map<int, int> color;  // Map to store the color of each node
    queue<pair<int, int>> Q;

    for (auto& node : adj) {  // Iterate through all nodes in the adjacency map
        int start = node.first;
        if (color.find(start) == color.end()) {  // If the node is unvisited
            Q.push({start, 0});
            color[start] = 0;

            while (!Q.empty()) {
                int node = Q.front().first;
                int c = Q.front().second;
                Q.pop();
                for (auto x : adj[node]) {
                    if (color.find(x) != color.end() && color[x] == c)
                        return false;
                    if (color.find(x) == color.end()) {  // If the neighbor is unvisited
                        color[x] = 1 - c;
                        Q.push({x, 1 - c});
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int m, a, b;
    cin >> m;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(adj)?cout << "Yes\n":cout << "No\n";
    return 0;
}
