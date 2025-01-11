#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    int V = 0;
    for (int val : v) V += val;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(V + 1, INT_MAX));
    int ans = 0;
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= V; j++) {
            if (j == 0) {
                dp[i][0] = 0;
                continue;
            }
            dp[i][j] = dp[i + 1][j];
            dp[i][j] = min(dp[i][j], w[i] + dp[i + 1][max(0, j - v[i])]);
            if (dp[i][j] <= W) ans = max(ans, j);
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}