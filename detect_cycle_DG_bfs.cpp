#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e; // number of nodes and edges
    cin >> n >> e;
    
    unordered_map<int, vector<int>> adj;
    int a, b;
    
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> inDegree(n, 0);
    
    // Calculate in-degrees of all nodes
    for (auto x : adj) {
        for (auto y : x.second) {
            inDegree[y]++;
        }
    }

    // Initialize queue with all nodes having in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0; // Count of nodes processed in topological sort order
    
    // Perform topological sort
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Process the node
        count++;
        
        for (auto x : adj[node]) {
            inDegree[x]--;
            if (inDegree[x] == 0) {
                q.push(x);
            }
        }
    }

    // If count is not equal to n, there is a cycle
    if (count != n) {
        cout << "Yes\n";  // Cycle detected
    } else {
        cout << "No\n";   // No cycle
    }

    return 0;
}
