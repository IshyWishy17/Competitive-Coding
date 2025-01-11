#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    int n;
    long long int h;
    cin >> n >> h;
    vector<long long int> heights(n);
    vector<long long int> weights(n);
    vector<long long int> strengths(n);
    for (int i = 0; i < n; i++) cin >> heights[i] >> weights[i] >> strengths[i];
    vector<pair<long long int, long long int>> dp(1 << n, make_pair(-1, -1));
    dp[0] = make_pair(0, INT_MAX);
    long long int ans = -1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                pair<long long int, long long int> prev = dp[mask ^ (1 << i)];
                dp[mask].first = prev.first + heights[i];
                if (prev.first == 0) {
                    dp[mask].second = strengths[i];
                    continue;
                }
                dp[mask].second = max(dp[mask].second, max(-1LL, min(prev.second - weights[i], strengths[i])));
            }
        }
        if (dp[mask].first >= h) ans = max(ans, dp[mask].second);
    }
    if (ans == -1) cout << "Mark is too tall";
    else cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}