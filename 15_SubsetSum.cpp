#include <bits/stdc++.h>
using namespace std;

bool SubsetSum_Recursion(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (arr[n-1] > sum) return SubsetSum_Recursion(arr, n-1, sum);
    return SubsetSum_Recursion(arr, n-1, sum) || SubsetSum_Recursion(arr, n-1, sum - arr[n-1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << SubsetSum_Recursion(arr, arr.size(), sum) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool SubsetSum_Memoization(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (dp[n][sum] != -1) return dp[n][sum];

    if (arr[n-1] > sum) return dp[n][sum] = SubsetSum_Memoization(arr, n-1, sum);
    return dp[n][sum] = SubsetSum_Memoization(arr, n-1, sum) || SubsetSum_Memoization(arr, n-1, sum - arr[n-1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    dp.assign(arr.size()+1, vector<int>(sum+1, -1));
    cout << SubsetSum_Memoization(arr, arr.size(), sum) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool SubsetSum_BottomUp(vector<int>& arr, int n, int sum) {
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << SubsetSum_BottomUp(arr, arr.size(), sum) << endl;
    return 0;
}

