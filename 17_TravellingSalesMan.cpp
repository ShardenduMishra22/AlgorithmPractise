#include <bits/stdc++.h>
using namespace std;

int tspRecursion(int mask, int pos, vector<vector<int>>& dist, int n) {
    if (mask == (1 << n) - 1) return dist[pos][0];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tspRecursion(mask | (1 << city), city, dist, n);
            ans = min(ans, newAns);
        }
    }
    return ans;
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
    cout << tspRecursion(1, 0, dist, n);
}
