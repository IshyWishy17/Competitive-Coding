#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    vector<int> q(k);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> q[i];
    set<int> knows;
    for (int i = 0; i < k; i++) knows.insert(q[i]);
    for (int i = 0; i < m; i++) {
        bool flag = false;
        if (knows.find(a[i]) != knows.end()) {
            knows.erase(a[i]);
            flag = true;
        }
        if (knows.size() < n - 1) cout << "0";
        else cout << "1";
        if (flag) knows.insert(a[i]);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
