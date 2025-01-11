#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    // dp[i][x] = max(s[i] + dp[i - 1][x - h[i]], dp[i - 1][x])
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int j = 0; j <= x; j++) {
        if (j >= h[0]) dp[0][j] = s[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i] >= 0) dp[i][j] = max(dp[i][j], s[i] + dp[i - 1][j - h[i]]);
        }
    }   
    cout << dp[n - 1][x];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}