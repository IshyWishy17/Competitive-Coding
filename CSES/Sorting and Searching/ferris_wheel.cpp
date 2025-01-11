#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int ans = 0, l = 0, r = n - 1;
    while (l < r) {
        if (p[l] + p[r] <= x) { ans++; l++; r--; }
        else { ans++; r--; }
    }
    if (l == r) ans++;
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}