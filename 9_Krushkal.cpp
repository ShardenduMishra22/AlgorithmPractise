#include <bits/stdc++.h>
using namespace std;

void MakeSet(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int FindParent(vector<int>& parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = FindParent(parent, parent[node]);
}

void Union(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = FindParent(parent, u);
    v = FindParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u] += 1;
    }
}

int Kruskal(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n);
    vector<int> rank(n);

    MakeSet(parent, rank, n);
    int MstWeight = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][1];
        int v = edges[i][2];
        int w = edges[i][0];

        if (FindParent(parent, u) != FindParent(parent, v)) {
            MstWeight += w;
            Union(parent, rank, u, v);
        }
    }
    return MstWeight;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << Kruskal(n, edges) << endl;
    return 0;
}
