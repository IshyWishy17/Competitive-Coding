#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, x;
    cin >> n >> x;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<long long, int> prefix_sums;
    prefix_sums[0]++;
    long long int ans = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += prefix_sums[sum - x];
        prefix_sums[sum]++;
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