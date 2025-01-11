#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, a;
    cin >> n >> a;
    vector<long long int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    if (n == 1) { cout << 0 << "\n"; return; }
    if (a <= x[0]) { cout << abs(x[n - 2] - a) << "\n"; return; }
    if (a >= x[n - 1]) { cout << abs(a - x[1]) << "\n"; return; }
    long long int ans = min({ abs(x[n - 1] - a) + abs(x[n - 1] - x[1]), abs(a - x[1]) + abs(x[n - 1] - x[1]),
                            abs(x[n - 2] - a) + abs(x[n - 2] - x[0]), abs(a - x[0]) + abs(x[n - 2] - x[0]) });
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
