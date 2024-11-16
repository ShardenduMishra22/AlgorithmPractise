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

#include <bits/stdc++.h>
using namespace std;

int tspMemo(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1) return dist[pos][0];

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tspMemo(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns);
        }
    }
    
    return dp[mask][pos] = ans;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 5},
        {20, 25, 30, 0, 40},
        {25, 30, 5, 40, 0}
    };
    
    int n = 5;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << tspMemo(1, 0, dist, dp, n);
}
