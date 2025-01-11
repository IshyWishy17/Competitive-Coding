#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, a, b, c;
    cin >> n >> a >> b >> c;
    long long int ans = (n / (a + b + c)) * 3;
    long long int d = (n / (a + b + c)) * (a + b + c);
    if (d >= n) {
        cout << ans << "\n";
        return;
    }
    ans += 1;
    d += a;
    if (d >= n) {
        cout << ans << "\n";
        return;
    }
    ans += 1;
    d += b;
    if (d >= n) {
        cout << ans << "\n";
        return;
    }
    ans += 1;
    d += c;
    if (d >= n) {
        cout << ans << "\n";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
