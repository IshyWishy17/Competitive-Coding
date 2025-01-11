#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    if (n <= 2) { cout << n << "\n"; return; }
    if (n <= 4) { cout << "2\n"; return; }
    long long int ans = 2;
    long long int start = 4;
    while (start < n) {
        ans++;
        start = start * 2LL + 2LL;
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
