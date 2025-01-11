#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)  cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(b[i] + dp[i + 1][1], c[i] + dp[i + 1][2]);
        dp[i][1] = max(a[i] + dp[i + 1][0], c[i] + dp[i + 1][2]);
        dp[i][2] = max(b[i] + dp[i + 1][1], a[i] + dp[i + 1][0]);
    }
    cout << max({ dp[0][1], dp[0][2], dp[0][0] });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}