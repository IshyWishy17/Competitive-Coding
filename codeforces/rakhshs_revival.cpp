#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, m, k;
    string s;
    cin >> n >> m >> k;
    cin >> s;
    long long int ans = 0;
    long long int i = 0;
    while (i < n) {
        long long int count = 0;
        while (i < n && s[i] == '0' && count < m) { i++; count++; }
        if (count == m) {
            ans++;
            i+= k - 1;
        } else i++;
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
