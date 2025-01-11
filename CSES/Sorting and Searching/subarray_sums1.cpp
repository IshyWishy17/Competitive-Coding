#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, x;
    cin >> n >> x;
    vector<long long int> a(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    int ans = 0;
    long long int sum = a[0];
    while (r < n) {
        if (sum > x) {
            if (l < r) {
                sum -= a[l];
                l++;
            } else {
                l++;
                r++;
                sum = a[l];
            }
        } else if (sum < x) {
            r++;
            sum += a[r];
        } else {
            ans++;
            r++;
            sum += a[r];
        }
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