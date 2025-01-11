#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    vector<long long int> temps(n);
    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }
    vector<int> pos_before(n);
    pos_before[0] = temps[0] >= 0 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        pos_before[i] = pos_before[i - 1] + (temps[i] >= 0 ? 1 : 0);
    }
    vector<int> negs_after(n);
    negs_after[n - 1] = temps[n - 1] <= 0 ? 1 : 0;
    for (int i = n - 2; i >= 0; i--) {
        negs_after[i] = negs_after[i + 1] + (temps[i] <= 0 ? 1 : 0);
    }
    int ans = n + 1;
    for (int i = 1; i < n; i++) {
        ans = min(ans, pos_before[i - 1] + negs_after[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}
