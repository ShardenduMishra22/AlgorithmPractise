#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adj(n); // Adjacency list

    // Adding edges (example)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    vector<bool> visited(n, false);
    DFS(0, adj, visited);  // Starting DFS from node 0

    return 0;
}
