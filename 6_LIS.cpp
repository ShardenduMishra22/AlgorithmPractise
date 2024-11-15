#include <bits/stdc++.h>
using namespace std;

int lisMemoization(vector<int>& arr, int n, vector<int>& dp) {
    if (dp[n] != -1) {
        return dp[n];
    }

    int maxLength = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[n - 1]) {
            maxLength = max(maxLength, 1 + lisMemoization(arr, i, dp));
        }
    }

    dp[n] = maxLength;
    return dp[n];
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = arr.size();

    // Initialize the DP table with -1
    vector<int> dp(n + 1, -1);

    cout << "Length of Longest Increasing Subsequence: " << lisMemoization(arr, n, dp) << endl;

    return 0;
}
