#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<long long int> dp(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= k && i + j < n; j++)
            dp[i] = min(dp[i], abs(h[i] - h[i + j]) + dp[i + j]);
    }
    cout << dp[0];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}