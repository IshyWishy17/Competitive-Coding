#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool check(long double r, vector<long long int> x, long long int n) {
    long double init = (x[n - 1] + x[0]) / 2;
    long long int start = lower_bound(x.begin(), x.end(), init) - x.begin();
    
}

void solve() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    long long int n;
    vector<long long int> x(n);
    for (long long int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    long double l = 0;
    long double r = (x[n - 1] + x[0]) / 2;
    long double ans = (x[n - 1] + x[0]) / 2;
    while (l <= r) {
        long double mid = (l + r) / 2;
        if (check(mid, x, n)) { ans = mid; r = mid - 0.5; }
        else l = mid + 0.5;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
