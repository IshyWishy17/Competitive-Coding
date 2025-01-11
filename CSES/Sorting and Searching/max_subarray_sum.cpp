#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    long long int start = x[0];
    long long int ans = x[0];
    for (int i = 1; i < n; i++) {
        start = max(start + x[i], x[i]);
        ans = max(ans, start);
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}