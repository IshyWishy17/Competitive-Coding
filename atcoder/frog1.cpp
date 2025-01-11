#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> dp(n, 0);
    dp[n - 2] = abs(h[n - 1] - h[n - 2]);
    for (int i = n - 3; i >= 0; i--)
        dp[i] = min(dp[i + 1] + abs(h[i] - h[i + 1]), dp[i + 2] + abs(h[i] - h[i + 2]));
    cout << dp[0];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}