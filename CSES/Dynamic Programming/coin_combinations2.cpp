#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> dp(n, vector<int>(x + 1, 1));
    for (int j = 0; j <= x; j++)
        if (j % c[n - 1] != 0)
            dp[n - 1][j] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j - c[i] >= 0) (dp[i][j] += dp[i][j - c[i]]) %= MOD;
        }
    }

    cout << dp[0][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
