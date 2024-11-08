#include <bits/stdc++.h>
using namespace std;

void Bellman_ford(vector<vector<int>>& Edges, unordered_map<int, int>& Dist, int numNodes){
    // Relax edges numNodes - 1 times
    for (int i = 0; i < numNodes - 1; i++){
        for (auto& x : Edges){
            int a = x[0], b = x[1], wt = x[2];
            if (Dist[a] != INT_MAX && Dist[a] + wt < Dist[b])
                Dist[b] = Dist[a] + wt;
        }
    }

    // Check for negative weight cycles
    for (auto& x : Edges){
        int a = x[0], b = x[1], wt = x[2];
        if (Dist[a] != INT_MAX && Dist[a] + wt < Dist[b]){
            cout << "Negative weight cycle detected in the graph\n";
            exit(0);
        }
    }
}

int main(){
    int m;
    cin >> m;

    vector<vector<int>> Edges;
    unordered_map<int, int> Dist;  // Dynamic distance map
    unordered_set<int> uniqueNodes;
	
    for (int i = 0; i < m; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        Edges.push_back({a, b, wt});
        uniqueNodes.insert(a);
        uniqueNodes.insert(b);

        // Initialize distances for each node as INT_MAX if not already set
        if (Dist.find(a) == Dist.end()) Dist[a] = INT_MAX;
        if (Dist.find(b) == Dist.end()) Dist[b] = INT_MAX;
    }

    int src;
    cin >> src;
    Dist[src] = 0;

    int numNodes = uniqueNodes.size();  // Get the actual number of unique nodes
    Bellman_ford(Edges, Dist, numNodes);

    // Output distances
    for (auto& [node, distance] : Dist){
        if (distance == INT_MAX)
            cout << "Node " << node << ": INF\n";
        else
            cout << "Node " << node << ": " << distance << "\n";
    }
    return 0;
}
