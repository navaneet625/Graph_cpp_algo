#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *distance, int *vis, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void dijkstra(int **adj_mat, int n) {
    int *distance = new int[n];
    int *vis = new int[n];

    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        vis[i] = 0;
    }

    distance[0] = 0;  // Starting node (0) distance is 0

    for (int i = 0; i < n - 1; i++) {
        int minVertex = findMinVertex(distance, vis, n);
        vis[minVertex] = 1;

        // Update distances of adjacent vertices
        for (int j = 0; j < n; j++) {
            if (adj_mat[minVertex][j] != 0 && !vis[j]) {  // Check for edge and unvisited node
                int dist = distance[minVertex] + adj_mat[minVertex][j];
                if (dist < distance[j]) {
                    distance[j] = dist;
                }
            }
        }
    }

    // Output the shortest distance from source to each vertex
    for (int i = 0; i < n; i++) {
        cout << "Distance from 0 to " << i << " is " << distance[i] << endl;
    }

    delete[] distance;
    delete[] vis;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Dynamically allocate adjacency matrix
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n]();
    }

    // Read edges and populate adjacency matrix
    for (int i = 0; i < m; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges[a][b] = wt;
        edges[b][a] = wt;  // Assuming undirected graph
    }

    // Run Dijkstra's algorithm
    dijkstra(edges, n);

    // Deallocate memory for adjacency matrix
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
