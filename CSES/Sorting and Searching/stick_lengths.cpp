#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int target = n % 2 == 0 ? p[n / 2] : p[(n - 1) / 2];
    long long int ans = 0;
    for (int i = 0; i < n; i++) ans+= abs(p[i] - target);
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}