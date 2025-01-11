#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long int x, y;
    cin >> n >> x >> y;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long int S = 0;
    for (int i = 0; i < n; i++) S += a[i];
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx_1 = upper_bound(a.begin() + (i + 1), a.end(), S - x - a[i]) - a.begin();
        int idx_2 = lower_bound(a.begin() + (i + 1), a.end(), S - y - a[i]) - a.begin();
        ans += max(0, min(idx_1 - 1, n - 1) - max(i + 1, idx_2) + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
