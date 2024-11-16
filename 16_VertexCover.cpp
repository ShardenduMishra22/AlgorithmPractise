#include <bits/stdc++.h>
using namespace std;

int vertexCoverRec(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    int cover = 1;  // include this vertex

    for (int v : adj[u]) {
        if (!visited[v]) {
            cover += vertexCoverRec(v, adj, visited);
        }
    }
    return cover;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(4);
    
    vector<bool> visited(n, false);
    cout << vertexCoverRec(0, adj, visited);
}
