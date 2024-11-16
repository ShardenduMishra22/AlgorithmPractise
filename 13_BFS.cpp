#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
    BFS(0, adj, visited);  // Starting BFS from node 0

    return 0;
}
