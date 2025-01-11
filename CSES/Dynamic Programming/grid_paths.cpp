 #include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    if (grid[0][0] == '.') dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;
            if (j > 0) (dp[i][j] += dp[i][j - 1]) %= MOD;
            if (i > 0) (dp[i][j] += dp[i - 1][j]) %= MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
