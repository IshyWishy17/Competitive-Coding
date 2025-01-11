#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s, t;
    cin >> s;
    cin >> t;
    int m = s.length(), n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m) {
                dp[m][j] = n - j;
                continue;
            }
            if (j == n) {
                dp[i][n] = m - i;
                continue;
            }
            if (s[i] == t[j]) {
                dp[i][j] = dp[i + 1][j + 1];
                continue;
            }
            dp[i][j] = 1 + min({ dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1] });
        }
    }
    cout << dp[0][0];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}