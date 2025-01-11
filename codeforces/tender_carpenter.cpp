#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < 2 * a[i] && a[i + 1] > a[i]) flag = true;
        if (a[i] < 2 * a[i + 1] && a[i] > a[i + 1]) flag = true;
        if (a[i] == a[i + 1]) flag = true;
    }
    if (!flag) cout << "NO\n";
    else cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}