#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    long long int x;
    cin >> n >> x;
    vector<long long int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<pair<int, long long int>> dp(1 << n);
    dp[0] = make_pair(1, 0);
    for (long long int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = make_pair(n, x);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int rides = dp[mask ^ (1 << i)].first;
                long long int weight = dp[mask ^ (1 << i)].second;
                if (weight + w[i] <= x) dp[mask] = min(dp[mask], make_pair(rides, weight + w[i]));
                else dp[mask] = min(dp[mask], make_pair(rides + 1, w[i]));
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}