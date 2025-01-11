#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> match(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> match[i][j];
            
    vector<int> dp1(1 << n, 1);
    vector<int> dp2(1 << n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp1[mask] = 0;
            if (__builtin_popcount(mask) < n - i) continue;
            for (int j = 0; j < n; j++)
                if (match[i][j] && (mask & (1 << j)))
                    (dp1[mask] += dp2[mask ^ (1 << j)]) %= MOD;
        }
        dp2 = dp1;
    }
    cout << dp1[(1 << n) - 1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}