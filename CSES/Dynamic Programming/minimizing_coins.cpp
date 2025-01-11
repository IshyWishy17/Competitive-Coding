#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(x + 1, 0);
    for (int i = 1; i <= x; i++) {
        dp[i] = x + 10;
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - c[j]]);
            }
        }
    }
    cout << (dp[x] <= x ? dp[x] : -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
