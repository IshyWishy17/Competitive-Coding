#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) { cout << "0"; return; }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    vector<vector<int>> ans(n + 1, vector<int>(sum + 1, 0));
    dp[n][sum / 2] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int s = 0; s + i < sum; s++) {
            (dp[i][s] = dp[i + 1][s] + dp[i + 1][s + i + 1]) %= MOD;
            (ans[i][s] = (dp[i + 1][s] + dp[i + 1][s + i + 1]) / 2) %= MOD;
        }
    cout << ans[0][0];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}