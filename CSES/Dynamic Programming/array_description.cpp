#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (x[i] != 0) {
                if (abs(j - x[i]) <= 1) dp[i][j] = dp[i + 1][x[i]];
                else dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i + 1][j];
            if (j - 1 >= 1) (dp[i][j] += dp[i + 1][j - 1]) %= MOD;
            if (j + 1 <= m) (dp[i][j] += dp[i + 1][j + 1]) %= MOD;
        }
    }
    if (x[0] == 0) {
        int s = 0;
        for (int i = 1; i <= m; i++) {
            (s += dp[1][i]) %= MOD;
        }
        cout << s;
    }
    else cout << dp[1][x[0]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
