#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, odd = 0, even = 0;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if (even >= odd) cout << odd << "\n";
    else cout << even + (odd - even) / 3 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
