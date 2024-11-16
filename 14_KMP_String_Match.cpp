#include <bits/stdc++.h>
using namespace std;

void KMP_Recursion(string &text, string &pattern, int i, int j) {
    if (j == pattern.length()) {
        cout << "Pattern found at index " << i - j << endl;
        return;
    }
    if (i == text.length()) return;

    if (text[i] == pattern[j]) {
        KMP_Recursion(text, pattern, i + 1, j + 1);
    } else {
        if (j > 0) {
            KMP_Recursion(text, pattern, i, pattern[j] == text[i] ? j + 1 : 0);
        } else {
            KMP_Recursion(text, pattern, i + 1, 0);
        }
    }
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";
    KMP_Recursion(text, pattern, 0, 0);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int KMP_Memoization(string &text, string &pattern, int i, int j) {
    if (j == pattern.length()) return 1;
    if (i == text.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (text[i] == pattern[j]) {
        return dp[i][j] = KMP_Memoization(text, pattern, i + 1, j + 1);
    } else {
        if (j > 0 && pattern[j] == text[i]) {
            return dp[i][j] = KMP_Memoization(text, pattern, i, j + 1);
        } else {
            return dp[i][j] = KMP_Memoization(text, pattern, i + 1, 0);
        }
    }
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";
    dp.assign(text.length(), vector<int>(pattern.length(), -1));
    cout << "Pattern found: " << KMP_Memoization(text, pattern, 0, 0) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void KMP_BottomUp(string &text, string &pattern) {
    int m = pattern.length();
    int n = text.length();
    vector<int> lps(m, 0);

    // Preprocessing pattern
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }

    // Searching the pattern in text
    i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";
    KMP_BottomUp(text, pattern);
    return 0;
}
