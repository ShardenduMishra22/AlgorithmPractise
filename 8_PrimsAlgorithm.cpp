#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> CalcPrims(int n, int m, vector<pair<pair<int, int>, int>>& vec) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++) {
        int u = vec[i].first.first;
        int v = vec[i].first.second;
        int w = vec[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!mst[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mst[u] = true;

        for (auto neighbour : adj[u]) {
            int v = neighbour.first;
            int weight = neighbour.second;

            if (!mst[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 1; i < n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {
    int n = 5; // Number of vertices
    int m = 7; // Number of edges
    vector<pair<pair<int, int>, int>> vec = {
        {{0, 1}, 2}, {{0, 3}, 6}, {{1, 3}, 8}, {{1, 2}, 3}, 
        {{1, 4}, 5}, {{2, 4}, 7}, {{3, 4}, 9}
    };

    vector<pair<pair<int, int>, int>> mst = CalcPrims(n, m, vec);

    for (auto edge : mst) {
        cout << "Edge: (" << edge.first.first << ", " << edge.first.second << "), Weight: " << edge.second << "\n";
    }

    return 0;
}
