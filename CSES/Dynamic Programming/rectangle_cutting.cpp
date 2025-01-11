#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) { dp[i][j] = 0; continue; }
            for (int a = 1; a < i; a++) {
                dp[i][j] = min(dp[i][j], 1 + dp[a][j] + dp[i - a][j]);
            }
            for (int b = 1; b < j; b++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][b] + dp[i][j - b]);
            }
        }
    }
    cout << dp[a][b];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}