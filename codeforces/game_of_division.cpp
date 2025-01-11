#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        bool found = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (abs(a[i] - a[j]) % k == 0) found = false;
        }
        if (found) { cout << "YES\n" << i + 1 << "\n"; return; }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
