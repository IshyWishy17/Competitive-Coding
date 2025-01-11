#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        times[i].first = t;
        times[i].second = s;
    }
    sort(times.begin(), times.end());
    int ans = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (times[i].second >= end) { ans++; end = times[i].first; }
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}