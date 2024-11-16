#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Bellman-Ford Algorithm
bool BellmanFord(int n, vector<vector<int>>& edges, int src, vector<int>& dist) {
    dist[src] = 0;

    // Relax all edges (n-1) times
    for (int i = 1; i < n; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return false;  // Negative weight cycle found
        }
    }

    return true;
}

int main() {
    // Number of vertices and edges
    int n = 5, e = 8;
    
    // Edges represented as (u, v, weight)
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    vector<int> dist(n, INF);

    int source = 0;

    if (BellmanFord(n, edges, source, dist)) {
        // Print shortest distances from the source
        cout << "Shortest distances from source vertex " << source << " are:" << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
