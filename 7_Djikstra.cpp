#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<vector<int>>& vec, int vrt, int edgs, int src) {
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edgs; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(vrt, INT_MAX);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src}); // Pair format: {distance, node}

    while (!s.empty()) {
        auto p = *(s.begin());
        int nodeDist = p.first; // Distance comes first
        int node = p.second;    // Node comes second

        s.erase(s.begin());

        for (auto neighbour : adj[node]) {
            int v = neighbour.first; // Neighboring node
            int weight = neighbour.second; // Weight of the edge between 'node' and 'v'

            // If a shorter path to 'v' is found through 'node'
            if (nodeDist + weight < dist[v]) {
                // Find and erase the outdated distance of 'v' from the set, if it exists
                auto it = s.find({dist[v], v}); 
                if (it != s.end()) {
                    s.erase(it); // Remove the outdated pair {dist[v], v}
                }

                // Update the distance to 'v' and insert the new pair into the set
                dist[v] = nodeDist + weight;
                s.insert({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> vec = {
        {0, 0, 0}, {0, 1, 7}, {0, 2, 1}, {1, 0, 7}, {1, 3, 5},
        {1, 4, 1}, {1, 2, 3}, {2, 1, 3}, {2, 0, 1}, {4, 3, 7},
        {4, 1, 1}, {3, 0, 2}, {3, 1, 5}, {3, 4, 7}
    };

    int vrt = 5; // Number of vertices (adjusted for your input)
    int edgs = vec.size(); // Total number of edges
    int src = 0; // Source vertex

    vector<int> result = Dijkstra(vec, vrt, edgs, src);
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == INT_MAX)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << result[i] << "\n";
    }

    return 0;
}
