#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1e9 + 7;

void solve() {
    long long int n;
    cin >> n;
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    // dp[i] = dp[i - 1] + .. + dp[i - 6]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++)
            dp[i] += dp[i - j] % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
