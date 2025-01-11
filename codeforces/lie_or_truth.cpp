#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    vector<long long int> a(n);
    vector<long long int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (i >= l && i <= r) continue;
        if (a[i] != b[i]) { cout << "LIE\n"; return; }
    }
    cout << "TRUTH\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
