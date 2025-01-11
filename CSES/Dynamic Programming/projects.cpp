#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<long long int, long long int>, long long int>> intervals(n);
    for (int i = 0; i < n; i++) cin >> intervals[i].first.first >> intervals[i].first.second >> intervals[i].second;
    vector<long long int> dp(n + 1);
    sort(intervals.begin(), intervals.end());
    for (int i = n - 1; i >= 0; i--) {
        long long int r = intervals[i].first.second;
        pair<pair<long long int, long long int>, long long int> search = make_pair(make_pair(r, INT_MAX), INT_MAX);
        int next_idx = upper_bound(intervals.begin(), intervals.end(), search) - intervals.begin();
        dp[i] = max(dp[i + 1], intervals[i].second + dp[next_idx]);
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