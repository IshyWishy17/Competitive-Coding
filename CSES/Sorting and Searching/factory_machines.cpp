#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, t;
    cin >> n >> t;
    vector<long long int> k(n);
    for (long long int i = 0; i < n; i++) cin >> k[i];
    long long int l = 1;
    long long int r = t * *min_element(k.begin(), k.end());
    long long int ans = r;
    while (l <= r) {
        long long int mid_time = l + (r - l) / 2;
        long long int num_products = 0;
        for (long long int i = 0; i < n; i++) num_products += mid_time / k[i];
        if (num_products < t) l = mid_time + 1;
        else {
            r = mid_time - 1;
            ans = mid_time;
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