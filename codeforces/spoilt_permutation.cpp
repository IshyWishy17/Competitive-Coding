#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0;
    while (i < n && a[i] == i + 1) i++;
    if (i == n) { cout << "0 0\n"; return; }
    int l = i;
    while (i < n && a[i] - a[i + 1] == 1) {
        i++;
    }
    int r = i;
    i++;
    while (i < n && a[i] == i + 1) i++;
    if (i == n) { cout << l + 1 << " " << r + 1 << "\n"; return; }
    cout << "0 0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}
