#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i].first = t;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (a[l].first + a[r].first == x) {
            cout << a[l].second << " " << a[r].second;
            return;
        } else if (a[l].first + a[r].first > x) r--;
        else l++;
    }
    cout << "IMPOSSIBLE";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}