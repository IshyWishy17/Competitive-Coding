#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int na, nb, nc;
    string a, b, c;
    cin >> a >> b >> c;
    na = a.length();
    nb = b.length();
    nc = c.length();
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    for (int i = na; i >= 0; i--) {
        for (int j = nb; j >= 0; j--) {
            if (i + j >= nc) continue;
            if (i == na) dp[i][j] = dp[i][j + 1] + ((b[j] == c[i + j]) ? 0 : 1);
            else if (j == nb) dp[i][j] = dp[i + 1][j] + ((a[i] == c[i + j]) ? 0 : 1);
            else dp[i][j] = min(dp[i + 1][j] + ((a[i] == c[i + j]) ? 0 : 1), dp[i][j + 1] + ((b[j] == c[i + j]) ? 0 : 1));
        }
    }
    cout << dp[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
