#include <bits/stdc++.h>
using namespace std;

int INF = INT_MAX;

void FloydWarshall(vector<vector<int>>& graph, int n) {
    // Create a distance matrix from the graph
    vector<vector<int>> dist = graph;

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if the new path through 'k' is shorter
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Hardcoded graph with 4 vertices
    int n = 4;
    vector<vector<int>> graph(n, vector<int>(n, INF));

    // Distance from a vertex to itself is 0
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    // Hardcoded edges (u, v, w) where u and v are vertices and w is the weight
    graph[0][1] = 3;  // Edge from vertex 0 to vertex 1 with weight 3
    graph[0][2] = 5;  // Edge from vertex 0 to vertex 2 with weight 5
    graph[1][2] = 1;  // Edge from vertex 1 to vertex 2 with weight 1
    graph[1][3] = 7;  // Edge from vertex 1 to vertex 3 with weight 7
    graph[2][3] = 2;  // Edge from vertex 2 to vertex 3 with weight 2

    FloydWarshall(graph, n);

    return 0;
}