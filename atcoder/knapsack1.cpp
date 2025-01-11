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
    vector<vector<long long int>> dp(n + 1, vector<long long int>(W + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], v[i] + dp[i + 1][j - w[i]]);
        }
    }
    cout << dp[0][W];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}